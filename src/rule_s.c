/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 15:19:55 by ryada             #+#    #+#             */
/*   Updated: 2025/01/23 14:07:21 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//1 2 3 4 5 -> 2 1 3 4 5
void sa(t_stack *stack_a, bool print)
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
    if (print == false)
        ft_printf("sa\n");
}
//1 2 3 4 5 -> 2 1 3 4 5
void sb(t_stack *stack_b, bool print)
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
    if (print == false)
        ft_printf("sb\n");
}

void ss(t_stack *stack_a, t_stack *stack_b)
{
    sa(stack_a, true);
    sb(stack_b, true);
    ft_printf("ss\n");
}