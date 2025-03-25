/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erbuffet <erbuffet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:25:57 by erbuffet          #+#    #+#             */
/*   Updated: 2025/01/08 14:47:34 by erbuffet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_next_line(int fd)
{
	static char	buf[FD_SIZE][BUFFER_SIZE + 1];
	char		*l;
	ssize_t		bytesread;

	l = NULL;
	if (fd < 0 || BUFFER_SIZE < 1 || fd >= FD_SIZE)
		return (NULL);
	while (1)
	{
		if (buf[fd][0] == 0)
		{
			bytesread = read(fd, buf[fd], BUFFER_SIZE);
			if (bytesread <= 0)
			{
				if (l != NULL && bytesread != -1)
					return (l);
				return (free(l), NULL);
			}
			buf[fd][bytesread] = '\0';
		}
		l = ft_strjoin_gnl(l, buf[fd]);
		if (l && strchr_gnl(buf[fd], '\n') != 0)
			return (ft_strcpy(buf[fd], buf[fd] + strchr_gnl(buf[fd], '\n')), l);
		buf[fd][0] = '\0';
	}
}
