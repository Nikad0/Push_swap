/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erbuffet <erbuffet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:57:56 by erbuffet          #+#    #+#             */
/*   Updated: 2025/04/07 14:45:42 by erbuffet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_node **stack_a)
{
	if (*stack_a == NULL)
		return ;
	(*stack_a) = (*stack_a)->next;
	ft_printf("ra\n");
}

void	rotate_b(t_node **stack_b)
{
	if (*stack_b == NULL)
		return ;
	(*stack_b) = (*stack_b)->next;
	ft_printf("rb\n");
}

void	rotate_r(t_node **stack_a, t_node **stack_b)
{
	if (*stack_a == NULL || *stack_b == NULL)
		return ;
	(*stack_a) = (*stack_a)->next;
	(*stack_b) = (*stack_b)->next;
	ft_printf("rr\n");
}
