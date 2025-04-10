/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erbuffet <erbuffet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 21:19:11 by erbuffet          #+#    #+#             */
/*   Updated: 2025/04/07 14:45:47 by erbuffet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a_utils(t_node **stack_a, t_node **stack_b)
{
	t_node	*tmp;

	tmp = (*stack_b)->next;
	(*stack_a) = (*stack_b);
	tmp->prev = (*stack_b)->prev;
	tmp->prev->next = tmp;
	(*stack_b)->next = (*stack_b);
	(*stack_b)->prev = (*stack_b);
	(*stack_b) = tmp;
}

void	push_a_utils_2(t_node **stack_a, t_node **stack_b)
{
	t_node	*tmp;

	tmp = (*stack_b);
	(*stack_b) = (*stack_b)->next;
	(*stack_b)->prev = tmp->prev;
	tmp->prev->next = (*stack_b);
	add_front(tmp, stack_a);
	(*stack_a) = tmp;
}

void	push_b_utils(t_node **stack_a, t_node **stack_b)
{
	t_node	*tmp;

	tmp = (*stack_a)->next;
	(*stack_b) = (*stack_a);
	tmp->prev = (*stack_a)->prev;
	tmp->prev->next = tmp;
	(*stack_a)->next = (*stack_a);
	(*stack_a)->prev = (*stack_a);
	(*stack_a) = tmp;
}

void	push_b_utils_2(t_node **stack_a, t_node **stack_b)
{
	t_node	*tmp;

	tmp = (*stack_a);
	(*stack_a) = tmp->next;
	(*stack_a)->prev = tmp->prev;
	tmp->prev->next = (*stack_a);
	add_front(tmp, stack_b);
	(*stack_b) = tmp;
}
