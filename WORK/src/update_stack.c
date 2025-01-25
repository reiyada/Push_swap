/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 15:43:20 by ryada             #+#    #+#             */
/*   Updated: 2025/01/25 16:56:30 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// typedef struct s_stack
// {
//     t_node *top;DONE
//     t_node *bottom;DONE
//     t_node *biggest;DONE
//     t_node *smallest;DONE
//     t_node *cheapest;
//     int size;DONE
// }   t_stack;

void ft_update_top_bottom(t_stack *stack)
{
    t_node *current;

    if (!stack || !stack->top)
    {
        stack->top = NULL;
        stack->bottom = NULL;
        return;
    }
    current = stack->top;
    while (current->next)
        current = current->next;
    stack->bottom = current;
}

void ft_update_biggest_smallest(t_stack *stack)
{
    t_node *current;

    if (!stack || !stack->top)
        return;
    current = stack->top;
    stack->biggest = current;
    stack->smallest = current;

    while (current)
    {
        if (current->value > stack->biggest->value)
            stack->biggest = current;
        if (current->value < stack->smallest->value)
            stack->smallest = current;
        current = current->next;
    }
}

void ft_update_size(t_stack *stack)
{
    int size;
    t_node *current;

    size = 0;
    current = stack->top;
    while (current)
    {
        size++;
        current = current->next;
    }
    stack->size = size;
}

void ft_update_cheapest(t_stack *stack_a)
{
    t_node *cheapest;
    t_node *current;
    
    if (!stack_a)
        return;
    current = stack_a->top;
    cheapest = current;
    while (current)
    {
        if (current->cost < cheapest->cost)
            cheapest = current;
        current = current->next;
    }
    stack_a->cheapest = cheapest;
}

void ft_update_stack(t_stack *stack_a, t_stack *stack_b)
{
    ft_update_top_bottom(stack_a);
    ft_update_biggest_smallest(stack_a);
    ft_update_size(stack_a);
    ft_update_cheapest(stack_a);

    ft_update_top_bottom(stack_b);
    ft_update_biggest_smallest(stack_b);
    ft_update_size(stack_b);
    ft_update_cheapest(stack_b);
}