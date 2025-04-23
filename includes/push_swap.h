/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erbuffet <erbuffet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 14:27:24 by erbuffet          #+#    #+#             */
/*   Updated: 2025/04/23 12:56:28 by erbuffet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_node
{
	long long		value;
	int				index;

	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

/*utils*/
void				print_list(t_node *stack, char *a);
void				free_list(t_node **stack);
void				exit_error(char *msg);
void				free_tab(char **tab);
ssize_t				is_sorted(t_node **stack);
int					chunk_size(int list_size);
long long			ft_atoll_push(const char *nptr);

/*checker.c*/
void				pars_argument(int ac, char **av);
void				init(char **av, char c);
void				checker(char **av, char c);

/*getters.c*/
int					get_n_chunk(int list_size);
int					get_list_size(t_node *stack);
ssize_t				get_max_value(t_node *stack);
ssize_t				get_min_value(t_node *stack);
ssize_t				get_min_index(t_node *stack, ssize_t min_value);

/*rotate.c*/
void				rotate_a(t_node **stack_a);
void				rotate_b(t_node **stack_b);
void				rotate_r(t_node **stack_a, t_node **stack_b);

/*reverse_rotate.c*/
void				reverse_rotate_a(t_node **stack_a);
void				reverse_rotate_b(t_node **stack_b);
void				reverse_rotate_r(t_node **stack_a, t_node **stack_b);

/*swap.c*/
void				swap_a(t_node *stack_a);
void				swap_b(t_node *stack_b);
void				swap_s(t_node *stack_a, t_node *stack_b);

/*push.c*/
void				push_b(t_node **stack_a, t_node **stack_b);
void				push_a(t_node **stack_a, t_node **stack_b);

/*push_utils.c*/
void				push_a_utils(t_node **stack_a, t_node **stack_b);
void				push_a_utils_2(t_node **stack_a, t_node **stack_b);
void				push_b_utils(t_node **stack_a, t_node **stack_b);
void				push_b_utils_2(t_node **stack_a, t_node **stack_b);

/*add_node.c*/
t_node				*create_node(long long value);
void				add_back(t_node *next_node, t_node **stack);
void				add_front(t_node *prev_node, t_node **stack);

/*sort*/
void				indexing(t_node **stack);
void				sort_3(t_node **stack_a);
void				sort_5(t_node **stack_a, t_node **stack_b);
void				to_a(t_node **stack_a, t_node **stack_b);
void				sort(t_node **stack_a, t_node **stack_b);
void				sort_algo(t_node **stack_a, t_node **stack_b,
						int list_size);

#endif
