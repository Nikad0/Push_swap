/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erbuffet <erbuffet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:58:22 by erbuffet          #+#    #+#             */
/*   Updated: 2025/03/21 14:56:59 by erbuffet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_node **stack_a, t_node **stack_b)
{
	int	size;

	if (*stack_b == NULL)
		return ;
	size = get_list_size(*stack_b);
	if (*stack_a == NULL)
		push_a_utils(stack_a, stack_b);
	else
		push_a_utils_2(stack_a, stack_b);
	if (size == 1)
		*stack_b = NULL;
	ft_printf("pa\n");
}

void	push_b(t_node **stack_a, t_node **stack_b)
{
	int	size;

	if (*stack_a == NULL)
		return ;
	size = get_list_size(*stack_a);
	if (*stack_b == NULL)
		push_b_utils(stack_a, stack_b);
	else
		push_b_utils_2(stack_a, stack_b);
	if (size == 1)
		*stack_a = NULL;
	ft_printf("pb\n");
}
