/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rei <rei@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 13:16:40 by ryada             #+#    #+#             */
/*   Updated: 2025/01/03 22:32:14 by rei              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// int main (int argc, char **argv)
// {
//     t_stack *stack;
//     // int pivot;
//     // int elemnts;

//     // elemnts = argc - 1;
//     if (ft_error(argc, argv) == 0)
//     {
//         ft_printf("Error\n");
//         return (1);
//     }
//     stack = malloc(sizeof(t_stack));
//     if(!stack)
//     {
//         ft_printf("Error\n");
//         return (1);
//     }
//     stack->top = NULL;
//     stack->size = 0;
//     ft_fill_stack(stack, argc, argv);
//     ft_display_stack(stack);
//     // pivot = ft_find_pivot(*stack, elemnts);
//     // ft_printf("Pivot :%d\n", pivot);
//     ft_free_stack(stack);
// }

int mian (int argc, char **argv)
{
    t_stack *stack_a;
    t_stack *stack_b;
    int moved;

    stack_a = malloc(sizeof(t_stack));
    stack_b = malloc(sizeof(t_stack));
    if(!stack_a || !stack_b)
    {
        ft_printf("Error\n");
        return (1);
    }
    stack_a->top = NULL;
    stack_a->size = 0;
    stack_b->top = NULL;
    stack_b->size = 0;
    if (ft_error(argc, argv) == 0)
    {
        ft_printf("Error\n");
        return (1);
    }
    ft_fill_stack(stack_a, argc, argv);
    moved = ft_move_to_stackb(stack_a, stack_b, stack_a->size);
    ft_printf("Moved %d elements smaller than the pivot to stack_b.\n", moved);
    ft_display_stack(stack_a);
    ft_display_stack(stack_b);
    ft_free_stack(stack_a);
    ft_free_stack(stack_b);
    return 0;
}
