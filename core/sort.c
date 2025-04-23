/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erbuffet <erbuffet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 13:41:18 by nikado            #+#    #+#             */
/*   Updated: 2025/04/23 13:01:26 by erbuffet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_node **stack_a, t_node **stack_b)
{
	int	list_size;

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
		else if (list_size <= 5)
			sort_5(stack_a, stack_b);
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
	if (is_sorted(stack_a) == -1)
		swap_a((*stack_a));
}

void	sort_5(t_node **stack_a, t_node **stack_b)
{
	ssize_t	min_value;
	int		list_size;

	list_size = get_list_size(*stack_a);
	while (list_size > 3)
	{
		min_value = get_min_value(*stack_a);
		if ((*stack_a)->prev->value == min_value)
			reverse_rotate_a(stack_a);
		else
			rotate_a(stack_a);
		if ((*stack_a)->value == min_value)
		{
			push_b(stack_a, stack_b);
			list_size--;
		}
	}
	if (is_sorted(stack_a) == -1)
		sort_3(stack_a);
	if ((*stack_b)->value < (*stack_b)->next->value)
		swap_b(*stack_b);
	while ((*stack_b))
		push_a(stack_a, stack_b);
}

void	sort_algo(t_node **stack_a, t_node **stack_b, int list_size)
{
	int	index;
	int	chunk;

	index = 0;
	chunk = chunk_size(list_size);
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
	t_node	*tmp;
	int		list_size;
	int		median;
	int		i;

	while ((*stack_b))
	{
		i = 0;
		tmp = (*stack_b);
		list_size = get_list_size(*stack_b);
		median = list_size / 2;
		while (tmp)
		{
			if (tmp->index == list_size)
				break ;
			tmp = tmp->next;
			i++;
		}
		if (i == 0 && (*stack_b)->index == list_size)
			push_a(stack_a, stack_b);
		else if (i > median)
			reverse_rotate_b(stack_b);
		else
			rotate_b(stack_b);
	}
}
