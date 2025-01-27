/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_r.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rei <rei@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 15:56:58 by ryada             #+#    #+#             */
/*   Updated: 2025/01/27 00:03:17 by rei              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void ft_top_to_bottom(t_stack **stack_move)
{
    t_node *temp;

    if (!stack_move || !(*stack_move) || (*stack_move)->size < 2)
        return;

    temp = (*stack_move)->top; // Save the current top
    (*stack_move)->top = (*stack_move)->top->next; // Move top to the next node

    // If there's only one node, update bottom to NULL
    if (!(*stack_move)->top)
        (*stack_move)->bottom = NULL;
    else
        (*stack_move)->bottom->next = temp; // Attach the old top to the bottom

    (*stack_move)->bottom = temp; // Update the bottom pointer
    temp->next = NULL;            // Ensure the new bottom's next is NULL
}


// void ft_top_to_bottom(t_stack *stack_move)
// {
//     t_node *temp;

//     if (stack_move->size < 2)
//         return;
//     temp = stack_move->top;
//     stack_move->top = stack_move->top->next;
//     stack_move->bottom->next = temp;
//     stack_move->bottom = temp;
//     temp->next = NULL;
// }

void ft_bottom_to_top(t_stack **stack_move)
{
    t_node *prev = NULL;
    t_node *last;

    if (!stack_move || !(*stack_move) || (*stack_move)->size < 2)
        return;

    last = (*stack_move)->top;

    // Traverse to the last node while keeping track of the previous node
    while (last->next)
    {
        prev = last;
        last = last->next;
    }

    // Safety check
    if (!prev || !last)
        return;

    // Adjust pointers to move the last node to the top
    prev->next = NULL;            // Disconnect the last node
    last->next = (*stack_move)->top; // Point last node to the current top
    (*stack_move)->top = last;    // Update top pointer
    (*stack_move)->bottom = prev; // Update bottom pointer
}


// void ft_bottom_to_top(t_stack *stack_move)
// {
//     t_node *prev = NULL;
//     t_node *last = stack_move->top;

//     if (!stack_move || stack_move->size < 2) // Ensure stack is valid and has at least two nodes
//         return;

//     // Traverse to the last node
//     while (last && last->next)
//     {
//         prev = last;
//         last = last->next;
//     }

//     // Safety check: Ensure we have valid nodes
//     if (!prev || !last)
//     {
//         //printf("ft_bottom_to_top: Error - Invalid state during traversal.\n");
//         return;
//     }

//     // Adjust pointers to move the bottom node to the top
//     prev->next = NULL;         // Disconnect the last node
//     last->next = stack_move->top; // Move the last node to the top
//     stack_move->top = last;    // Update top pointer
//     stack_move->bottom = prev; // Update bottom pointer
//     // Debugging
//     // printf("After ft_bottom_to_top: Top=%d, Bottom=%d\n",
//     //        stack_move->top ? stack_move->top->value : -1,
//     //        stack_move->bottom ? stack_move->bottom->value : -1);
// }


void ra(t_stack **stack_a, t_stack **stack_b, bool print)
{
    ft_top_to_bottom(stack_a);
    ft_update_node(stack_a, stack_b);
    if (print == false)
    {
        ft_printf("ra\n");
        increment_operation_count();
    }
}

void rb(t_stack **stack_b, t_stack **stack_a, bool print)
{
    ft_top_to_bottom(stack_b);
    ft_update_node(stack_b, stack_a);
    if (print == false)
    {
        ft_printf("rb\n");
        increment_operation_count();
    }
}

void rr(t_stack **stack_a, t_stack **stack_b)
{
    ra(stack_a, stack_b, true);
    rb(stack_b, stack_a, true);
    increment_operation_count();
    ft_printf("rr\n");
}

// void ft_bottom_to_top(t_stack *stack_move)
// {
//     t_node *prev;
//     t_node *last;

//     if (stack_move->size < 2)
//         return;
//     prev = NULL;
//     last = stack_move->top;
//     while (last->next)
//     {
//         prev = last;
//         last = last->next;
//     }
//     prev->next = NULL;
//     last->next = stack_move->top; 
//     stack_move->top = last;
//     stack_move->bottom = prev;
//     ft_update_stack(stack_move);
// }

// void rra(t_stack **stack_a, t_stack **stack_b, bool print)
// {
//     ft_bottom_to_top(*stack_a);
//     ft_top_to_bottom(*stack_b);
//     ft_update_node(stack_a, stack_b);
//     if (print == false)
//     {
//         ft_printf("rra\n");
//         increment_operation_count();
//     }
// }

void rra(t_stack **stack_a, t_stack **stack_b, bool print)
{
    ft_bottom_to_top(stack_a);
    ft_update_node(stack_a, stack_b);

    if (!print)
    {
        ft_printf("rra\n");
        increment_operation_count();
    }

    // Debugging
    printf("After rra:\n");
    ft_display_stack(*stack_a, *stack_b);
}


void rrb(t_stack **stack_b, t_stack **stack_a,bool print)
{
    ft_bottom_to_top(stack_b);
    ft_update_node(stack_b, stack_a);
    if (print == false)
    {
        ft_printf("rrb\n");
        increment_operation_count();
    }
}

void rrr(t_stack **stack_a, t_stack **stack_b)
{
    rra(stack_a, stack_b, true);
    rrb(stack_b, stack_a, true);
    increment_operation_count();
    ft_printf("rrr\n");
}
