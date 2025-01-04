/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 15:19:55 by ryada             #+#    #+#             */
/*   Updated: 2025/01/04 17:48:20 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void sa(t_stack *stack_a)
{
    int temp;
    t_node *first;
    t_node *second;
    if (stack_a->size < 2)
        return;
    first = stack_a->top;
    second = stack_a->top->next;
    temp = first->value;
    first->value = second->value;
    second->value = temp;
}

void sb(t_stack *stack_b)
{
    int temp;
    t_node *first;
    t_node *second;
    if (stack_b->size < 2)
        return;
    first = stack_b->top;
    second = stack_b->top->next;
    temp = first->value;
    first->value = second->value;
    second->value = temp;
}

void ss(t_stack *stack_a, t_stack *stack_b)
{
    sa(stack_a);
    sb(stack_b);
}