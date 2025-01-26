/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rei <rei@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 15:35:32 by ryada             #+#    #+#             */
/*   Updated: 2025/01/26 00:53:22 by rei              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void ft_push(t_stack **stack_to, t_stack **stack_from)
{
    t_node *temp;
    if (!(*stack_from)->top)
        return;
    temp = (*stack_from)->top;
    (*stack_from)->top = (*stack_from)->top->next;
    temp->next = (*stack_to)->top;
    (*stack_to)->top = temp;
    increment_operation_count();
    ft_update_stack(*stack_to);
    ft_update_stack(*stack_from);
    ft_update_node((*stack_to), stack_from);
}

void pa(t_stack **stack_a, t_stack **stack_b)
{
    ft_push(stack_a, stack_b);
    ft_printf("pa\n");
}

void pb(t_stack **stack_b, t_stack **stack_a)
{
    ft_push(stack_b, stack_a);
    ft_printf("pb\n");
}