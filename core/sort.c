/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erbuffet <erbuffet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 13:41:18 by nikado            #+#    #+#             */
/*   Updated: 2025/04/15 21:41:47 by erbuffet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_node **stack_a, t_node **stack_b)
{
	int	list_size;

	if (!stack_a || !stack_b)
		exit_error("Error : stack error sort_algo()");
	indexing(stack_a);
	list_size = get_list_size(*stack_a);
	if (is_sorted(stack_a) == 1)
		return ;
	while (is_sorted(stack_a) == -1)
	{
		if (list_size == 2)
			swap_a(*stack_a);
		else if (list_size == 3)
			sort_3(stack_a);
		else if (list_size > 3)
			sort_algo(stack_a, stack_b, list_size);
	}
}

void	sort_3(t_node **stack_a)
{
	ssize_t	max_value;

	max_value = get_max_value(*stack_a);
	if ((*stack_a)->value == max_value)
		rotate_a(stack_a);
	else if ((*stack_a)->next->value == max_value)
		reverse_rotate_a(stack_a);
	else if ((*stack_a)->prev->value == max_value)
		swap_a(*stack_a);
}

void	sort_algo(t_node **stack_a, t_node **stack_b, int list_size)
{
	int	index;
	int	chunk;

	chunk = chunk_size(list_size);
	index = 0;
	while (index < list_size)
	{
		if ((*stack_a)->index <= index)
		{
			push_b(stack_a, stack_b);
			index++;
		}
		else if ((*stack_a)->index <= index + chunk)
		{
			push_b(stack_a, stack_b);
			rotate_b(stack_b);
			index++;
		}
		else
			rotate_a(stack_a);
	}
	to_a(stack_a, stack_b);
}
void	to_a(t_node **stack_a, t_node **stack_b)
{
	while ((*stack_b))
	{
		if ((*stack_b)->index < (*stack_b)->prev->index)
			reverse_rotate_b(stack_b);
		else
			push_a(stack_a, stack_b);
	}
}