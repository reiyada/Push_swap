/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_r.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 15:56:58 by ryada             #+#    #+#             */
/*   Updated: 2025/01/25 17:13:59 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


void ft_top_to_bottom(t_stack *stack)
{
    t_node *temp;

    if (stack->size < 2)
        return;
    temp = stack->top;
    stack->top = stack->top->next;
    stack->bottom->next = temp;
    stack->bottom = temp;
    temp->next = NULL;
    increment_operation_count();
    ft_update_stack(stack_a, stack_b);
    ft_update_node(stack_a, stack_b);
}

//1 2 3 4 5 -> 2 3 4 5 1
void ra(t_stack *stack_a, bool print)
{
    ft_top_to_bottom(stack_a);// same as stack_a->bottom->next = NULL but this is prefered
    if (print == false)
        ft_printf("ra\n");
}

void rb(t_stack *stack_b, bool print)
{
    ft_top_to_bottom(stack_b);
    if (print == false)
        ft_printf("rb\n");
}

void rr(t_stack *stack_a, t_stack *stack_b)
{
    ra(stack_a, true);
    rb(stack_b, true);
    ft_printf("rr\n");
}

//1 2 3 4 5 -> 5 1 2 3 4
// void rra(t_stack *stack_a, bool print)
// {
//     t_node *current;
//     t_node *prev;

//     if (stack_a->size < 2)
//         return;
//     current = stack_a->top;
//     prev = NULL;
//     while (current->next != NULL) // to set prev as the one before the bottom
//     {
//         prev = current;
//         current = current->next;
//     }
//     prev->next = NULL; //the bottom
//     current->next = stack_a->top; //connect the top of stack_a to the bottom
//     stack_a->top = current; //update the new top
//     stack_a->bottom = prev; //update the bttom
//     if (print == false)
//         ft_printf("rra\n");
// }

void rra(t_stack *stack_a, bool print)
{
    t_node *current;

    if (stack_a->size < 2)
        return;
    current = stack_a->top;
    while (current != stack_a->bottom)
        ra(stack_a, true);
    if (print == false)
        ft_printf("rra\n");
    ft_update_stack(stack_a, stack_b);
    ft_update_node(stack_a, stack_b);
}

// void rrb(t_stack *stack_b, bool print)
// {
//     t_node *current;
//     t_node *prev;

//     if (stack_b->size < 2)
//         return;
//     current = stack_b->top;
//     prev = NULL;
//     while (current->next != NULL) // to set prev as the one before the bottom
//     {
//         prev = current;
//         current = current->next;
//     }
//     prev->next = NULL; //the bottom
//     current->next = stack_b->top; //connect the top of stack_b to the bottom
//     stack_b->top = current; //update the new top
//     stack_b->bottom = prev; //update the bttom
//     if (print == false)
//         ft_printf("rrb\n");
// }

void rrb(t_stack *stack_b, bool print)
{
    t_node *current;

    if (stack_b->size < 2)
        return;
    current = stack_b->top;
    while (current != stack_b->bottom)
        ra(stack_b, true);
    if (print == false)
        ft_printf("rrb\n");
    ft_update_stack(stack_a, stack_b);
    ft_update_node(stack_a, stack_b);
}

void rrr(t_stack *stack_a, t_stack *stack_b)
{
    rra(stack_a, true);
    rrb(stack_b, true);
    ft_printf("rrr\n");
}
