/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rei <rei@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 15:07:01 by ryada             #+#    #+#             */
/*   Updated: 2025/01/03 22:32:13 by rei              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// sa: Swap the top two elements of stack a.
// pb: Push the top element from a to b.
// pa: Push the top element from b to a.
// ra / rra: Rotate stack a up or down.
// rb / rrb: Rotate stack b up or down.

#include "../includes/push_swap.h"


//find the pivot(the number in the middle)
int ft_find_pivot(t_stack stack_a, int size)
{
    int *temp;
    t_node *current;
    int i;
    int pivot;

    temp = malloc(sizeof(int) * size);
    if (!temp)
        return (0);
    current = stack_a.top;
    i = 0;
    while (current && i < size)
    {
        temp[i] = current->value;
        current = current->next;
        i++;
    }
    pivot = temp[size / 2];
    free (temp);
    return (pivot);
}

int ft_move_to_stackb(t_stack *stack_a, t_stack *stack_b, int size)
{
    int pivot;
    int count_smaller;
    int i;
    
    pivot = ft_find_pivot(*stack_a, size);
    ft_printf("Pivot: %d\n", pivot); //// delete this
    i = 0;
    while (i < size)
    {
        if(stack_a->top->value < pivot)
        {
            pb(stack_a, stack_b);
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
    return (count_smaller);
}
