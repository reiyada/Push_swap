/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 15:19:55 by ryada             #+#    #+#             */
/*   Updated: 2025/01/25 17:14:16 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// operations.c
static int g_operation_count = 0;
void increment_operation_count(void)
{
    g_operation_count++;
}

int get_operation_count(void)
{
    return g_operation_count;
}

void reset_operation_count(void)
{
    g_operation_count = 0;
}


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
    increment_operation_count();
    ft_update_stack(stack_a, stack_b);
    ft_update_node(stack_a, stack_b);
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
    increment_operation_count();
    ft_update_stack(stack_a, stack_b);
    ft_update_node(stack_a, stack_b);
}

void ss(t_stack *stack_a, t_stack *stack_b)
{
    sa(stack_a, true);
    sb(stack_b, true);
    ft_printf("ss\n");
}