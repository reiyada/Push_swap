/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Turk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rei <rei@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 16:34:26 by ryada             #+#    #+#             */
/*   Updated: 2025/01/21 23:13:15 by rei              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
// Push 2 first numbers into B from A
// Find the cheapest number of A
// -> Operations to bring A on top + operations to bring target nod (smaller biggest in B) to the top B
// Push cheapest A to top B
// Do this untill A has only 3 ints
// Push back the top B to top A if the target (closest bigger) is ont he top A
// if not, put it on top A then push top B to top A
// push the smallest on top A

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
        if (forward_cost < reverse_cost) //if doing ra many times cost less than doing rra many times
            current->cost = forward_cost;
        else
            current->cost = reverse_cost;
        current = current->next;
    }
}

int ft_count_cost_b(t_stack *stack_b, int value_a)
{
    t_node *current;
    t_node *target_node;
    int forward_cost;
    int reverse_cost;

    target_node = NULL;
    if (!stack_b || stack_b->size == 0)
        return (0);
    if (value_a < stack_b->smallest->value)
        target_node = stack_b->smallest;
    else if (value_a > stack_b->biggest->value)
        target_node = stack_b->biggest;
    else
    {
        current = stack_b->top;
        while (current)
        {
            if (value_a > current->value && (!current->next || value_a < current->next->value))
            {
                target_node = current->next;
                break;
            }
            current = current->next;
        }
    }
    if (!target_node)
        target_node = stack_b->top;
    forward_cost = target_node->index;
    reverse_cost = stack_b->size - target_node->index;
    if (forward_cost < reverse_cost)
        return (forward_cost);
    else
        return (reverse_cost);
}


void ft_calculate_total_cost(t_stack *stack_a, t_stack *stack_b)
{
    t_node *current_a;
    int cost_a;
    int cost_b;
    if (!stack_a || !stack_b)
        return;
    current_a = stack_a->top;
    ft_count_cost_a(stack_a);
    while (current_a)
    {
        cost_a = current_a->cost;
        cost_b = ft_count_cost_b(stack_b, current_a->value);
        current_a->cost = cost_a + cost_b;
        // ft_printf("Node Value: %d, Cost_a: %d, Cost_b: %d, Total cost: %d\n",
        // current_a->value, cost_a, cost_b, current_a->cost); //delete this
        current_a = current_a->next;
    }
}

void ft_find_cheapest(t_stack *stack_a)
{
    int operations;
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


// t_stack *ft_turk(t_stack *stack_a, t_stack *stack_b, int argc, char **argv)
// {
//     pb(stack_b, stack_a);
//     pb(stack_b, stack_a);
//     stack_a = ft_find_cheapest(stack_a);//find the cheapest and put it on the top, return the stack
// }
