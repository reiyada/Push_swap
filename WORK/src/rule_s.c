/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rei <rei@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 15:19:55 by ryada             #+#    #+#             */
/*   Updated: 2025/01/26 21:23:25 by rei              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//1 2 3 4 5 -> 2 1 3 4 5
void ft_swap(t_stack **stack_swap, t_stack **stack_stay)
{
    int temp;
    t_node *first;
    t_node *second;
    if ((*stack_swap)->size < 2)
        return;
    first = (*stack_swap)->top;
    second = (*stack_swap)->top->next;
    temp = first->value;
    first->value = second->value;
    second->value = temp;
    ft_update_stack(*stack_swap);
    ft_update_stack(*stack_stay);
    ft_update_node(stack_swap, stack_stay);
}

void sa(t_stack **stack_a, t_stack **stack_b, bool print)
{
    ft_swap(stack_a, stack_b);
    if (print == false)
    {
        ft_printf("sa\n");
        increment_operation_count();
    }
}
//1 2 3 4 5 -> 2 1 3 4 5
void sb(t_stack **stack_b, t_stack **stack_a, bool print)
{
    ft_swap(stack_b, stack_a);
    if (print == false)
    {
        ft_printf("sb\n");
        increment_operation_count();
    }
}

void ss(t_stack **stack_a, t_stack **stack_b)
{
    sa(stack_a, stack_b, true);
    sb(stack_b, stack_a, true);
    increment_operation_count();
    ft_printf("ss\n");
}