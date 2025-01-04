/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 15:35:32 by ryada             #+#    #+#             */
/*   Updated: 2025/01/04 17:48:22 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void pa(t_stack *stack_a, t_stack *stack_b)
{
    t_node *temp;
    if (!stack_b->top)
        return;
    temp = stack_b->top;
    stack_b->top = stack_b->top->next;
    if(!stack_b->top)
        stack_b->bottom = NULL;
    stack_b->size--;
    temp->next = stack_a->top;
    stack_a->top = temp;
    stack_a->size++;
}

void pb(t_stack *stack_b, t_stack *stack_a)
{
    t_node *temp;
    if (!stack_a->top)
        return;
    temp = stack_a->top;
    stack_a->top = stack_a->top->next;
    if(!stack_a->top)
        stack_a->bottom = NULL;
    stack_a->size--;
    temp->next = stack_b->top;
    stack_b->top = temp;
    stack_b->size++;
}