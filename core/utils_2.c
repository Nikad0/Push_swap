/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erbuffet <erbuffet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 18:27:08 by erbuffet          #+#    #+#             */
/*   Updated: 2025/04/18 14:05:35 by erbuffet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	chunk_size(int list_size)
{
	int	chunk_size;

	chunk_size = 0.00000003 * (list_size * list_size) + 0.03 * list_size + 14.5;
	return (chunk_size);
}

long long	ft_atoll_push(const char *nptr)
{
	long long	nb;
	int			i;
	int			signe;

	i = 0;
	nb = 0;
	signe = 1;
	while ((nptr[i] >= '\t' && nptr[i] <= '\r') || (nptr[i] == ' '))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			signe *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nb = nb * 10 + nptr[i] - 48;
		i++;
	}
	return (nb * signe);
}
