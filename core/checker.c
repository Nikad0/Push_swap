/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikado <nikado@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 16:32:15 by nikado            #+#    #+#             */
/*   Updated: 2025/04/02 21:20:41 by nikado           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int duplicate_checker(t_node *stack)
{
    t_node *tmp;
    t_node *compare_node;

    if (stack == NULL)
        return (0);
    tmp = stack;
    while (tmp != stack->prev)
    {
        compare_node = tmp->next;
        while (compare_node != stack)
        {
            if (tmp->value == compare_node->value)
            {
                // free_list(&stack);
                return (1);
            }
            compare_node = compare_node->next;
        }
        tmp = tmp->next;
    }
    return (0);
}
