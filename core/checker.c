/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erbuffet <erbuffet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 16:32:15 by nikado            #+#    #+#             */
/*   Updated: 2025/04/16 17:57:34 by erbuffet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	checker(t_node **stack_a)
{
	if (duplicate_checker(*stack_a))
	{
		free_list(stack_a);
		exit_error("Error : duplicate in arguments given !");
	}
	if ((*stack_a)->value < INT_MIN || (*stack_a)->value > INT_MAX)
	{
		free_list(stack_a);
		exit_error("Error : argument not in INT range !");
	}
}

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
		while (compare_node != tmp)
		{
			if (tmp->value == compare_node->value)
				return (1);
			compare_node = compare_node->next;
		}
		tmp = tmp->next;
	}
	return (0);
}
