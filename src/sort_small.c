/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 10:57:47 by ryada             #+#    #+#             */
/*   Updated: 2025/01/06 16:28:58 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void ft_sort_array(int *array, int size)
{
    int temp;
    int i;
    int j;

    i = 0;
    while (i < size)
    {
        j = i + 1;
        while (j < size)
        {
            if (array[i] > array[j])
            {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
            j++;
        }
        i++;
    }
}

int ft_find_pivot(t_stack *stack_a, int size)
{
    int *temp;
    t_node *current;
    int i;
    int pivot;

    temp = malloc(sizeof(int) * size);
    if (!temp)
        return (0);
    current = stack_a->top;
    i = 0;
    while (current && i < size)
    {
        temp[i] = current->value;
        current = current->next;
        i++;
    }
    ft_sort_array(temp, size);
    pivot = temp[size / 2];
    free (temp);
    return (pivot);
}

void ft_move_to_stackb(t_stack *stack_a, t_stack *stack_b, int size)
{
    int pivot;
    int count_smaller;
    int i;
    
    pivot = ft_find_pivot(stack_a, size);
    i = 0;
    count_smaller = 0;
    while (i < size)
    {
        if(stack_a->top->value < pivot)
        {
            pb(stack_b, stack_a);
            count_smaller++;
        }
        else
            ra(stack_a);
        i++;
    }
    i = 0;
    while (i < size - count_smaller)
    {
        rra(stack_a);
        i++;
    }
}

t_stack *ft_sort_2(t_stack *stack_a)
{
    if (stack_a->top->value > stack_a->bottom->value)
        sa(stack_a);
    return (stack_a);
}

t_stack *ft_sort_3(t_stack *stack_a)
{
    int first;
    int second;
    int third;

    first = stack_a->top->value;
    second = stack_a->top->next->value;
    third = stack_a->bottom->value;
    
    if (first < second && second > third && first < third)
    {
        rra(stack_a);
        sa(stack_a);
    }
    else if (first > second && second < third && first < third)
        sa(stack_a);
    else if (first < second && second > third && first > third)
        rra(stack_a);
    else if (first > second && second < third && first > third)
        ra(stack_a);
    else if (first > second && second > third)
    {
        ra(stack_a);
        sa(stack_a);
    }
    return (stack_a);
}

t_stack *ft_sort_4_5(t_stack *stack_a, t_stack *stack_b, int argc, char **argv)
{
    int size;

    if (argc == 2)
        size = ft_countstr(argv);
    else if (argc > 2)
        size = argc;
    ft_move_to_stackb(stack_a, stack_b, size);
    if (size == 5)
    {
        ft_sort_2(stack_a);
        if (stack_b->top < stack_b->bottom)
            sb(stack_b);
        pa(stack_a, stack_b);
        pa(stack_a, stack_b);
    }
    else if (size == 6)
    {
        ft_sort_3(stack_a);
        if (stack_b->top < stack_b->bottom)
            sb(stack_b);
        pa(stack_a, stack_b);
        pa(stack_a, stack_b);
    }
    return (stack_a);
}
