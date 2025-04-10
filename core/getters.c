/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erbuffet <erbuffet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 22:20:45 by erbuffet          #+#    #+#             */
/*   Updated: 2025/04/10 11:02:45 by erbuffet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


ssize_t	get_min_index(t_node *stack, ssize_t min_value)
{
	t_node	*tmp;
	ssize_t	min_index;

	tmp = stack;
	min_index = 0;
	while (tmp)
	{
		if (tmp->value == min_value)
			return (min_index);
		tmp = tmp->next;
		min_index++;
	}
	return (-1);
}

ssize_t	get_list_size(t_node *stack)
{
	t_node	*tmp;
	ssize_t	size;

	size = 1;
	tmp = stack;
	if (stack == NULL)
		return (0);
	while (tmp != stack->prev)
	{
		size++;
		tmp = tmp->next;
	}
	return (size);
}

ssize_t	get_max_value(t_node *stack)
{
	t_node	*tmp;
	ssize_t	max_value;

	if (stack == NULL)
		return (0);
	max_value = stack->value;
	tmp = stack->next;
	while (tmp != stack)
	{
		if (tmp->value > max_value)
			max_value = tmp->value;
		tmp = tmp->next;
	}
	return (max_value);
}

ssize_t	get_min_value(t_node *stack)
{
	t_node	*tmp;
	ssize_t	min_value;

	if (stack == NULL)
		return (0);
	min_value = stack->value;
	tmp = stack->next;
	while (tmp != stack)
	{
		if (tmp->value < min_value)
			min_value = tmp->value;
		tmp = tmp->next;
	}
	return (min_value);
}
