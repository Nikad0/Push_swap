/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikado <nikado@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 14:27:24 by erbuffet          #+#    #+#             */
/*   Updated: 2025/04/01 17:02:51 by nikado           ###   ########.fr       */
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
	long long value;

	struct s_node *next;
	struct s_node *prev;
}			t_node;

typedef struct s_data
{
	int		size_a;
	int		size_b;
	t_node	**stack_a;
	t_node	**stack_b;
}			t_data;

/*utils*/
void free_list(t_node **stack);
int exit_error(char *msg);

/*checker.c*/

int duplicate_checker(t_node *stack);

/*getters.c*/
ssize_t get_list_size(t_node *stack);
ssize_t get_max_value(t_node *stack);

/*rotate.c*/
void rotate_a(t_node **stack_a);
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
t_node *create_node(t_node **stack, long long value);
void		add_back(t_node *next_node, t_node **stack);
void		add_front(t_node *prev_node, t_node **stack);

/*sort*/
void sort(t_node **stack_a, t_node **stack_b);
void sort_3(t_node **stack_a);
void turck_sort(t_node **stack_a, t_node **stack_b);

#endif
