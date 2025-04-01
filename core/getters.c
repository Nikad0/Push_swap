/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikado <nikado@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 22:20:45 by erbuffet          #+#    #+#             */
/*   Updated: 2025/04/01 18:48:59 by nikado           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

ssize_t get_list_size(t_node *stack)
{
	t_node	*tmp;
	ssize_t size;

	size = 1;
	tmp = stack->next;
	if (stack == NULL)
		return (0);
	while (tmp != stack)
	{
		size++;
		tmp = tmp->next;
	}
	return (size);
}

ssize_t get_max_value(t_node *stack)
{
	t_node *tmp;
	ssize_t max_value;

	max_value = stack->value;
	tmp = stack->next;
	while (tmp != stack)
	{
		if (tmp->value > stack->value)
			max_value = tmp->value;
		tmp = tmp->next;
	}
	return (max_value);
}
