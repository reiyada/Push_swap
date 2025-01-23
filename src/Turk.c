/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Turk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 16:34:26 by ryada             #+#    #+#             */
/*   Updated: 2025/01/23 14:05:26 by ryada            ###   ########.fr       */
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
        if (forward_cost < reverse_cost) //if doing ra many times cost less than doing rra many times
            current->cost = forward_cost;
        else
            current->cost = reverse_cost;
        current = current->next;
    }
}

void ft_find_target_node(t_stack *stack_a, t_stack *stack_b)
{
    t_node *current_a;
    t_node *current_b;
    t_node *best_target;

    if (!stack_a || !stack_b || stack_b->size == 0)
        return;
    current_a = stack_a->top;
    //printf("TOP A%d\n", current_a->value);
    ft_assign_biggest_smallest(stack_b);
    while (current_a)
    {
        if (current_a->value < stack_b->smallest->value)
        {
            // printf("Smaller than all \n");
            best_target = stack_b->smallest;
        }
        else if (current_a->value > stack_b->biggest->value)
        {
            // printf("bigger than all\n");
            best_target = stack_b->biggest;
        }
        else
        {
            // printf("in between\n");
            current_b = stack_b->top;
            while (current_b)
            {
                if (current_a->value > current_b->value &&
                    (!current_b->next || current_a->value < current_b->next->value))
                {
                    best_target = current_b;
                    break;
                }
                current_b = current_b->next;
            }
        }
        if (!best_target)
            best_target = stack_b->top;
        current_a->target = best_target;
        // printf("Target of %d is %d\n", current_a->value, current_a->target->value);
        current_a = current_a->next;
    }
}



// void ft_find_target_node(t_stack *stack_a, t_stack *stack_b)
// {
//     t_node *current_a;
//     t_node *current_b;

//     if (!stack_a || !stack_b || stack_b->size == 0)
//         return ;
//     current_a = stack_a->top;
//     while (current_a)
//     {
//         if (current_a->value < stack_b->smallest->value)
//             current_a->target = stack_b->smallest;
//         else if (current_a->value > stack_b->biggest->value)
//             current_a->target = stack_b->biggest;
//         else
//         {
//             current_b = stack_b->top;
//             while (current_b)
//             {
//                 if (current_a->value > current_b->value && (!current_b->next || current_a->value < current_b->next->value))
//                 {
//                     current_a->target = current_b->next;
//                     break;
//                 }
//                 current_b = current_b->next;
//             }
//         }
//         if (!current_a->target)
//             current_a->target = stack_b->top;
//         current_a = current_a->next;
//     }
// }

//maybe it will be better if I make another function to find the target
// int ft_count_cost_b(t_stack *stack_b, int value_a)
// {
//     t_node *current;
//     int forward_cost;
//     int reverse_cost;

//     if (!stack_b || stack_b->size == 0)
//         return (0);
//     if (value_a < stack_b->smallest->value)
//         stack_b->target = stack_b->smallest;
//     else if (value_a > stack_b->biggest->value)
//         stack_b->target = stack_b->biggest;
//     else
//     {
//         current = stack_b->top;
//         while (current)
//         {
//             if (value_a > current->value && (!current->next || value_a < current->next->value))
//             {
//                 stack_b->target = current->next;
//                 break;
//             }
//             current = current->next;
//         }
//     }
//     if (!stack_b->target)
//         stack_b->target = stack_b->top;
//     forward_cost = stack_b->target->index;
//     reverse_cost = stack_b->size - stack_b->target->index;
//     if (forward_cost < reverse_cost)
//         return (forward_cost);
//     else
//         return (reverse_cost);
// }

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
        ft_find_target_node(stack_a, stack_b);
        cost_b = ft_count_cost_b(current_a, stack_b);
        current_a->cost = cost_a + cost_b;
        // ft_printf("Node Value: %d, Cost_a: %d, Cost_b: %d, Total cost: %d\n",
        // current_a->value, cost_a, cost_b, current_a->cost); //delete this
        // ft_printf("Node: %d, Cost: %d, Target: %d\n",
        //     current_a->value,
        //     current_a->cost,
        //     current_a->target ? current_a->target->value : -1);//DELETE
        current_a = current_a->next;
    }
}

void ft_find_cheapest(t_stack *stack_a)
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

// void ft_target_to_top(t_stack *stack_b, t_node *target)
// {
//     int forward_cost;
//     int reverse_cost;

//     forward_cost = target->index;
//     reverse_cost = stack_b->size - target->index;
//     if (forward_cost < reverse_cost)
//     {
//         while (forward_cost--)
//             rb(stack_b);
//     }
//     else
//     {
//         while (reverse_cost--)
//             rrb(stack_b);
//     }
// }

void ft_target_to_top(t_stack *stack_b, t_node *target)
{
    if (!stack_b || !target)
    {
        ft_printf("Error: Invalid stack or target.\n");
        return;
    }

    int forward_cost = target->index;
    int reverse_cost = stack_b->size - target->index;

    if (forward_cost < reverse_cost)
    {
        while (forward_cost--)
            rb(stack_b, false);
    }
    else
    {
        while (reverse_cost--)
            rrb(stack_b, false);
    }
}


void ft_cheapest_to_top(t_stack *stack_a)
{
    int forward_cost;
    int reverse_cost;

    forward_cost = stack_a->cheapest->index;
    reverse_cost = stack_a->size - stack_a->cheapest->index;
    if (forward_cost < reverse_cost)
    {
        while (forward_cost--)
            rb(stack_a, false);
    }
    else
    {
        while (reverse_cost--)
            rrb(stack_a, false);
    }
}

void ft_sort_stack_b(t_stack *stack_b)
{
    t_node *current;
    int sorted;

    sorted = 0;
    if (!stack_b || stack_b->size < 2)
        return;
    while (!sorted)
    {
        current = stack_b->top;
        sorted = 1;
        while (current && current->next)
        {
            if (current->value < current->next->value)
            {
                rb(stack_b, false);
                sorted = 0;
                break;
            }
            current = current->next;
        }
    }
}

void ft_sort_stack_a(t_stack *stack_a, t_stack *stack_b)
{
    while (stack_a->top < stack_b->top)
        ra(stack_a, false);
}

int ft_is_sorted(t_stack *stack_a)
{
    t_node *current;

    if (!stack_a || !stack_a->top) 
        return (1);
    current = stack_a->top;
    while (current->next)
    {
        if (current->value > current->next->value)
            return (0);
        current = current->next;
    }
    return (1);
}

void ft_rotate_to_sorted(t_stack *stack_a)
{
    int smallest_index;

    if (!stack_a || stack_a->size < 2)
        return;

    // Find the index of the smallest node
    ft_assign_biggest_smallest(stack_a);
    smallest_index = stack_a->smallest->index;

    // Rotate or reverse rotate to bring smallest to the top
    if (smallest_index <= stack_a->size / 2)
    {
        while (stack_a->top != stack_a->smallest)
            ra(stack_a, false);
    }
    else
    {
        while (stack_a->top != stack_a->smallest)
            rra(stack_a, false);
    }
}


// t_stack *ft_turk(t_stack *stack_a, t_stack *stack_b, int argc, char **argv)
// {
//     pb(stack_b, stack_a);
//     pb(stack_b, stack_a);
//     stack_a = ft_find_cheapest(stack_a);//find the cheapest and put it on the top, return the stack
// }
