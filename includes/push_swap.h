/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erbuffet <erbuffet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 14:27:24 by erbuffet          #+#    #+#             */
/*   Updated: 2025/03/24 22:35:56 by erbuffet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_node
{
	int value; // contenue de la list (argv)

	struct s_node *next; // pointeur sur la node suivante
	struct s_node *prev; // pointeur sur la node precedente
}			t_node;

typedef struct s_data
{
	int		size_a;
	int		size_b;
	t_node	**stack_a;
	t_node	**stack_b;
}			t_data;

int			exit_error(char *msg);
/*checker.c*/
void		checker(int ac, char **av);
/*getters.c*/
int			get_list_size(t_node *stack);

/*rotate.c*/
void		rotate_a(t_node **stack_a);
void		rotate_b(t_node **stack_b);
void		rotate_r(t_node **stack_a, t_node **stack_b);

/*reverse_rotate.c*/
void		reverse_rotate_a(t_node **stack_a);
void		reverse_rotate_b(t_node **stack_b);
void		reverse_rotate_r(t_node **stack_a, t_node **stack_b);

/*swap.c*/
void		swap_a(t_node *stack_a);
void		swap_b(t_node *stack_b);
void		swap_s(t_node *stack_a, t_node *stack_b);

/*push.c*/
void		push_b(t_node **stack_a, t_node **stack_b);
void		push_a(t_node **stack_a, t_node **stack_b);

/*push_utils.c*/
void		push_a_utils(t_node **stack_a, t_node **stack_b);
void		push_a_utils_2(t_node **stack_a, t_node **stack_b);
void		push_b_utils(t_node **stack_a, t_node **stack_b);
void		push_b_utils_2(t_node **stack_a, t_node **stack_b);

/*add_node.c*/
t_node		*create_node(int value);
void		add_back(t_node *next_node, t_node **stack);
void		add_front(t_node *prev_node, t_node **stack);
#endif
