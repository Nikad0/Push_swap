/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erbuffet <erbuffet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:56:37 by erbuffet          #+#    #+#             */
/*   Updated: 2025/03/24 20:30:33 by erbuffet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_node *stack_a)
{
	int	tmp;

	if (stack_a == NULL)
		return ;
	tmp = stack_a->value;
	stack_a->value = stack_a->next->value;
	stack_a->next->value = tmp;
	ft_printf("sa\n");
}

void	swap_b(t_node *stack_b)
{
	int	tmp;

	if (stack_b == NULL)
		return ;
	tmp = stack_b->value;
	stack_b->value = stack_b->next->value;
	stack_b->next->value = tmp;
	ft_printf("sb\n");
}

void	swap_s(t_node *stack_a, t_node *stack_b)
{
	int	tmp_a;
	int	tmp_b;

	if (stack_a == NULL || stack_b == NULL)
		return ;
	tmp_a = stack_a->value;
	stack_a->value = stack_a->next->value;
	stack_a->next->value = tmp_a;
	tmp_b = stack_b->value;
	stack_b->value = stack_b->next->value;
	stack_b->next->value = tmp_b;
	ft_printf("ss\n");
}
