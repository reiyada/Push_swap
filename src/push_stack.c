/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 15:43:19 by ryada             #+#    #+#             */
/*   Updated: 2025/01/06 14:56:00 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void ft_push(t_stack *stack, int value, int to_top)
{
    t_node *new_node;
    new_node = malloc(sizeof(t_node));
    if (!new_node)
    {
        ft_printf("Error\n");
        return;
    }
    new_node->value = value;
    new_node->next = NULL;
    if (to_top || !stack->top)
    {
        new_node->next = stack->top;
        stack->top = new_node;
        if (!stack->bottom)
            stack->bottom = new_node;
    }
    else
    {
        stack->bottom->next = new_node;
        stack->bottom = new_node;
    }
    stack->size++;
}

void ft_fill_stack(t_stack *stack_a, int argc, char **argv)
{
    int i;
    int size;
    int value;

    if (argc == 2)
    {
        i = 0;
        size = ft_countstr(argv);
    }
    else
    {
        i = 1;
        size = argc;
    }
    while (i < size)
    {
        value = ft_atoi(argv[i]);
        ft_push(stack_a, value, 0);
        i++;
    }
}

void ft_display_stack(t_stack *stack_a, t_stack *stack_b)
{
    int i;
    i = 0;
    t_node *current_a;
    t_node *current_b;
    current_a = stack_a->top;
    current_b = stack_b->top;
    ft_printf("    A B\n");
    while(current_a || current_b)
    {
        ft_printf("[%d] ", i);
        if (current_a)
        {
            ft_printf("%d ", current_a->value);
            current_a = current_a->next;
        }
        else
            ft_printf("  "); //2 spaces
        if (current_b)
        {
            ft_printf("%d", current_b->value);
            current_b = current_b->next;
        }
        ft_printf("\n");
        i++;
    }
}

void ft_free_stack(t_stack *stack)
{
    t_node *current;
    t_node *temp;
    current  = stack->top;
    while (current)
    {
        temp = current;
        current = current->next;
        free(temp);
    }
    free(stack);
}
