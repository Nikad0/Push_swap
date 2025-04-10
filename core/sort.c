/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erbuffet <erbuffet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 13:41:18 by nikado            #+#    #+#             */
/*   Updated: 2025/04/10 11:40:55 by erbuffet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void optimize_stack_b(t_node **stack_b);

void	sort(t_node **stack_a, t_node **stack_b)
{
	ssize_t	list_size;

	(void)stack_b;
	list_size = get_list_size(*stack_a);
	if (is_sorted(stack_a) == 1)
		return ;
	while (is_sorted(stack_a) == -1)
	{
		if (list_size == 2)
			swap_a(*stack_a);
		else if (list_size == 3)
			sort_3(stack_a);
		else if (list_size > 3)
			swap_sort(stack_a, stack_b);
	}
}

void	sort_3(t_node **stack_a)
{
	ssize_t	max_value;

	max_value = get_max_value(*stack_a);
	if ((*stack_a)->value == max_value)
		rotate_a(stack_a);
	else if ((*stack_a)->next->value == max_value)
		reverse_rotate_a(stack_a);
	else if ((*stack_a)->prev->value == max_value)
		swap_a(*stack_a);
}

void swap_sort(t_node **stack_a, t_node **stack_b)
{
    ssize_t list_size;
    ssize_t min_val, max_val;
    ssize_t chunk_size;
    int chunk_count;
    
    // Get initial list size
    list_size = get_list_size(*stack_a);
    
    // Early return if already sorted
    if (is_sorted(stack_a) == 1)
        return;
        
    // Get min and max values
    min_val = get_min_value(*stack_a);
    max_val = get_max_value(*stack_a);
    
    // Determine chunk count based on list size
    if (list_size <= 20)
        chunk_count = 3;
    else if (list_size <= 100)
        chunk_count = 5;
    else
        chunk_count = 11;
        
    chunk_size = ((max_val - min_val) / chunk_count) + 1;
    
    // Push elements to stack B in chunks
    for (int chunk = 0; chunk < chunk_count; chunk++)
    {
        ssize_t chunk_min = min_val + (chunk * chunk_size);
        ssize_t chunk_max = chunk_min + chunk_size - 1;
        
        // Continue until no more elements in this chunk
        int elements_pushed = 1;
        while (elements_pushed && *stack_a)
        {
            elements_pushed = 0;
            
            // Find an element in the current chunk
            t_node *current = *stack_a;
            t_node *start = current;
            ssize_t best_index = -1;
            ssize_t current_index = 0;
            ssize_t best_distance = list_size;
            
            if (current)
            {
                do {
                    if (current->value >= chunk_min && current->value <= chunk_max)
                    {
                        // Calculate rotational distance
                        ssize_t current_size = get_list_size(*stack_a);
                        ssize_t forward_dist = current_index;
                        ssize_t backward_dist = current_size - current_index;
                        ssize_t distance = (forward_dist <= backward_dist) ? forward_dist : backward_dist;
                        
                        if (distance < best_distance)
                        {
                            best_distance = distance;
                            best_index = current_index;
                        }
                    }
                    current = current->next;
                    current_index++;
                } while (current != start);
            }
            
            // If we found an element in the current chunk
            if (best_index != -1)
            {
                // Move it to the top
                ssize_t current_size = get_list_size(*stack_a);
                if (best_index <= current_size / 2)
                {
                    for (int j = 0; j < best_index; j++)
                        rotate_a(stack_a);
                }
                else
                {
                    for (int j = 0; j < current_size - best_index; j++)
                        reverse_rotate_a(stack_a);
                }
                
                // Push to stack B
                push_b(stack_a, stack_b);
                elements_pushed = 1;
            }
        }
    }
    
    // Push elements back to stack A in order
    while (*stack_b)
    {
        // Find maximum value in stack B
        ssize_t max_b = get_max_value(*stack_b);
        t_node *current = *stack_b;
        t_node *start = current;
        ssize_t max_index = 0;
        ssize_t current_index = 0;
        
        if (current)
        {
            do {
                if (current->value == max_b)
                {
                    max_index = current_index;
                    break;
                }
                current = current->next;
                current_index++;
            } while (current != start);
        }
        
        // Rotate B to bring max to top
        ssize_t size_b = get_list_size(*stack_b);
        if (max_index <= size_b / 2)
        {
            for (int j = 0; j < max_index; j++)
                rotate_b(stack_b);
        }
        else
        {
            for (int j = 0; j < size_b - max_index; j++)
                reverse_rotate_b(stack_b);
        }
        
        // Push back to A
        push_a(stack_a, stack_b);
    }
}

// void	chunk_sort(t_node **stack_a, t_node **stack_b)
// {
// 	ssize_t	list_size;
// 	ssize_t	min_value;
// 	ssize_t	max_value;
// 	ssize_t	chunk_size;
// 	int		chunk_count;

// 	list_size = get_list_size(*stack_a);
// 	min_value = get_min_value(stack_a);
// 	max_value = get_max_value(stack_a);
// 	if (list_size <= 20)
// 		chunk_count = 3
// }
