/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rei <rei@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 13:16:40 by ryada             #+#    #+#             */
/*   Updated: 2025/01/23 20:05:55 by rei              ###   ########.fr       */
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
    stack_a->bottom = NULL;
    stack_a->size = 0;
    stack_a->biggest = NULL;
    stack_a->smallest = NULL;

    stack_b->top = NULL;
    stack_b->bottom = NULL;
    stack_b->size = 0;
    stack_b->biggest = NULL;
    stack_b->smallest = NULL;
}


int main (int argc, char **argv)
{
    t_stack *stack_a;
    t_stack *stack_b;
    char **tab;

    stack_a = malloc(sizeof(t_stack));
    stack_b = malloc(sizeof(t_stack));
    if(!stack_a || !stack_b)
    {
        ft_printf("Error\n");
        ft_printf("Error: Failed to allocate memory for stacks.\n");//DELETE
        return (0);
    } //wanna put this in ft_set_stack but idk how
    ft_set_stack(stack_a, stack_b);
    if (argc == 2)
    {
        tab = ft_split(argv[1], ' ');
        if (ft_error(2, tab) == 0)
        {
            ft_printf("Error\n");
            ft_printf("Error: Invalid input.\n");//DELETE
            ft_free_tab(tab);
            return (1);
        }
        ft_push_swap_turk(stack_a, stack_b, argc, tab);
        ft_free_tab(tab);
    }
    else
    {
        if (ft_error(argc, argv) == 0)
        {
            ft_printf("Error\n");
            ft_printf("Error: Invalid input.\n");//DELETE
            return (1);
        }
        ft_push_swap_turk(stack_a, stack_b, argc, argv);
    }
    return (0);
}

// void ft_push_swap_turk(t_stack *stack_a, t_stack *stack_b, int argc, char **argv)
// {
//     //[1]Initialize the input
//     ft_set_stack(stack_a, stack_b);
//     ft_fill_stack(stack_a, argc, argv);
//     ft_assign_index(stack_a);
//     ft_display_stack(stack_a, stack_b);
//     ft_printf("--------------------------------------------\n");
//     ft_free_stack(stack_a);
//     ft_free_stack(stack_b);
//     //[2]Push 2 nodes of stack_a to stack_b
//     //[3]Push the cheapest node of stack_a to stack_b
//     //[4]Push back nodes of stack_b to stack_a
//     //[5]Sort stack_a
// }

//GOOD ONE//
void ft_push_swap_turk(t_stack *stack_a, t_stack *stack_b, int argc, char **argv)
{
    //[1]Initialize the input
    ft_set_stack(stack_a, stack_b);
    ft_fill_stack(stack_a, argc, argv);
    if (!stack_a->top)
    {
        ft_printf("Error: stack_a is empty after initialization.\n"); //DELETE
        return;
    }
    ft_assign_index(stack_a);
    
    if (ft_is_sorted(stack_a))
    {
        ft_printf("The input stack is already sorted.\n"); //DELETE
        return ;
    }
    ft_display_stack(stack_a, stack_b);
    ft_printf("--------------------------------------------\n");
    //CHECK if the argument is more than 3 digits 
    if (stack_a->size <= 5)
    {
        if (stack_a->size == 3)
            ft_sort_3(stack_a);
        else if(stack_a->size == 2)
            ft_sort_2(stack_a);
        else
            ft_sort_4_5(stack_a, stack_b);
    }
    //[2]Push 2 nodes of stack_a to stack_b
    else
    {
        pb(stack_b, stack_a);
        pb(stack_b, stack_a);
        ft_assign_index(stack_a);
        ft_assign_index(stack_b);
        ft_display_stack(stack_a, stack_b);
        ft_printf("--------------------------------------------\n");

        //[3]Push the cheapest node of stack_a to stack_b
        while (stack_a->size > 3)
        {
            //printf("1\n");
            ft_find_target_node(stack_a, stack_b);
            // if (!stack_a->cheapest->target)
            // {
            //     ft_printf("Error: Target node for cheapest is NULL.\n");
            //     return;
            // }
            // t_node *current_a = stack_a->top;
            // while (current_a)
            // {
            //     printf("Target of %d is %d\n", current_a->value, current_a->target->value);
            //     current_a = current_a->next;
            // }
            
            ft_calculate_total_cost(stack_a, stack_b);
            ft_find_cheapest(stack_a);
            //printf("2\n");
            ft_printf("\nCheapest is :[%d]%d with the cost of %d\n\n", stack_a->cheapest->index, stack_a->cheapest->value, stack_a->cheapest->cost);
            if (!stack_a->cheapest)
            {
                ft_printf("Error: Cheapest node is NULL.\n");
                return;
            }
            if (!stack_a->cheapest->target)
            {
                ft_printf("Error: Target node for cheapest is NULL.\n");
                return;
            }
            //printf("3\n");
            ft_target_to_top(stack_b, stack_a->cheapest->target);
            ft_display_stack(stack_a, stack_b);
            ft_printf("--------------------------------------------\n");
            //printf("4\n");
            ft_cheapest_to_top(stack_a);
            ft_display_stack(stack_a, stack_b);
            ft_printf("--------------------------------------------\n");
            //printf("5\n");
            pb(stack_b, stack_a);
            ft_assign_index(stack_a);
            ft_assign_index(stack_b);
        }
        // ft_sort_3(stack_a);
        // ft_display_stack(stack_a, stack_b);
        // ft_printf("--------------------------------------------\n");

        //[4]Push back nodes of stack_b to stack_a
        while (stack_b->size > 0)
        {
            ft_assign_biggest_smallest(stack_b);
            if (stack_b->biggest->index <= stack_b->size / 2)
            {
                while (stack_b->top != stack_b->biggest)
                    rb(stack_b, false);
            }
            else
            {
                while (stack_b->top != stack_b->biggest)
                    rrb(stack_b, false);
            }
            ft_assign_index(stack_a);
            ft_assign_index(stack_b);
            if (stack_a->size == 3)
            {
                ft_sort_3(stack_a);
                ft_display_stack(stack_a, stack_b);
                ft_printf("--------------------------------------------\n");
                while (stack_a->top->value < stack_b->top->value)
                {
                    ra(stack_a, false);
                    ft_display_stack(stack_a, stack_b);
                    ft_printf("--------------------------------------------\n");
                    pa(stack_a, stack_b);
                }
            }
            pa(stack_a, stack_b);
            ft_assign_index(stack_a);
            ft_assign_index(stack_b);
            ft_display_stack(stack_a, stack_b);
            ft_printf("--------------------------------------------\n");
        }
        //[5]Sort stack_a
        ft_assign_biggest_smallest(stack_a);
        if (stack_a->smallest->index <= stack_a->size / 2)
        {
            while (stack_a->top != stack_a->smallest)
                ra(stack_a, false);
        }
        else
        {
            while (stack_a->top != stack_a->smallest)
                rra(stack_a, false);
        }
    }
    ft_display_stack(stack_a, stack_b);
    ft_printf("--------------------------------------------\n");
    ft_printf("Total operations: %d\n", get_operation_count());
    ft_free_stack(stack_a);
    ft_free_stack(stack_b);
}


