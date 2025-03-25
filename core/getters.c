/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erbuffet <erbuffet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 22:20:45 by erbuffet          #+#    #+#             */
/*   Updated: 2025/03/19 17:57:02 by erbuffet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_list_size(t_node *stack)
{
	t_node	*tmp;
	int		size;

	size = 1;
	tmp = stack->next;
	if (stack == NULL)
		return (0);
	while (tmp != stack)
	{
		size++;
		tmp = tmp->next;
	}
	return (size);
}
