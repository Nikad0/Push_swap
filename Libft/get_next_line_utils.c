/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erbuffet <erbuffet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:30:11 by erbuffet          #+#    #+#             */
/*   Updated: 2025/03/24 22:02:52 by erbuffet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen_gnl(const char *str)
{
	size_t	l;

	l = 0;
	while (str && str[l] && str[l] != '\n')
		l++;
	if (str && str[l] == '\n')
		l++;
	return (l);
}

char	*ft_strcpy(char *dst, const char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

int	strchr_gnl(const char *s, int c)
{
	size_t	i;
	char	tmp;

	i = 0;
	tmp = (unsigned char)c;
	while (s[i] && s[i] != tmp)
		i++;
	if (s[i] == tmp)
		return (i + 1);
	return (0);
}

char	*ft_strjoin_gnl(char *s1, const char *s2)
{
	char	*dest;
	int		i;

	i = 0;
	dest = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!dest)
		return (free(s1), NULL);
	while (s1 && s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	while (s2 && *s2 && *s2 != '\n')
	{
		dest[i] = *s2;
		i++;
		s2++;
	}
	if (s2 && *s2 == '\n')
		dest[i++] = '\n';
	dest[i] = '\0';
	return (free(s1), dest);
}
