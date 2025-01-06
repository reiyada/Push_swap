/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 13:16:40 by ryada             #+#    #+#             */
/*   Updated: 2025/01/06 16:29:31 by ryada            ###   ########.fr       */
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

void ft_set_stack(t_stack *stack_a, t_stack *stack_b)
{
    stack_a->top = NULL;
    stack_a->size = 0;
    stack_b->top = NULL;
    stack_b->size = 0;
}

void ft_push_stack(t_stack *stack_a, t_stack *stack_b, int argc, char **argv)
{
    ft_fill_stack(stack_a, argc, argv);
    ft_printf("Before the sort\n");
    ft_display_stack(stack_a, stack_b);
    ft_printf("--------------------------------------------\n");
    ft_printf ("The process\n");
    ft_sort_4_5(stack_a, stack_b, argc, argv); //replace this with the sort function
    ft_printf("--------------------------------------------\n");
    ft_printf("After the move\n");
    ft_display_stack(stack_a, stack_b);
    ft_free_stack(stack_a);
    ft_free_stack(stack_b);
}

int main (int argc, char **argv)
{
    t_stack *stack_a;
    t_stack *stack_b;
    char **tab;
    int countstr;

    stack_a = malloc(sizeof(t_stack));
    stack_b = malloc(sizeof(t_stack));
    if(!stack_a || !stack_b)
    {
        ft_printf("Error\n");
        return (0);
    } //wanna put this in ft_set_stack but idk how
    ft_set_stack(stack_a, stack_b);
        if (argc == 2)
        {
            tab = ft_split(argv[1], ' ');
            countstr = ft_countstr(tab) + 1;
            if (ft_error(countstr, tab) == 0)
            {
                ft_printf("Error\n");
                return (1);
            }
            ft_push_stack(stack_a, stack_b, argc, tab);
        }
        else
        {
            if (ft_error(argc, argv) == 0)
            {
                ft_printf("Error\n");
                return (1);
            }
            ft_push_stack(stack_a, stack_b, argc, argv);
        }
    return (0);
}

