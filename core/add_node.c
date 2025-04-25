/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erbuffet <erbuffet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 12:57:33 by erbuffet          #+#    #+#             */
/*   Updated: 2025/04/25 13:45:43 by erbuffet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*create_node(long long value)
{
	t_node	*next_node;

	next_node = malloc(sizeof(t_node));
	if (!next_node)
		return (next_node);
	next_node->value = value;
	next_node->index = 1;
	next_node->next = next_node;
	next_node->prev = next_node;
	return (next_node);
}

void	add_back(t_node *new_node, t_node **stack)
{
	t_node	*tmp_node;

	tmp_node = (*stack);
	if (!new_node)
		return ;
	if ((*stack) == NULL)
		(*stack) = new_node;
	else
	{
		while (tmp_node->next != NULL && tmp_node->next != *stack)
			tmp_node = tmp_node->next;
		tmp_node->next = new_node;
		new_node->prev = tmp_node;
		new_node->next = (*stack);
		(*stack)->prev = new_node;
	}
}

void	add_front(t_node *new_node, t_node **stack)
{
	if (!new_node)
		return ;
	new_node->next = (*stack);
	new_node->prev = (*stack)->prev;
	(*stack)->prev->next = new_node;
	(*stack)->prev = new_node;
}
