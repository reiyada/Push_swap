/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rei <rei@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 13:16:40 by ryada             #+#    #+#             */
/*   Updated: 2025/01/21 22:28:14 by rei              ###   ########.fr       */
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

// void ft_push_swap(t_stack *stack_a, t_stack *stack_b, int argc, char **argv)
// {
//     ft_fill_stack(stack_a, argc, argv);
//     ft_printf("Before the sort\n");
//     ft_display_stack(stack_a, stack_b);
//     ft_printf("--------------------------------------------\n");
//     ft_printf ("The process\n");
//     if (stack_a->size == 2)
//         ft_sort_2(stack_a);
//     else if (stack_a->size == 3)
//         ft_sort_3(stack_a);
//     else if (stack_a->size == 4 || stack_a->size == 5)
//         ft_sort_4_5(stack_a, stack_b); //replace this with the sort function
//     ft_printf("--------------------------------------------\n");
//     ft_printf("After the move\n");
//     ft_display_stack(stack_a, stack_b);
//     ft_free_stack(stack_a);
//     ft_free_stack(stack_b);
// }

// void ft_push_swap(t_stack *stack_a, t_stack *stack_b, int argc, char **argv)
// {
//     ft_fill_stack(stack_a, argc, argv);
//     ft_assign_index(stack_a);
//     ft_assign_index(stack_b);
//     ft_printf("Before the sort:\n");
//     ft_display_stack(stack_a, stack_b);
//     ft_printf("--------------------------------------------\n");
//     ft_printf("\nStack A with Costs:\n");
//     ft_count_cost_a(stack_a);
//     ft_printf("--------------------------------------------\n");
//     ft_printf("The process:\n");

//     if (stack_a->size == 2)
//         ft_sort_2(stack_a);
//     else if (stack_a->size == 3)
//         ft_sort_3(stack_a);
//     else if (stack_a->size == 4 || stack_a->size == 5) // You can replace this with a sort function for larger stacks
//     {
//         ft_sort_4_5(stack_a, stack_b);
//         // Display the stack with costs for debugging
        
//         ft_display_stack(stack_a, stack_b);
//     }

//     ft_printf("--------------------------------------------\n");
//     ft_printf("After the process:\n");
//     ft_display_stack(stack_a, stack_b);

//     ft_free_stack(stack_a);
//     ft_free_stack(stack_b);
// }

void ft_push_swap(t_stack *stack_a, t_stack *stack_b, int argc, char **argv)
{
    // Step 1: Fill and assign indexes
    ft_fill_stack(stack_a, argc, argv);
    ft_assign_index(stack_a);
    ft_assign_index(stack_b);

    // Display the initial state of the stacks
    ft_printf("Before the sort:\n");
    ft_display_stack(stack_a, stack_b);
    ft_printf("--------------------------------------------\n");

    // Step 2: Push 2 nodes from stack_a to stack_b
    ft_printf("Pushing 2 nodes to STACK_B:\n");
    pb(stack_b, stack_a);
    pb(stack_b, stack_a);

    // Step 3: Display the state after pushing 2 nodes
    ft_printf("\nAfter pushing 2 nodes to STACK_B:\n");
    ft_assign_index(stack_a);
    ft_assign_index(stack_b);
    ft_assign_biggest_smallest(stack_b);
    ft_display_stack(stack_a, stack_b);
    ft_printf("--------------------------------------------\n");

    // Step 4: Calculate and display total costs for stack_a
    ft_printf("\nCalculating total costs for STACK_A:\n");
    ft_calculate_total_cost(stack_a, stack_b); // Calculates total cost for each node in stack_a

    // Step 5: Display the stack to verify costs
    ft_printf("\nStack A with Total Costs:\n");
    ft_display_stack(stack_a, stack_b);
    ft_printf("--------------------------------------------\n");

    // Free the stacks
    ft_free_stack(stack_a);
    ft_free_stack(stack_b);
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
        return (0);
    } //wanna put this in ft_set_stack but idk how
    ft_set_stack(stack_a, stack_b);
    if (argc == 2)
    {
        tab = ft_split(argv[1], ' ');
        if (ft_error(2, tab) == 0)
        {
            ft_printf("Error\n");
            ft_free_tab(tab);
            return (1);
        }
        ft_push_swap(stack_a, stack_b, argc, tab);
        ft_free_tab(tab);
    }
    else
    {
        if (ft_error(argc, argv) == 0)
        {
            ft_printf("Error\n");
            return (1);
        }
        ft_push_swap(stack_a, stack_b, argc, argv);
    }
    return (0);
}

