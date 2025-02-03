/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 13:16:40 by ryada             #+#    #+#             */
/*   Updated: 2025/02/03 18:46:41 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


int main (int argc, char **argv)
{
    t_stack *stack_a;
    t_stack *stack_b;
    char **tab;

    stack_a = malloc(sizeof(t_stack));
    stack_b = malloc(sizeof(t_stack));
    if(!stack_a || !stack_b)
    {
        free(stack_a);
        free(stack_b);
        return (ft_putstr_fd("Error\n", 2),1);
    }
    ft_ini_stack(stack_a);
    ft_ini_stack(stack_b);
    if (argc == 2)
    {
        tab = ft_split(argv[1], ' ');
        if (!ft_error(2, tab))
        {
            ft_putstr_fd("Error\n", 2);
            ft_free_tab(tab);
            ft_free_stack(&stack_a);
            ft_free_stack(&stack_b);
            return (1);
        }
        ft_push_swap_turk(&stack_a, &stack_b, argc, tab);
        ft_free_tab(tab);
    }
    else if (argc > 2)
    {
        if (!ft_error(argc, argv))
        {
            return (ft_putstr_fd("Error\n", 2), 1);
            ft_free_stack(&stack_a);
            ft_free_stack(&stack_b);
        }
        ft_push_swap_turk(&stack_a, &stack_b, argc, argv);
    }
    //ft_display_stack(stack_a, stack_b);
    printf("operation Count: %d\n", get_operation_count());
    ft_free_stack(&stack_a);
    ft_free_stack(&stack_b);
    return (0);
}

void ft_push_swap_turk(t_stack **stack_a, t_stack **stack_b, int argc, char **argv)
{
    ft_fill_stack(*stack_a, argc, argv);
    if (ft_is_sorted(*stack_a))
        return;
    if ((*stack_a)->size > 3)
        ft_sort_large_stack(stack_a, stack_b);
    else
        ft_tiny_sort(stack_a, stack_b);
}

void ft_sort_large_stack(t_stack **stack_a, t_stack **stack_b)
{
    while (((*stack_b)->size < 2) && (*stack_a)->size > 3)
        pb(stack_b, stack_a);
    while ((*stack_a)->size > 3)
    {
        ft_before_pb(stack_a, stack_b);
        pb(stack_b, stack_a);
    }
    ft_tiny_sort(stack_a, stack_b);
    while ((*stack_b)->size > 0)
    {
        if ((*stack_b)->top->target->mid)
        {
            while ((*stack_a)->top != (*stack_b)->top->target)
                ra(stack_a, stack_b, false);
        }
        else
        {
            while ((*stack_a)->top != (*stack_b)->top->target)
                rra(stack_a, stack_b, false);
        }
        pa(stack_a, stack_b);
    }
    if (!ft_is_sorted(*stack_a))
        ft_align_stack_a(stack_a, stack_b);
}

void ft_align_stack_a(t_stack **stack_a, t_stack **stack_b)
{
    if (!(*stack_a) || !(*stack_a)->smallest || (*stack_a)->size <= 1)
        return;
    if ((*stack_a)->smallest->mid)
    {
        while ((*stack_a)->top != (*stack_a)->smallest)
            ra(stack_a, stack_b, false);
    }
    else
    {
        while ((*stack_a)->top != (*stack_a)->smallest)
            rra(stack_a, stack_b, false);
    }
}


