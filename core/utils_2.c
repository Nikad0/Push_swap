/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erbuffet <erbuffet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 18:27:08 by erbuffet          #+#    #+#             */
/*   Updated: 2025/04/15 21:23:49 by erbuffet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	chunk_size(int list_size)
{
	int chunk_size;
	chunk_size = 0.00000001 * (list_size * list_size) + 0.03 * list_size + 14.5;
	return (chunk_size);
}