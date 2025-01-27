/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rei <rei@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 16:34:26 by ryada             #+#    #+#             */
/*   Updated: 2025/01/27 00:15:29 by rei              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
// ---------------------------------------------------------
// typedef struct s_node
// {
//     struct s_node *next;
//     int value;
//     int cost;
//     int index;
// }   t_node;

// typedef struct s_stack
// {
//     t_node *top;
//     t_node *bottom;
//     t_node *biggest;
//     t_node *smallest;
//     t_node *cheapest;
//     t_node *target;
//     int size;
// }   t_stack;
// ------------------------------------------------------------


void ft_count_cost_a(t_stack *stack_a)
{
    t_node *current;
    int forward_cost; //ra
    int reverse_cost; //rra

    if (!stack_a || stack_a->size <= 1)
        return;
    current = stack_a->top;
    while (current)
    {
        forward_cost = current->index;
        reverse_cost = stack_a->size - current->index;
        current->cost = (forward_cost < reverse_cost) ? forward_cost : reverse_cost;
        current = current->next;
    }
}

int ft_count_cost_b(t_node *current_a, t_stack *stack_b)
{
    t_node *target_node;
    int forward_cost;
    int reverse_cost;

    if (!stack_b || stack_b->size == 0 || !current_a->target)
        return (0);
    target_node = current_a->target;
    forward_cost = target_node->index;
    reverse_cost = stack_b->size - target_node->index;
    return ((forward_cost < reverse_cost) ? forward_cost : reverse_cost);
}

void ft_calculate_total_cost(t_stack *stack_a, t_stack *stack_b)
{
    t_node *current_a;
    int cost_a;
    int cost_b;

    if (!stack_a || !stack_b)
        return;
    ft_count_cost_a(stack_a);
    current_a = stack_a->top;
    while (current_a)
    {
        //printf("[%d]%d's target:[%d]%d\n", current_a->index, current_a->value, current_a->target->index, current_a->target->value);
        cost_a = current_a->cost;
        cost_b = ft_count_cost_b(current_a, stack_b);
        current_a->cost = cost_a + cost_b;
        current_a = current_a->next;
    }
}

void ft_find_cheapest(t_stack *stack_a, t_stack *stack_b)
{
    t_node *cheapest;
    t_node *current;
    
    if (!stack_a)
        return;
    ft_calculate_total_cost(stack_a, stack_b);
    current = stack_a->top;
    cheapest = current;
    while (current)
    {
        if (current->cost <= cheapest->cost)
            cheapest = current;
        current = current->next;
    }
    stack_a->cheapest = cheapest;
}

void ft_cheapest_to_top(t_stack **stack_a, t_stack **stack_b)
{
    int forward_cost;
    int reverse_cost;

    if (!(*stack_a) || !(*stack_a)->cheapest)
        return;
    forward_cost = (*stack_a)->cheapest->index;
    reverse_cost = (*stack_a)->size - (*stack_a)->cheapest->index;

    if (forward_cost < reverse_cost)
    {
        while (forward_cost--)
            ra(stack_a, stack_b, false); // Pass double pointers
    }
    else
    {
        while (reverse_cost--)
            rra(stack_a, stack_b, false); // Pass double pointers
    }
}
