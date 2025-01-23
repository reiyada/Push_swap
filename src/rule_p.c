/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rei <rei@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 15:35:32 by ryada             #+#    #+#             */
/*   Updated: 2025/01/23 19:52:31 by rei              ###   ########.fr       */
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
    if (!stack_a->bottom)
        stack_a->bottom = temp;
    stack_a->size++;
    ft_printf("pa\n");
    increment_operation_count();
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
    if (!stack_b->bottom)
        stack_b->bottom = temp;
    stack_b->size++;
    ft_printf("pb\n");
    increment_operation_count();
}