/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Turk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 16:34:26 by ryada             #+#    #+#             */
/*   Updated: 2025/01/09 16:03:37 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
// Push 2 first numbers into B from A
// Find the cheapest number of A
// -> Operations to bring A on top + operations to bring target nod (smaller biggest in B) to the top B
// Push cheapest A to top B
// Do this untill A has only 3 ints
// Push back the top B to top A if the target (closest bigger) is ont he top A
// if not, put it on top A then push top B to top A
// push the smallest on top A

int ft_to_top(t_list *stack, t_node current)
{
    if (current != stack->top)
}

t_list *ft_find_cheapest(t_list *stack_a)
{
    int operations;
    opertions = to top A + to top B;

}


t_list *ft_turk(t_list *stack_a, t_list *stack_b, int argc, char **argv)
{
    pb(stack_b, stack_a);
    pb(stack_b, stack_a);
    stack_a = ft_find_cheapest(stack_a);//find the cheapest and put it on the top, return the stack
}
