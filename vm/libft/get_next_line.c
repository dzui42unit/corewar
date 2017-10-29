/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 15:31:22 by dzui              #+#    #+#             */
/*   Updated: 2017/01/11 16:05:05 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	t_list	*ft_correct_fd(t_list **head, size_t fd)
{
	t_list		*node;

	node = *head;
	if (node)
	{
		while (node)
		{
			if (fd == node->content_size)
				return (node);
			node = node->next;
		}
	}
	node = ft_lstnew("\0", 1);
	node->content_size = fd;
	ft_lstadd(head, node);
	return (node);
}

static	char	*ft_strndup(char *sorc, size_t n)
{
	char		*dup;

	if (!(dup = (char *)malloc(sizeof(char) * n + 1)))
		return (NULL);
	dup = ft_strncpy(dup, sorc, n);
	dup[n] = '\0';
	return (dup);
}

static	char	*ft_strnjoin(char const *s1, char const *s2, size_t len)
{
	char		*s3;

	if (!s1 || !s2)
		return (NULL);
	if (!(s3 = ft_strnew(ft_strlen(s1) + len)))
		return (NULL);
	s3 = ft_strcpy(s3, s1);
	s3 = ft_strncat(s3, s2, len);
	return (s3);
}

static	char	*ft_add(char *content, char *buff, int result)
{
	char		*p;

	p = content;
	content = ft_strnjoin(content, buff, result);
	free(p);
	return (content);
}

int				get_next_line(const int fd, char **line)
{
	static	t_list	*new_line;
	t_list			*head;
	char			buff[BUFF_SIZE + 1];
	int				result;
	char			*s;

	if (fd < 0 || read(fd, buff, 0) < 0 || !line)
		return (-1);
	head = new_line;
	new_line = ft_correct_fd(&head, fd);
	while (!ft_strchr(new_line->content, '\n')
		&& (result = read(fd, buff, BUFF_SIZE)))
		new_line->content = ft_add(new_line->content, buff, result);
	result = 0;
	while (((char *)new_line->content)[result]
		&& ((char *)new_line->content)[result] != '\n')
		result++;
	*line = ft_strndup(new_line->content, result);
	if (((char *)new_line->content)[result] == '\n')
		result++;
	s = new_line->content;
	new_line->content = ft_strdup(new_line->content + result);
	free(s);
	new_line = head;
	return (result ? 1 : 0);
}
