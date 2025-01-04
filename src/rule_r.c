/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_r.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 15:56:58 by ryada             #+#    #+#             */
/*   Updated: 2025/01/04 17:48:21 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//1 2 3 4 5 -> 2 3 4 5 1
void ra(t_stack *stack_a)
{
    t_node *temp;

    if (stack_a->size < 2)
        return;
    temp = stack_a->top;
    stack_a->top = stack_a->top->next;
    stack_a->bottom->next = temp;
    stack_a->bottom = temp;
    temp->next = NULL; // same as stack_a->bottom->next = NULL but this is prefered
}

void rb(t_stack *stack_b)
{
    t_node *temp;

    if (stack_b->size < 2)
        return;
    temp = stack_b->top;
    stack_b->top = stack_b->top->next;
    stack_b->bottom->next = temp;
    stack_b->bottom = temp;
    temp->next = NULL;
}

void rr(t_stack *stack_a, t_stack *stack_b)
{
    ra(stack_a);
    rb(stack_b);
}

//1 2 3 4 5 -> 5 1 2 3 4
void rra(t_stack *stack_a)
{
    t_node *current;
    t_node *prev;

    if (stack_a->size < 2)
        return;
    current = stack_a->top;
    prev = NULL;
    while (current->next != NULL) // to set prev as the one before the bottom
    {
        prev = current;
        current = current->next;
    }
    prev->next = NULL; //the bottom
    current->next = stack_a->top; //connect the top of stack_a to the bottom
    stack_a->top = current; //update the new top
    stack_a->bottom = prev; //update the bttom
}

void rrb(t_stack *stack_b)
{
    t_node *current;
    t_node *prev;

    if (stack_b->size < 2)
        return;
    current = stack_b->top;
    prev = NULL;
    while (current->next != NULL) // to set prev as the one before the bottom
    {
        prev = current;
        current = current->next;
    }
    prev->next = NULL; //the bottom
    current->next = stack_b->top; //connect the top of stack_b to the bottom
    stack_b->top = current; //update the new top
    stack_b->bottom = prev; //update the bttom
}

void rrr(t_stack *stack_a, t_stack *stack_b)
{
    ra(stack_a);
    rb(stack_b);
}
