/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erbuffet <erbuffet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 14:13:53 by nikado            #+#    #+#             */
/*   Updated: 2025/04/10 08:16:27 by erbuffet         ###   ########lyon.fr   */
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
	return ;
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
