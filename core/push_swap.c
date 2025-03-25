/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erbuffet <erbuffet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 22:00:37 by erbuffet          #+#    #+#             */
/*   Updated: 2025/03/24 23:06:49 by erbuffet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list(t_node *stack, char a)
{
	int	size_list;

	if (stack == NULL)
		return ;
	size_list = get_list_size(stack);
	while (size_list--)
	{
		printf("value stack_%c : %d\n", a, stack->value);
		printf("prev stack_%c : %p\n", a, stack->prev);
		printf("adress stack_%c : %p\n", a, stack);
		printf("next stack_%c : %p\n\n", a, stack->next);
		stack = stack->next;
	}
}

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

int	exit_error(char *msg)
{
	ft_printf("%s\n", msg);
	exit(-1);
}

int	main(int ac, char **av)
{
	int		i;
	t_node	*stack_a;
	t_node	*stack_b;
	t_node	*next_node;

	if (ac < 2)
		exit_error("Error : no argument given !");
	// checker(ac, av);
	i = 1;
	stack_a = create_node(ft_atoi(av[1]));
	stack_b = NULL;
	next_node = NULL;
	while (++i < ac)
	{
		next_node = create_node((ft_atoi(av[i])));
		add_back(next_node, &stack_a);
	}
	print_list(stack_a, 'a');
	print_list(stack_b, 'b');
	free_list(&stack_a);
	free_list(&stack_b);
	return (0);
}
