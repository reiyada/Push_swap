/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_r.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 15:56:58 by ryada             #+#    #+#             */
/*   Updated: 2025/02/03 16:48:31 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void ft_top_to_bottom(t_stack **stack_move)
{
    t_node *temp;

    if (!stack_move || !(*stack_move) || (*stack_move)->size < 2)
        return;

    temp = (*stack_move)->top;
    (*stack_move)->top = (*stack_move)->top->next;
    if (!(*stack_move)->top)
        (*stack_move)->bottom = NULL;
    else
        (*stack_move)->bottom->next = temp;

    (*stack_move)->bottom = temp;
    temp->next = NULL;
}

void ft_bottom_to_top(t_stack **stack_move)
{
    t_node *prev = NULL;
    t_node *last;

    if (!stack_move || !(*stack_move) || (*stack_move)->size < 2)
        return;

    last = (*stack_move)->top;

    while (last->next)
    {
        prev = last;
        last = last->next;
    }
    if (!prev || !last)
        return;
    prev->next = NULL;
    last->next = (*stack_move)->top;
    (*stack_move)->top = last;
    (*stack_move)->bottom = prev;
}

void ra(t_stack **stack_a, t_stack **stack_b, bool print)
{
    ft_top_to_bottom(stack_a);
    ft_update_node(stack_a, stack_b);
    ft_update_stack(*stack_a);
    if (print == false)
    {
        ft_printf("ra\n");
        increment_operation_count();
    }
    ft_display_stack(*stack_a, *stack_b);
}

void rb(t_stack **stack_b, t_stack **stack_a, bool print)
{
    ft_top_to_bottom(stack_b);
    ft_update_node(stack_b, stack_a);
    ft_update_stack(*stack_b);
    if (print == false)
    {
        ft_printf("rb\n");
        increment_operation_count();
    }
    ft_display_stack(*stack_a, *stack_b);
}

void rr(t_stack **stack_a, t_stack **stack_b)
{
    ra(stack_a, stack_b, true);
    rb(stack_b, stack_a, true);
    increment_operation_count();
    ft_printf("rr\n");
}

void rra(t_stack **stack_a, t_stack **stack_b, bool print)
{
    ft_bottom_to_top(stack_a);
    ft_update_stack(*stack_a);
    ft_update_node(stack_a, stack_b);

    if (!print)
    {
        ft_printf("rra\n");
        increment_operation_count();
    }
    ft_display_stack(*stack_a, *stack_b);
}


void rrb(t_stack **stack_b, t_stack **stack_a,bool print)
{
    ft_bottom_to_top(stack_b);
    ft_update_node(stack_b, stack_a);
    ft_update_stack(*stack_b);
    if (print == false)
    {
        ft_printf("rrb\n");
        increment_operation_count();
    }
    ft_display_stack(*stack_a, *stack_b);
}

void rrr(t_stack **stack_a, t_stack **stack_b)
{
    rra(stack_a, stack_b, true);
    rrb(stack_b, stack_a, true);
    increment_operation_count();
    ft_printf("rrr\n");
}
