/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erbuffet <erbuffet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 16:32:15 by nikado            #+#    #+#             */
/*   Updated: 2025/04/18 01:57:27 by erbuffet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	duplicate_checker(char **arg)
{
	int	i;
	int	j;

	i = 0;
	while (arg[i])
	{
		j = i + 1;
		while (arg[j])
		{
			if (ft_atoi(arg[i]) == ft_atoi(arg[j]))
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	digit_checker(char **arg)
{
	int	i;
	int	j;

	i = 0;
	while (arg[i])
	{
		j = 0;
		while (arg[i][j])
		{
			if (arg[i][j] == '-' || arg[i][j] == '+')
				j++;
			if (arg[i][j] < '0' || arg[i][j] > '9')
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}
static int	range_checker(char **arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (ft_atoll_push(arg[i]) > INT_MAX
			|| ft_atoll_push(arg[i++]) < INT_MIN)
			return (-1);
	}
	return (0);
}

void	checker(char **arg)
{
	if (arg)
	{
		if (digit_checker(arg) == -1)
			exit_error("Error : Argument is not a number !");
		else if (range_checker(arg) == -1)
			exit_error("Error : Argument not in int range !");
		else if (duplicate_checker(arg) == -1)
			exit_error("Error : Duplicate number !");
		else
			init(arg);
	}
	else
	{
		return ;
	}
}
