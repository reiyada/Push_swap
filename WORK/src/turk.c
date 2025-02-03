/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 16:34:26 by ryada             #+#    #+#             */
/*   Updated: 2025/02/03 11:26:07 by ryada            ###   ########.fr       */
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


// void ft_count_cost_a(t_stack *stack_a)
// {
//     t_node *current;
//     int forward_cost; //ra
//     int reverse_cost; //rra

//     if (!stack_a || stack_a->size <= 1)
//         return;
//     current = stack_a->top;
//     while (current)
//     {
//         forward_cost = current->index;
//         reverse_cost = stack_a->size - current->index;
//         current->cost = (forward_cost < reverse_cost) ? forward_cost : reverse_cost;
//         current = current->next;
//     }
// }

// int ft_count_cost_b(t_node *current_a, t_stack *stack_b)
// {
//     t_node *target_node;
//     int forward_cost;
//     int reverse_cost;

//     if (!stack_b || stack_b->size == 0 || !current_a->target)
//         return (0);
//     target_node = current_a->target;
//     forward_cost = target_node->index;
//     reverse_cost = stack_b->size - target_node->index;
//     return ((forward_cost < reverse_cost) ? forward_cost : reverse_cost);
// }

// void ft_calculate_total_cost(t_stack *stack_a, t_stack *stack_b)
// {
//     t_node *current_a;
//     int cost_a;
//     int cost_b;

//     if (!stack_a || !stack_b)
//         return;
//     ft_count_cost_a(stack_a);
//     current_a = stack_a->top;
//     while (current_a)
//     {
//         //printf("[%d]%d's target:[%d]%d\n", current_a->index, current_a->value, current_a->target->index, current_a->target->value);
//         cost_a = current_a->cost;
//         cost_b = ft_count_cost_b(current_a, stack_b);
//         current_a->cost = cost_a + cost_b;
//         current_a = current_a->next;
//     }
// }

// void ft_find_cheapest(t_stack *stack_a, t_stack *stack_b)
// {
//     t_node *cheapest;
//     t_node *current;
    
//     if (!stack_a)
//         return;
//     ft_calculate_total_cost(stack_a, stack_b);
//     current = stack_a->top;
//     cheapest = current;
//     while (current)
//     {
//         if (current->cost <= cheapest->cost)
//             cheapest = current;
//         current = current->next;
//     }
//     stack_a->cheapest = cheapest;
// }
//-------------------------------------------------------------------------


void ft_count_cost_a(t_stack **stack_a)
{
    t_node *current;

    if (!stack_a || (*stack_a)->size <= 1)
        return;
    current = (*stack_a)->top;
    while (current)
    {
        if(current->mid)
            current->cost = current->index;
        else
            current->cost = (*stack_a)->size - current->index;
        current = current->next;
    }
}

int ft_count_cost_b(t_node **current_a, t_stack **stack_b)
{
    t_node *target_node;

    if (!stack_b || (*stack_b)->size == 0 || !(*current_a)->target)
        return (0);
    target_node = (*current_a)->target;
    if(target_node->mid)
        return(target_node->index);
    else
        return ((*stack_b)->size - target_node->index);
}

void ft_calculate_total_cost(t_stack **stack_a, t_stack **stack_b)
{
    t_node *current_a;
    int cost_a;
    int cost_b;

    if (!stack_a || !stack_b)
        return;
    ft_count_cost_a(stack_a);
    current_a = (*stack_a)->top;
    while (current_a)
    {
        //printf("[%d]%d's target:[%d]%d\n", current_a->index, current_a->value, current_a->target->index, current_a->target->value);
        cost_a = current_a->cost;
        cost_b = ft_count_cost_b(&current_a, stack_b);
        //printf("cost of A: %d cost of B: %d\n", current_a->cost, cost_b);
        current_a->cost = cost_a + cost_b;
        current_a = current_a->next;
    }
}

void ft_find_cheapest(t_stack **stack_a, t_stack **stack_b)
{
    t_node *cheapest;
    t_node *current;

    ft_calculate_total_cost(stack_a, stack_b);
    current = (*stack_a)->top;
    cheapest = current;
    while (current)
    {
        if (current->cost < cheapest->cost)
            cheapest = current;
        current = current->next;
    }
    (*stack_a)->cheapest = cheapest;
}


// bool ft_cheapest_to_top(t_stack **stack_a, t_stack **stack_b, bool extra)
// {
//     int forward_cost;
//     int reverse_cost;
//     bool operation;

//     if (!(*stack_a) || !(*stack_a)->cheapest)
//         return (true);
//     ft_find_cheapest(stack_a, stack_b);
//     //printf("Cheapest node in A: %d\n", (*stack_a)->cheapest->value);
//     forward_cost = (*stack_a)->cheapest->index;
//     reverse_cost = (*stack_a)->size - (*stack_a)->cheapest->index;

//     if (forward_cost < reverse_cost)
//     {
//         operation = true;
//         if (extra == true)
//         {
//             while (forward_cost--)
//             ra(stack_a, stack_b, false); // Pass double pointers
//         }
//     }
//     else
//     {
//         operation = false;
//         if (extra == true)
//         {
//             while (reverse_cost--)
//             rra(stack_a, stack_b, false); // Pass double pointers
//         }
//     }
//     (*stack_a)->cheapest = NULL;
//     printf("a\n");
//     return(operation);
// }

// bool ft_target_to_top(t_stack **stack_a, t_stack **stack_b, bool extra)
// {
//     int forward_cost;
//     int reverse_cost;
//     t_node *target;
//     bool operation;

//     target = (*stack_a)->cheapest->target;
//     if (target == (*stack_b)->top)
//         return (true);
//     forward_cost = target->index;
//     reverse_cost = (*stack_b)->size - target->index;
//     if (forward_cost < reverse_cost)
//     {
//         operation = true;
//         if (extra == true)
//         {
//         while (forward_cost--)
//             rb(stack_b, stack_a, false); // Pass double pointers
//         }
        
//     }
//     else
//     {
//         operation = false;
//         if (extra == true)
//         {
//             while (reverse_cost--)
//             rrb(stack_b, stack_a, false); // Pass double pointers
//         }
//     }
//     printf("b\n");
//     return (operation);
// }

// void ft_before_pb(t_stack **stack_a, t_stack **stack_b)
// {
//     printf("1\n");
//     bool operation_a;
//     bool operation_b;

//     operation_a = ft_cheapest_to_top(stack_a, stack_b, false);
//     printf("2\n");
//     operation_b = ft_target_to_top(stack_a, stack_b, false);
    
//     if (operation_a == true && operation_b == true)
//     {
//         while (((*stack_a)->top != (*stack_a)->cheapest) && (*stack_b)->top != (*stack_a)->cheapest->target)
//             rr(stack_a, stack_b);
//         while (((*stack_a)->top != (*stack_a)->cheapest) && (*stack_b)->top == (*stack_a)->cheapest->target)
//             ra(stack_a, stack_b, false);
//         while (((*stack_a)->top == (*stack_a)->cheapest) && (*stack_b)->top != (*stack_a)->cheapest->target)
//             rb(stack_b, stack_a, false);
//     }
//     else if (operation_a == false && operation_b == false)
//     {
//         while (((*stack_a)->top != (*stack_a)->cheapest) && (*stack_b)->top != (*stack_a)->cheapest->target)
//             rrr(stack_a, stack_b);
//         while (((*stack_a)->top != (*stack_a)->cheapest) && (*stack_b)->top == (*stack_a)->cheapest->target)
//             rra(stack_a, stack_b, false);
//         while (((*stack_a)->top == (*stack_a)->cheapest) && (*stack_b)->top != (*stack_a)->cheapest->target)
//             rrb(stack_b, stack_a, false);
//     }
//     else
//     {
//         ft_cheapest_to_top(stack_a, stack_b, true);
//         ft_target_to_top(stack_a, stack_b, true);
//     }
// }

void ft_before_pb(t_stack **stack_a, t_stack **stack_b)
{
    t_node *cheapest_in_a;
    t_node *target_in_b;

    ft_find_cheapest(stack_a, stack_b);
    cheapest_in_a = (*stack_a)->cheapest;
    target_in_b = (*stack_a)->cheapest->target;
    if (cheapest_in_a->index != 0 || target_in_b->index != 0)
    {
        //both r
        if (cheapest_in_a->mid && target_in_b->mid)
        {
            while (cheapest_in_a->index > 0 && target_in_b->index > 0)
                rr(stack_a, stack_b);
            while (cheapest_in_a->index > 0 && target_in_b->index == 0)
                ra(stack_a, stack_b, false);
            while (target_in_b->index > 0 && cheapest_in_a->index == 0)
                rb(stack_b, stack_a, false);
        }
        //both rr
        else if (!(cheapest_in_a->mid) && !(target_in_b->mid))
        {
            while (cheapest_in_a->index > 0 && target_in_b->index > 0)
                rrr(stack_a, stack_b);
            while (cheapest_in_a->index > 0 && target_in_b->index == 0)
                rra(stack_a, stack_b, false);
            while (target_in_b->index > 0 && cheapest_in_a->index == 0)
                rrb(stack_b, stack_a, false);
        }
        else
        {
            while ((cheapest_in_a->mid) && cheapest_in_a->index > 0 && target_in_b->index == 0)
                ra(stack_a, stack_b, false);
            while ((target_in_b->mid) && target_in_b->index > 0 && cheapest_in_a->index == 0)
                rb(stack_b, stack_a, false);
            while (!(cheapest_in_a->mid)&& cheapest_in_a->index > 0 && target_in_b->index == 0)
                rra(stack_a, stack_b, false);
            while (!(target_in_b->mid) && target_in_b->index > 0 && cheapest_in_a->index == 0)
                rrb(stack_b, stack_a, false);
        }
    }
}
