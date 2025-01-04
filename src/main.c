/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 13:16:40 by ryada             #+#    #+#             */
/*   Updated: 2025/01/04 17:50:57 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int ft_countstr(char **tab)
{
    int i;
    i = 0;
    while (tab[i])
        i++;
    return (i);
}

void ft_free_tab(char **tab)
{
    int i;
    i = 0;
    while (tab[i])
    {
        free (tab[i]);
        i++;
    }
    free (tab);
}

// int main (int argc, char **argv)
// {
//     t_stack *stack;
//     char **tab;
//     int countstr;
//     // int pivot;
//     // int elemnts;

//     // elemnts = argc - 1;
    
//     stack = malloc(sizeof(t_stack));
//     if(!stack)
//     {
//         ft_printf("Error\n");
//         return (1);
//     }
//     if (argc == 2)
//     {
//         tab = ft_split(argv[1], ' ');
//         countstr = ft_countstr(tab);
//         stack->top = NULL;
//         stack->size = 0;
//         ft_fill_stack(stack, countstr, tab);
//         ft_display_stack(stack);
//         // pivot = ft_find_pivot(*stack, elemnts);
//         // ft_printf("Pivot :%d\n", pivot);
//         ft_free_stack(stack);
//         ft_free_tab(tab);
//     }
//     else if (argc > 2)
//     {
//         if (ft_error(argv) == 0)
//         {
//             ft_printf("Error1\n");
//             return (1);
//         }
//         stack->top = NULL;
//         stack->size = 0;
//         ft_fill_stack(stack, argc - 1, argv);
//         ft_display_stack(stack);
//         // pivot = ft_find_pivot(*stack, elemnts);
//         // ft_printf("Pivot :%d\n", pivot);
//         ft_free_stack(stack);    
//     }
//     return (0);
// }

int main (int argc, char **argv)
{
    t_stack *stack_a;
    t_stack *stack_b;
    char **tab;
    int countstr;
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
    if (ft_error(argv) == 0)
    {
        ft_printf("Error\n");
        return (1);
    }
    if (argc == 2)
    {
        tab = ft_split(argv[1], ' ');
        countstr = ft_countstr(tab);
        stack_a->top = NULL;
        stack_a->size = 0;
        ft_fill_stack(stack_a, countstr, tab);
        moved = ft_move_to_stackb(stack_a, stack_b, stack_a->size);
        ft_printf("Moved %d elements smaller than the pivot to stack_b.\n", moved);
        ft_display_stack(stack_a);
        ft_display_stack(stack_b);
        ft_free_stack(stack_a);
        ft_free_stack(stack_b);
        return (0);
    }
    ft_fill_stack(stack_a, argc, argv);
    moved = ft_move_to_stackb(stack_a, stack_b, stack_a->size);
    ft_printf("Moved %d elements smaller than the pivot to stack_b.\n", moved);
    ft_display_stack(stack_a);
    ft_display_stack(stack_b);
    ft_free_stack(stack_a);
    ft_free_stack(stack_b);
    return (0);
}
