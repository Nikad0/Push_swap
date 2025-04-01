/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikado <nikado@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 13:41:18 by nikado            #+#    #+#             */
/*   Updated: 2025/04/01 18:57:36 by nikado           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort(t_node **stack_a, t_node **stack_b)
{
    ssize_t list_size;
    (void)stack_b;

    list_size = get_list_size(*stack_a);
    if (list_size == 2)
        swap_a(*stack_a);
    else if (list_size == 3)
        sort_3(stack_a);
    // else if (list_size < 3)
    //     turck_sort(stack_a, stack_b);
}

void sort_3(t_node **stack_a)
{
    ssize_t max_value;

    max_value = get_max_value(*stack_a);
    if ((*stack_a)->prev->value == max_value)
        swap_a(*stack_a);
    else if ((*stack_a)->next->value == max_value)
        reverse_rotate_a(stack_a);
    else if ((*stack_a)->value == max_value)
        rotate_a(stack_a);
}

// void turck_sort(t_node **stack_a, t_node **stack_b)
// {
// }