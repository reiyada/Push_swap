/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 15:35:32 by ryada             #+#    #+#             */
/*   Updated: 2025/02/03 18:30:50 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void ft_push(t_stack **stack_to, t_stack **stack_from)
{
    t_node *temp;
    if (!(*stack_from) || !(*stack_from)->top)
        return;
    temp = (*stack_from)->top;
    (*stack_from)->top = (*stack_from)->top->next;
    if (!(*stack_from)->top)
        (*stack_from)->bottom = NULL;
    temp->next = (*stack_to)->top;
    (*stack_to)->top = temp;
    if (!(*stack_to)->bottom)
        (*stack_to)->bottom = temp;
    ft_update_stack(*stack_to);
    ft_update_stack(*stack_from);
    increment_operation_count();
}

void pa(t_stack **stack_a, t_stack **stack_b)
{
    ft_push(stack_a, stack_b);
    ft_update_node(stack_a, stack_b);
    ft_printf("pa\n");
    ft_display_stack(*stack_a, *stack_b);
}

void pb(t_stack **stack_b, t_stack **stack_a)
{
    ft_push(stack_b, stack_a);
    ft_update_node(stack_a, stack_b);
    ft_printf("pb\n");
    ft_display_stack(*stack_a, *stack_b);
}