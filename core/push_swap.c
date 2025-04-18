/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erbuffet <erbuffet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 22:00:37 by erbuffet          #+#    #+#             */
/*   Updated: 2025/04/18 01:47:13 by erbuffet         ###   ########lyon.fr   */
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

void	init_stack(t_node **stack_a, char **arg)
{
	int			i;
	long long	value;
	t_node		*next_node;

	i = 1;
	next_node = NULL;
	*stack_a = create_node(stack_a, ft_atoll_push(arg[0]));
	while (arg[i])
	{
		value = ft_atoll_push(arg[i++]);
		next_node = create_node(stack_a, value);
		add_back(next_node, stack_a);
	}
}
void	init(char **arg)
{
	t_node	*stack_a;
	t_node	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	init_stack(&stack_a, arg);
	// print_list(stack_a, "a");
	int x = 0;
	while (arg[x])
		printf("%s\n", arg[x++]);
	// sort(&stack_a, &stack_b);
	free_list(&stack_a);
	free_list(&stack_b);
}
void	pars_argument(int ac, char **av)
{
	char	**arg;
	int		i;

	i = 0;
	arg = NULL;
	if (ac == 2)
	{
		arg = ft_split(av[1], ' ');
		if (!arg)
			return ;
		checker(arg);
		free_tab(arg);
	}
	arg = av;
	checker(arg + 1);
}

int	main(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac < 2)
		exit_error("Error : no argument given !");
	else
		pars_argument(ac, av);
	return (0);
}
