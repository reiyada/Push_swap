/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rei <rei@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 13:16:40 by ryada             #+#    #+#             */
/*   Updated: 2025/01/26 01:14:00 by rei              ###   ########.fr       */
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
        return (ft_putstr_fd("Error\n", 2),1);
    if (argc == 2)
    {
        tab = ft_split(argv[1], ' ');
        if (!ft_error(2, tab))
        {
            ft_putstr_fd("Error\n", 2);
            ft_free_tab(tab);
            return (1);
        }
        ft_push_swap_turk(stack_a, stack_b, argc, tab);
        ft_free_tab(tab);
    }
    else
    {
        if (ft_error(argc, argv) == 0)
            return (ft_putstr_fd("Error\n", 2), 1);
        ft_push_swap_turk(stack_a, stack_b, argc, argv);
    }
    free(stack_a);
    free(stack_b);
    return (0);
}



//NO DISPLAY
void ft_push_swap_turk(t_stack *stack_a, t_stack *stack_b, int argc, char **argv)
{
    ft_ini_stack(stack_a);
    ft_ini_stack(stack_b);
    ft_fill_stack(stack_a, argc, argv);
    if (ft_is_sorted(stack_a))
        return;
    if (stack_a->size > 3)
    {
        while (stack_a->size != 3 && stack_b->size != 2)
            pb(stack_b, stack_a);
        while(stack_a->size > 3)
        {
            ft_find_cheapest(stack_a, stack_b);
            //printf("cheapest:%d\n", stack_a->cheapest->value);
            ft_cheapest_to_top(stack_a, stack_b);

            pb(stack_b, stack_a);
        }
        ft_tiny_sort(stack_a, stack_b);
        while (stack_b->size > 0)
        {
            if (stack_a->top == stack_b->top->target)
            {
                pa(stack_a, stack_b);
            }
            else
            {
                if (stack_b->top->target->index < stack_a->size / 2)
                {
                    while (stack_a->top != stack_b->top->target)
                    {
                        ra(stack_a, stack_b, false);
                    } 
                }
                else
                {
                    while (stack_a->top != stack_b->top->target)
                    {
                        rra(stack_a, stack_b, false); 
                    }
                }
                pa(stack_a, stack_b);
            }
        }
        //Sort A
        if (stack_a->smallest->index < stack_a->size / 2)
        {
            while (stack_a->top != stack_a->smallest)
            {
                ra(stack_a, stack_b,false);
            }
        }
        else
        {
            while (stack_a->top != stack_a->smallest)
            {
                rra(stack_a, stack_b,false);
            }
                
        }
    }
    else
        ft_tiny_sort(stack_a, stack_b);
}
