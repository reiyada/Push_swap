/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_r.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rei <rei@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 15:56:58 by ryada             #+#    #+#             */
/*   Updated: 2025/01/26 00:59:26 by rei              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


void ft_top_to_bottom(t_stack *stack_move)
{
    t_node *temp;

    if (stack_move->size < 2)
        return;
    temp = stack_move->top;
    stack_move->top = stack_move->top->next;
    stack_move->bottom->next = temp;
    stack_move->bottom = temp;
    temp->next = NULL;
    ft_update_stack(stack_move);
}

void ra(t_stack **stack_a, t_stack **stack_b, bool print)
{
    ft_top_to_bottom(*stack_a);
    ft_update_stack(*stack_a);
    ft_update_node(*stack_a, *stack_b);
    if (print == false)
    {
        ft_printf("ra\n");
        increment_operation_count();
    }
}

void rb(t_stack **stack_b, t_stack **stack_a, bool print)
{
    ft_top_to_bottom(*stack_b);
    ft_update_stack(*stack_b);
    ft_update_node(*stack_b, *stack_a);
    if (print == false)
    {
        ft_printf("rb\n");
        increment_operation_count();
    }
}

void rr(t_stack **stack_a, t_stack **stack_b)
{
    ra(*stack_a, *stack_b, true);
    rb(*stack_b, *stack_a, true);
    increment_operation_count();
    ft_printf("rr\n");
}

void ft_bottom_to_top(t_stack *stack_move)
{
    t_node *prev;
    t_node *last;

    if (stack_move->size < 2)
        return;
    prev = NULL;
    last = stack_move->top;
    while (last->next)
    {
        prev = last;
        last = last->next;
    }
    prev->next = NULL;
    last->next = stack_move->top; 
    stack_move->top = last;
    stack_move->bottom = prev;
    ft_update_stack(stack_move);
}

void rra(t_stack **stack_a, t_stack **stack_b, bool print)
{
    ft_bottom_to_top(*stack_a);
    ft_update_stack(*stack_a);
    ft_update_node(*stack_a, *stack_b);
    if (print == false)
    {
        ft_printf("rra\n");
        increment_operation_count();
    }
}

void rrb(t_stack **stack_b, t_stack **stack_a,bool print)
{
    ft_bottom_to_top(*stack_b);
    ft_update_stack(*stack_b);
    ft_update_node(*stack_b, *stack_a);
    if (print == false)
    {
        ft_printf("rrb\n");
        increment_operation_count();
    }
}

void rrr(t_stack **stack_a, t_stack **stack_b)
{
    rra(*stack_a, *stack_b, true);
    rrb(*stack_b, *stack_a, true);
    increment_operation_count();
    ft_printf("rrr\n");
}
