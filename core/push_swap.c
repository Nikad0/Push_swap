/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erbuffet <erbuffet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 22:00:37 by erbuffet          #+#    #+#             */
/*   Updated: 2025/04/18 14:03:39 by erbuffet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	sort(&stack_a, &stack_b);
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
		checker(arg, 's');
		free_tab(arg);
	}
	else
	{
		arg = av;
		checker(arg + 1, 'o');
	}
}

int	main(int ac, char **av)
{
	if (ac < 2)
		exit_error("Error : no argument given !");
	else
		pars_argument(ac, av);
	return (0);
}
