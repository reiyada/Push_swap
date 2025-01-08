/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 10:57:47 by ryada             #+#    #+#             */
/*   Updated: 2025/01/08 13:55:56 by ryada            ###   ########.fr       */
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


void ft_move_to_stackb(t_stack *stack_a, t_stack *stack_b, int count)
{
    int i = 0;

    while (i < count)
    {
        t_node *current = stack_a->top;
        t_node *smallest = current;
        int pos = 0;
        int smallest_pos = 0;

        // Find the smallest element in stack_a
        while (current)
        {
            if (current->value < smallest->value)
            {
                smallest = current;
                smallest_pos = pos;
            }
            current = current->next;
            pos++;
        }

        // Rotate or reverse rotate to bring the smallest element to the top
        if (smallest_pos <= stack_a->size / 2)
        {
            int j = 0;
            while (j < smallest_pos)
            {
                ra(stack_a);
                j++;
            }
        }
        else
        {
            int j = 0;
            while (j < stack_a->size - smallest_pos)
            {
                rra(stack_a);
                j++;
            }
        }

        // Push the smallest element to stack_b
        pb(stack_b, stack_a);
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
        size = ft_countword(argv[1], ' ');
    else if (argc > 2)
        size = argc - 1;

    if (size == 4)
        ft_move_to_stackb(stack_a, stack_b, 1);
    else if (size == 5)
        ft_move_to_stackb(stack_a, stack_b, 2);
    ft_sort_3(stack_a);
    if (stack_b->size > 1 && stack_b->top->value < stack_b->top->next->value)
        sb(stack_b);
    while (stack_b->size > 0)
        pa(stack_a, stack_b);
    return stack_a;
}

