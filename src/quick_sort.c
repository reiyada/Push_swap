/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 15:07:01 by ryada             #+#    #+#             */
/*   Updated: 2025/01/02 17:42:12 by ryada            ###   ########.fr       */
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
        return (NULL);
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

