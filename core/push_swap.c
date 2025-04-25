/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erbuffet <erbuffet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 22:00:37 by erbuffet          #+#    #+#             */
/*   Updated: 2025/04/25 14:54:52 by erbuffet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_node **stack_a, char **arg, char c)
{
	int			i;
	long long	value;
	t_node		*next_node;

	i = 1;
	next_node = NULL;
	*stack_a = create_node(ft_atoll_push(arg[0]));
	if (*arg == NULL)
		exit_error("Error");
	while (arg[i])
	{
		value = ft_atoll_push(arg[i++]);
		next_node = create_node(value);
		if (next_node == NULL)
		{
			if (c == 's')
				free_tab(arg);
			free_list(stack_a);
			exit_error("Error");
		}
		else
			add_back(next_node, stack_a);
	}
}

void	init(char **arg, char c)
{
	t_node	*stack_a;
	t_node	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	init_stack(&stack_a, arg, c);
	sort(&stack_a, &stack_b);
	free_list(&stack_a);
	free_list(&stack_b);
}

bool	empty(char **arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (ft_strlen(arg[i]) > 10)
		{
			free_tab(arg);
			exit_error("Error");
		}
		i++;
	}
	if (i == 0)
		return (true);
	return (false);
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
			exit_error("Error");
		if (empty(arg))
		{
			free(arg);
			exit_error("Error");
		}
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
		return (0);
	else
		pars_argument(ac, av);
	return (0);
}
