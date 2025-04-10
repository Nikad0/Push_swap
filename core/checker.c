/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erbuffet <erbuffet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 16:32:15 by nikado            #+#    #+#             */
/*   Updated: 2025/04/09 18:59:36 by erbuffet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	duplicate_checker(t_node *stack)
{
	t_node	*tmp;
	t_node	*compare_node;

	if (stack == NULL)
		return (0);
	tmp = stack;
	while (tmp != stack->prev)
	{
		compare_node = tmp->next;
		while (compare_node != stack)
		{
			if (tmp->value == compare_node->value)
			{
				return (1);
			}
			compare_node = compare_node->next;
		}
		tmp = tmp->next;
	}
	return (0);
}
