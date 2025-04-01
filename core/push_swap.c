/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikado <nikado@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 22:00:37 by erbuffet          #+#    #+#             */
/*   Updated: 2025/04/01 18:49:07 by nikado           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_list(t_node *stack, char a)
{
	int size_list;

	if (stack == NULL)
		return;
	size_list = get_list_size(stack);
	while (size_list--)
	{
		printf("value stack_%c : %lld\n", a, stack->value);
		printf("prev stack_%c : %p\n", a, stack->prev);
		printf("adress stack_%c : %p\n", a, stack);
		printf("next stack_%c : %p\n\n", a, stack->next);
		stack = stack->next;
	}
}

void free_list(t_node **stack)
{
	t_node *tmp;
	t_node *first_node;

	if (*stack == NULL)
		return;
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

int exit_error(char *msg)
{

	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
	exit(-1);
}

int main(int ac, char **av)
{
	t_node *stack_a;
	t_node *stack_b;
	t_node *next_node;
	int i;

	stack_a = NULL;
	stack_b = NULL;
	next_node = NULL;
	i = 1;
	if (ac < 2)
		exit_error("Error : no argument given !");
	// if (ac == 2)
	// 	av = ft_split(av[1], ' ');
	stack_a = create_node(&stack_a, ft_atoll(av[1]));
	while (++i < ac)
	{
		next_node = create_node(&stack_a, ft_atoll(av[i]));
		add_back(next_node, &stack_a);
	}
	if (duplicate_checker(stack_a))
		exit_error("Error : duplicate in arguments given !");
	sort(&stack_a, &stack_b);
	print_list(stack_a, 'a');
	print_list(stack_b, 'b');
	free_list(&stack_a);
	free_list(&stack_b);
	return (0);
}
