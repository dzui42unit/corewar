/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozabara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 16:37:39 by ozabara           #+#    #+#             */
/*   Updated: 2017/01/30 16:38:52 by ozabara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "libft.h"
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# define BUFF_SIZE 1000

typedef struct			s_templst
{
	int					fd;
	char				*temp;
	size_t				temp_size;
	struct s_templst	*next;
}						t_ftemp;

int						get_next_line(const int fd, char **line);

#endif
