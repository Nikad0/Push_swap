/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erbuffet <erbuffet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:58:43 by erbuffet          #+#    #+#             */
/*   Updated: 2025/03/21 15:52:15 by erbuffet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_a(t_node **stack_a)
{
	if (*stack_a == NULL)
		return ;
	(*stack_a) = (*stack_a)->prev;
	ft_printf("rra\n");
}

void	reverse_rotate_b(t_node **stack_b)
{
	if (*stack_b == NULL)
		return ;
	(*stack_b) = (*stack_b)->prev;
	ft_printf("rrb\n");
}

void	reverse_rotate_r(t_node **stack_a, t_node **stack_b)
{
	if (*stack_a == NULL || *stack_b == NULL)
		return ;
	(*stack_a) = (*stack_a)->prev;
	(*stack_b) = (*stack_b)->prev;
	ft_printf("rrr\n");
}
