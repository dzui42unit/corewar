/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozabara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 13:24:07 by ozabara           #+#    #+#             */
/*   Updated: 2017/05/29 16:15:35 by ozabara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_ftemp	*check_fd(int fd, t_ftemp **begin_list)
{
	t_ftemp	*ptr;

	ptr = *begin_list;
	while (ptr && ptr->fd != fd)
		ptr = ptr->next;
	return (ptr);
}

static char		*remove_part_before_endofline(int fd, t_ftemp **begin_list)
{
	t_ftemp		*ptr;
	char		*begin;
	char		*end;
	char		*tempstr;

	ptr = check_fd(fd, begin_list);
	if (ptr == NULL || ptr->temp == NULL)
		return (NULL);
	if ((end = ft_strstr(ptr->temp, "\n")) != NULL)
	{
		begin = ft_strsub(ptr->temp, 0, (ptr->temp_size - ft_strlen(end) - 1));
		end++;
		tempstr = ptr->temp;
		ptr->temp = (ft_strlen(end) == 0) ? NULL : ft_strdup(end);
		ptr->temp_size = ft_strlen(end) + 1;
		free(tempstr);
	}
	else
	{
		begin = ft_strdup(ptr->temp);
		free(ptr->temp);
		ptr->temp = NULL;
		ptr->temp_size = 0;
	}
	return (begin);
}

static int		check_end_of_line(char *buff, int fd, t_ftemp **begin_list)
{
	t_ftemp		*ptr;
	char		*tempstr;

	ptr = check_fd(fd, begin_list);
	if (ptr == NULL)
	{
		if (!(ptr = (t_ftemp *)malloc(sizeof(t_ftemp))))
			return (-1);
		ptr->fd = fd;
		ptr->next = *begin_list;
		ptr->temp = ft_strdup(buff);
		ptr->temp_size = ft_strlen(ptr->temp) + 1;
		*begin_list = ptr;
	}
	else
	{
		tempstr = ft_strjoin(ptr->temp, buff);
		free(ptr->temp);
		ptr->temp = tempstr;
		ptr->temp_size = ft_strlen(ptr->temp) + 1;
	}
	if (ft_strstr(ptr->temp, "\n") != NULL)
		return (1);
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static t_ftemp	*begin_list;
	char			buff[BUFF_SIZE + 1];
	int				size;
	int				flag;

	if (fd < 0 || !line || read(fd, NULL, 0) == -1)
		return (-1);
	while ((size = read(fd, buff, BUFF_SIZE)) != 0)
	{
		buff[size] = '\0';
		flag = check_end_of_line(buff, fd, &begin_list);
		if (flag == 1)
		{
			*line = remove_part_before_endofline(fd, &begin_list);
			return (1);
		}
		if (flag == -1)
			return (-1);
	}
	if ((*line = remove_part_before_endofline(fd, &begin_list)) != NULL)
		return (1);
	return (0);
}
