/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 13:16:40 by ryada             #+#    #+#             */
/*   Updated: 2025/01/23 13:19:37 by ryada            ###   ########.fr       */
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

// void ft_push_swap(t_stack *stack_a, t_stack *stack_b, int argc, char **argv)
// {
//     t_node *current;
//     // Step 1: Fill and assign indexes
//     ft_fill_stack(stack_a, argc, argv);
//     ft_assign_index(stack_a);
//     ft_assign_index(stack_b);

//     // Display the initial state of the stacks
//     ft_printf("Before the sort:\n");
//     ft_display_stack(stack_a, stack_b);
//     ft_printf("--------------------------------------------\n");

//     // Step 2: Push 2 nodes from stack_a to stack_b
//     ft_printf("Pushing 2 nodes to STACK_B:\n");
//     pb(stack_b, stack_a);
//     pb(stack_b, stack_a);

//     // Step 3: Display the state after pushing 2 nodes
//     ft_printf("\nAfter pushing 2 nodes to STACK_B:\n");
//     ft_assign_index(stack_a);
//     ft_assign_index(stack_b);
//     ft_assign_biggest_smallest(stack_b);
//     ft_display_stack(stack_a, stack_b);
//     ft_printf("--------------------------------------------\n");

//     // Step 4: Display the stack to verify costs
//     ft_calculate_total_cost(stack_a, stack_b); // Calculates total cost for each node in stack_a
//     ft_printf("\nStack A with Total Costs:\n");
//     current = stack_a->top;
//     while (current)
//     {
//         ft_printf("[%d]%d: (cost)%d\n", current->index, current->value,current->cost);
//         current = current->next;
//     }
//     ft_printf("--------------------------------------------\n");

//     // Step 5: Find the cheapest of all the nodes of stack_a
//     ft_find_cheapest(stack_a);
//     ft_printf("The cheapest: [%d] %d\n", stack_a->cheapest->index, stack_a->cheapest->value);
//     ft_printf("--------------------------------------------\n");

//     // Step 6: Push the target node of stack_b to the top of stack_b
//     while (stack_a->size > 3)
//     {
//         ft_calculate_total_cost(stack_a, stack_b);
//         ft_find_cheapest(stack_a);
//         ft_target_to_top(stack_b, stack_a->cheapest->target);
//         ft_find_target_node(stack_a, stack_b); // Assign target nodes for all nodes in stack_a
//         pb(stack_b, stack_a);
//         ft_assign_index(stack_a);
//         ft_assign_index(stack_b);
//         ft_display_stack(stack_a, stack_b);
//         ft_printf("--------------------------------------------\n");

//         // ft_find_cheapest(stack_a); // Find the cheapest node in stack_a
//         // t_node *cheapest = stack_a->cheapest;

//         // // Push the target node of the cheapest node in stack_b to the top
//         // ft_target_to_top(stack_b, cheapest->target);
//         // ft_assign_index(stack_a);
//         // ft_assign_index(stack_b);
//         // ft_display_stack(stack_a, stack_b);
//         // ft_printf("--------------------------------------------\n");
//         // // Push the cheapest node from stack_a to stack_b
//         // pb(stack_b, stack_a);
//         // ft_assign_index(stack_a);
//         // ft_assign_index(stack_b);
//         // ft_display_stack(stack_a, stack_b);
//         // ft_printf("--------------------------------------------\n");
        
//     }
//     // Step 7: Sort stack_b into the deescalating order
//     // ft_sort_stack_b(stack_b);
//     ft_assign_index(stack_a);
//     ft_assign_index(stack_b);
//     ft_display_stack(stack_a, stack_b);
//     ft_printf("--------------------------------------------\n");
//     // Step 8: Srot stack_a into the escalating order
//     ft_sort_3(stack_a);
//     ft_assign_index(stack_a);
//     ft_assign_index(stack_b);
//     ft_display_stack(stack_a, stack_b);
//     ft_printf("--------------------------------------------\n");
//     // Step 9: Push all nodes back to stack_a
//     while (stack_b->size > 0)
//     {
//         ft_assign_biggest_smallest(stack_b);
//         if (stack_b->biggest->index <= stack_b->size / 2)
//         {
//             while (stack_b->top != stack_b->biggest)
//                 rb(stack_b);
//         }
//         else
//         {
//             while (stack_b->top != stack_b->biggest)
//                 rrb(stack_b);
//         }
//         pa(stack_a, stack_b);
//         ft_assign_index(stack_a);
//         ft_assign_index(stack_b);
//         ft_display_stack(stack_a, stack_b);
//         ft_printf("--------------------------------------------\n");
//     }
//     // Step 10: Free the stacks
//     ft_free_stack(stack_a);
//     ft_free_stack(stack_b);
// }


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
    ft_free_stack(stack_a);
    ft_free_stack(stack_b);
    return (0);
}

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

    //[2]Push 2 nodes of stack_a to stack_b
    pb(stack_b, stack_a);
    pb(stack_b, stack_a);
    ft_assign_index(stack_a);
    ft_assign_index(stack_b);
    ft_display_stack(stack_a, stack_b);
    ft_printf("--------------------------------------------\n");

    //[3]Push the cheapest node of stack_a to stack_b
    while (stack_a->size > 0)
    {
        printf("1\n");
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
        printf("2\n");
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
        printf("3\n");
        ft_target_to_top(stack_b, stack_a->cheapest->target);
        ft_display_stack(stack_a, stack_b);
        ft_printf("--------------------------------------------\n");
        printf("4\n");
        ft_cheapest_to_top(stack_a);
        ft_display_stack(stack_a, stack_b);
        ft_printf("--------------------------------------------\n");
        printf("5\n");
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
                rb(stack_b);
        }
        else
        {
            while (stack_b->top != stack_b->biggest)
                rrb(stack_b);
        }
        pa(stack_a, stack_b);
        ft_assign_index(stack_a);
        ft_assign_index(stack_b);
        ft_display_stack(stack_a, stack_b);
        ft_printf("--------------------------------------------\n");
    }

    //[5]Sort stack_a
    if (stack_a->smallest->index <= stack_a->size / 2)
    {
        while (stack_a->top != stack_a->smallest)
            ra(stack_a);
    }
    else
    {
        while (stack_a->top != stack_a->smallest)
            rra(stack_a);
    }
    ft_display_stack(stack_a, stack_b);
    ft_printf("--------------------------------------------\n");
}

