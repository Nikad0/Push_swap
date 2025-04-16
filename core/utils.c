/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erbuffet <erbuffet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 14:13:53 by nikado            #+#    #+#             */
/*   Updated: 2025/04/16 16:49:34 by erbuffet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_list(t_node **stack)
{
	t_node	*tmp;
	t_node	*first_node;

	if (*stack == NULL)
		return ;
	first_node = (*stack);
	tmp = (*stack);
	while (tmp->next != first_node)
	{
		tmp = tmp->next;
		free(tmp->prev);
	}
	free(tmp);
	(*stack) = NULL;
}

void	exit_error(char *msg)
{
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
	exit(-1);
}

ssize_t	is_sorted(t_node **stack)
{
	t_node	*tmp;

	tmp = *stack;
	while (tmp != (*stack)->prev)
	{
		if (tmp->value > tmp->next->value)
			return (-1);
		tmp = tmp->next;
	}
	return (1);
}

void	free_tab(char **tab)
{
	size_t	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

void	indexing(t_node **stack)
{
	t_node	*tmp;
	t_node	*compare;
	int		index;

	if (!(*stack))
		return ;
	tmp = (*stack);
	while ((*stack))
	{
		index = 1;
		compare = (*stack);
		while ((*stack))
		{
			if (compare->value < tmp->value)
				index++;
			compare = compare->next;
			if (compare == (*stack))
				break ;
		}
		tmp->index = index;
		tmp = tmp->next;
		if (tmp == (*stack))
			break ;
	}
}
