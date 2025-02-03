/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 16:34:26 by ryada             #+#    #+#             */
/*   Updated: 2025/02/03 17:18:52 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void ft_count_cost_a(t_stack **stack_a)
{
    t_node *current;

    if (!stack_a || (*stack_a)->size <= 1)
        return;
    current = (*stack_a)->top;
    while (current)
    {
        if(current->mid)
            current->cost = current->index;
        else
            current->cost = (*stack_a)->size - current->index;
        current = current->next;
    }
}

int ft_count_cost_b(t_node **current_a, t_stack **stack_b)
{
    t_node *target_node;

    if (!stack_b || (*stack_b)->size == 0 || !(*current_a)->target)
        return (0);
    target_node = (*current_a)->target;
    if(target_node->mid)
        return(target_node->index);
    else
        return ((*stack_b)->size - target_node->index);
}

int ft_two_moves(t_node *stack_a, t_node *stack_b)
{
    int i;

    i = 0;
    if (stack_a->mid && stack_b->mid)
    {
        printf("1\n");
        while (stack_a->index != 0 && stack_b->index != 0)
            i++;
            //rr(stack_a, stack_b);
        printf("2\n");   
        while (stack_a->index != 0 && stack_b->index == 0)
            i++;
            //ra(stack_a, stack_b, false);
        while (stack_b->index != 0 && stack_a->index == 0)
            i++;
            //rb(stack_b, stack_a, false);
    }
    else if (!(stack_a->mid) && !(stack_b->mid))
    {
        printf("3\n");
        while (stack_a->index != 0 && stack_b->index != 0)
            i++;
            //rrr(stack_a, stack_b);
        while (stack_a->index != 0 && stack_b->index == 0)
            i++;
            //rra(stack_a, stack_b, false);
        while (stack_b->index != 0 && stack_a->index == 0)
            i++;
            //rrb(stack_b, stack_a, false);
    }
    else
    {
        printf("4\n");
        while ((stack_a->mid) && stack_a->index != 0)
            i++;
            //ra(stack_a, stack_b, false);
        while ((stack_b->mid) && stack_b->index != 0)
            i++;
            //rb(stack_b, stack_a, false);
        while (!(stack_a->mid)&& stack_a->index != 0)
            i++;
            //rra(stack_a, stack_b, false);
        while (!(stack_b->mid) && stack_b->index != 0)
            i++;
            //rrb(stack_b, stack_a, false);
    }
    return(i);
}

void ft_calculate_total_cost(t_stack **stack_a, t_stack **stack_b)
{
    t_node *current_a;
    int cost_a;
    int cost_b;

    if (!stack_a || !stack_b)
        return;
    ft_count_cost_a(stack_a);
    current_a = (*stack_a)->top;
    while (current_a)
    {
        if (current_a->index != 0 && current_a->target->index != 0)
            current_a->cost = ft_two_moves(current_a, current_a->target);
        else
        {
            cost_a = current_a->cost;
            cost_b = ft_count_cost_b(&current_a, stack_b);
            current_a->cost = cost_a + cost_b;
        }
        current_a = current_a->next;
    }
}

void ft_find_cheapest(t_stack **stack_a, t_stack **stack_b)
{
    t_node *cheapest;
    t_node *current;

    ft_calculate_total_cost(stack_a, stack_b);
    current = (*stack_a)->top;
    cheapest = current;
    printf("-----------------------------------\n");
    while (current)
    {
        printf("[%d]%d (cost)%d\n", current->index, current->value, current->cost);
        if (current->cost < cheapest->cost)
            cheapest = current;
        current = current->next;
    }
    printf("-----------------------------------\n");
    printf("Cheapest:[%d]%d\n", cheapest->index, cheapest->value);
    (*stack_a)->cheapest = cheapest;
}

void ft_before_pb(t_stack **stack_a, t_stack **stack_b)
{
    t_node *cheapest_in_a;
    t_node *target_in_b;

    ft_find_cheapest(stack_a, stack_b);
    cheapest_in_a = (*stack_a)->cheapest;
    target_in_b = (*stack_a)->cheapest->target;
    if (!(cheapest_in_a->index == 0 && target_in_b->index == 0))
    {
        if (cheapest_in_a->mid && target_in_b->mid)
        {
            while (cheapest_in_a->index != 0 && target_in_b->index != 0)
                rr(stack_a, stack_b);
            while (cheapest_in_a->index != 0 && target_in_b->index == 0)
                ra(stack_a, stack_b, false);
            while (target_in_b->index != 0 && cheapest_in_a->index == 0)
                rb(stack_b, stack_a, false);
        }
        else if (!(cheapest_in_a->mid) && !(target_in_b->mid))
        {
            while (cheapest_in_a->index != 0 && target_in_b->index != 0)
                rrr(stack_a, stack_b);
            while (cheapest_in_a->index != 0 && target_in_b->index == 0)
                rra(stack_a, stack_b, false);
            while (target_in_b->index != 0 && cheapest_in_a->index == 0)
                rrb(stack_b, stack_a, false);
        }
        else
        {
            while ((cheapest_in_a->mid) && cheapest_in_a->index != 0)
                ra(stack_a, stack_b, false);
            while ((target_in_b->mid) && target_in_b->index != 0)
                rb(stack_b, stack_a, false);
            while (!(cheapest_in_a->mid)&& cheapest_in_a->index != 0)
                rra(stack_a, stack_b, false);
            while (!(target_in_b->mid) && target_in_b->index != 0)
                rrb(stack_b, stack_a, false);
        }
    }
}

void ft_before_pa(t_stack **stack_a, t_stack **stack_b)
{
    t_node *biggest_b;

    biggest_b = (*stack_b)->biggest;
    while((*stack_b)->top != biggest_b)
    {
        if ((*stack_a)->top != biggest_b->target)
        {
            if (biggest_b->mid && biggest_b->target->mid)
                rr(stack_a, stack_b);
            else if (!(biggest_b->mid && biggest_b->target->mid))
                rrr(stack_a, stack_b);
        }
        if (biggest_b->mid)
            rb(stack_b, stack_a, false);
        else if (!(biggest_b->mid))
            rrb(stack_b, stack_a, false);
    }
}
