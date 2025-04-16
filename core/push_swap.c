/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erbuffet <erbuffet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 22:00:37 by erbuffet          #+#    #+#             */
/*   Updated: 2025/04/16 21:55:19 by erbuffet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list(t_node *stack, char *a)
{
	int	size_list;

	if (stack == NULL)
		return ;
	size_list = get_list_size(stack);
	while (size_list--)
	{
		printf("value stack_%s : %lld\n", a, stack->value);
		printf("index stack_%s = %d\n", a, stack->index);
		printf("prev stack_%s : %p\n", a, stack->prev);
		printf("adress stack_%s : %p\n", a, stack);
		printf("next stack_%s : %p\n\n", a, stack->next);
		stack = stack->next;
	}
}

void	init_stack(t_node **stack_a, char **av)
{
	int			i;
	long long	value;
	t_node		*next_node;

	i = 1;
	next_node = NULL;
	*stack_a = create_node(stack_a, ft_atoll_push(av[0]));
	while (av[i])
	{
		value = ft_atoll_push(av[i++]);
		next_node = create_node(stack_a, value);
		add_back(next_node, stack_a);
	}
}

int	main(int ac, char **av)
{
	t_node	*stack_a;
	t_node	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac < 2)
	{
		exit_error("Error : no argument given !");
		return (-1);
	}
	if (ac == 2)
	{
		av = ft_split(av[1], ' ');
		if (av[0] == NULL)
		{
			free_tab(av);
			exit_error("Error : argument given empty !");
			return (-1);
		}
		init_stack(&stack_a, av);
		free_tab(av);
	}
	if (ac > 2)
		init_stack(&stack_a, av + 1);
	checker(&stack_a);
	sort(&stack_a, &stack_b);
	free_list(&stack_a);
	free_list(&stack_b);
	return (0);
}
