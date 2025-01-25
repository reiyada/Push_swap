/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 13:16:40 by ryada             #+#    #+#             */
/*   Updated: 2025/01/25 15:58:43 by ryada            ###   ########.fr       */
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


int main (int argc, char **argv)
{
    t_stack *stack_a;
    t_stack *stack_b;
    char **tab;

    stack_a = malloc(sizeof(t_stack));
    stack_b = malloc(sizeof(t_stack));
    if(!stack_a || !stack_b)
        return (ft_putstr_fd("Error\n", 2),1);
    if (argc == 2)
    {
        tab = ft_split(argv[1], ' ');
        if (ft_error(2, tab) == 0)
        {
            ft_putstr_fd("Error\n", 2);
            ft_free_tab(tab);
            return (1);
        }
        ft_push_swap_turk(stack_a, stack_b, argc, tab);
        ft_free_tab(tab);
    }
    else
    {
        if (ft_error(argc, argv) == 0)
            return (ft_putstr_fd("Error\n", 2), 1);
        ft_push_swap_turk(stack_a, stack_b, argc, argv);
    }
    return (0);
}



//NO DISPLAY
void ft_push_swap_turk(t_stack *stack_a, t_stack *stack_b, int argc, char **argv)
{
    //Set the stack
    ft_ini_stack(stack_a);
    ft_ini_stack(stack_b);
    ft_fill_stack(stack_a, argc, argv);
    //If it is already sorted order, return nothing
    if (ft_is_sorted(stack_a))
        return;
    //If stack_a has more than 3 nodes
    if (stack_a->size > 3)
    {
        if (stack_a->size > 4)
        {
            //Push 2 nodes to stack B from A without checking anything
            pb(stack_b, stack_a);
            pb(stack_b, stack_a);
        }
        else
        {
            //Push 1 node to stack B from A without checking anything
            pb(stack_b, stack_a);
        }
        while(stack_a->size > 3)
        {
            //Push the cheapest node to stack B from A
            ft_find_target_a(stack_a, stack_b);
            ft_find_cheapest(stack_a);
            ft_cheapest_to_top(stack_a);
            pb(stack_b, stack_a);
        }
        //Sort the left 3 nodes in A
        ft_tiny_sort(stack_a);
        while (stack_b->size > 0)
        {
            //Set the target node of B
            ft_set_target_b(stack_a, stack_b);
            //-> need to make this one
            if (stack_a->top == stack_b->top->target)
            {
                //Push the top B to A if the target of top B is already at top of A
                pa(stack_a, stack_b);
            }
            else
            {
                //If the target of top B is NOT at top of A yet
                if (stack_b->top->target->index < stack_a->size / 2)
                {
                    //If the target of top B is at higher than middle of A,
                    //Rotate the nodes until the targtet arrives to the top A
                    while (stack_a->top != stack_b->top->target)
                    {
                        ra(stack_a, false);
                    }
                }
                else
                {
                    //If the target of top B is at lower than middle of A,
                    //Reverse the nodes until the targtet arrives to the top A
                    while (stack_a->top != stack_b->top->target)
                    {
                        rra(stack_a, false);
                    }
                        
                }
                //Push the top B to A
                pa(stack_a, stack_b);
            }
        }
        //Sort A
        ft_assign_biggest_smallest(stack_a);
        if (stack_a->smallest->index < stack_a->size / 2)
        {
            //If the smallest of A is at higher than middle of A,
            //Rotate the nodes until the smallest arrives to the top A
            while (stack_a->top != stack_a->smallest)
            {
                ra(stack_a, false);
            }
                
        }
        else
        {
            //If the smallest of A is at lower than middle of A,
            //Reverse the nodes until the smallest arrives to the top A
            while (stack_a->top != stack_a->smallest)
            {
                rra(stack_a, false);
            }
                
        }
    }
    //If stack_a has les than 3 nodes
    else
    {
        ft_tiny_sort(stack_a);
    }
}

//New
void ft_push_swap_turk(t_stack *stack_a, t_stack *stack_b, int argc, char **argv)
{
    //Set the stack
    ft_set_stack(stack_a, stack_b);
    ft_fill_stack(stack_a, argc, argv);
    //If it is already sorted order, return nothing
    if (ft_is_sorted(stack_a))
        return;
    ft_printf("---------------------Before the sort-----------------------\n");
    ft_display_stack(stack_a, stack_b);
    //If stack_a has more than 3 nodes
    if (stack_a->size > 3)
    {
        if (stack_a->size > 4)
        {
            //Push 2 nodes to stack B from A without checking anything
            pb(stack_b, stack_a);
            pb(stack_b, stack_a);
            ft_printf("--------------------First 2 pb------------------------\n");
            ft_display_stack(stack_a, stack_b);
        }
        else
        {
            //Push 1 node to stack B from A without checking anything
            pb(stack_b, stack_a);
        }
        while(stack_a->size > 3)
        {
            //Push the cheapest node to stack B from A
            ft_find_target_a(stack_a, stack_b);
            ft_find_cheapest(stack_a);
            ft_cheapest_to_top(stack_a);
            ft_printf("--------------------Cheapest to the top A-----------------------\n");
            ft_display_stack(stack_a, stack_b);
            pb(stack_b, stack_a);
            ft_printf("--------------------Pb the cheapest-----------------------\n");
            ft_display_stack(stack_a, stack_b);
        }
        //Sort the left 3 nodes in A
        ft_tiny_sort(stack_a);
        while (stack_b->size > 0)
        {
            //Set the target node of B
            ft_set_target_b(stack_a, stack_b);
            //-> need to make this one
            if (stack_a->top == stack_b->top->target)
            {
                //Push the top B to A if the target of top B is already at top of A
                pa(stack_a, stack_b);
                ft_printf("--------------------pa-----------------------\n");
                ft_display_stack(stack_a, stack_b);
            }
            else
            {
                //If the target of top B is NOT at top of A yet
                if (stack_b->top->target->index < stack_a->size / 2)
                {
                    //If the target of top B is at higher than middle of A,
                    //Rotate the nodes until the targtet arrives to the top A
                    while (stack_a->top != stack_b->top->target)
                    {
                        ra(stack_a, false);
                        ft_printf("--------------------ra till the target comes to top-----------------------\n");
                        ft_display_stack(stack_a, stack_b);
                    }
                }
                else
                {
                    //If the target of top B is at lower than middle of A,
                    //Reverse the nodes until the targtet arrives to the top A
                    while (stack_a->top != stack_b->top->target)
                    {
                        rra(stack_a, false);
                        ft_printf("--------------------rra till the target comes to top-----------------------\n");
                        ft_display_stack(stack_a, stack_b);
                    }
                        
                }
                //Push the top B to A
                pa(stack_a, stack_b);
                ft_printf("--------------------pa-----------------------\n");
                ft_display_stack(stack_a, stack_b);
            }
        }
        //Sort A
        ft_assign_biggest_smallest(stack_a);
        if (stack_a->smallest->index < stack_a->size / 2)
        {
            //If the smallest of A is at higher than middle of A,
            //Rotate the nodes until the smallest arrives to the top A
            while (stack_a->top != stack_a->smallest)
            {
                ra(stack_a, false);
                ft_printf("--------------------ra till the smallest comes to top-----------------------\n");
                ft_display_stack(stack_a, stack_b);
            }
                
        }
        else
        {
            //If the smallest of A is at lower than middle of A,
            //Reverse the nodes until the smallest arrives to the top A
            while (stack_a->top != stack_a->smallest)
            {
                rra(stack_a, false);
                ft_printf("--------------------ra till the smallest comes to top-----------------------\n");
                ft_display_stack(stack_a, stack_b);
            }
                
        }
    }
    //If stack_a has les than 3 nodes
    else
    {
        ft_tiny_sort(stack_a);
    }
    ft_printf("--------------------FINAL------------------------\n");
    ft_display_stack(stack_a, stack_b);
    ft_printf("Total operations: %d\n", get_operation_count());
}






//GOOD ONE//
// void ft_push_swap_turk(t_stack *stack_a, t_stack *stack_b, int argc, char **argv)
// {
//     //[1]Initialize the input
//     ft_set_stack(stack_a, stack_b);



//     ft_fill_stack(stack_a, argc, argv);
//     if (!stack_a->top)
//     {
//         ft_printf("Error: stack_a is empty after initialization.\n"); //DELETE
//         return;
//     }
//     ft_assign_index(stack_a);
//     if (ft_is_sorted(stack_a))
//     {
//         ft_printf("The input stack is already sorted.\n"); //DELETE
//         return ;
//     }
//     ft_printf("---------------------Before the sort-----------------------\n");
//     ft_display_stack(stack_a, stack_b);
//     //CHECK if the argument is more than 3 digits 
//     if (stack_a->size <= 3)
//     {
//         if (stack_a->size == 3)
//             ft_sort_3(stack_a);
//         else if(stack_a->size == 2)
//             ft_sort_2(stack_a);
//         // else
//         //     ft_sort_4_5(stack_a, stack_b);
//     }
//     //[2]Push 2 nodes of stack_a to stack_b
//     else
//     {
//         pb(stack_b, stack_a);
//         pb(stack_b, stack_a);
//         ft_assign_index(stack_a);
//         ft_assign_index(stack_b);
//         ft_printf("----------------------After pussing 2 nodes to B----------------------\n");
//         ft_display_stack(stack_a, stack_b);

//         //[3]Push the cheapest node of stack_a to stack_b
//         while (stack_a->size > 3)
//         {
//             //printf("1\n");
//             ft_find_target_node(stack_a, stack_b);
//             // if (!stack_a->cheapest->target)
//             // {
//             //     ft_printf("Error: Target node for cheapest is NULL.\n");
//             //     return;
//             // }
//             // t_node *current_a = stack_a->top;
//             // while (current_a)
//             // {
//             //     printf("Target of %d is %d\n", current_a->value, current_a->target->value);
//             //     current_a = current_a->next;
//             // }
            
//             ft_calculate_total_cost(stack_a, stack_b);
//             ft_find_cheapest(stack_a);
//             //printf("2\n");
//             ft_printf("\nCheapest is :[%d]%d with the cost of %d\n\n", stack_a->cheapest->index, stack_a->cheapest->value, stack_a->cheapest->cost);
//             if (!stack_a->cheapest)
//             {
//                 ft_printf("Error: Cheapest node is NULL.\n");
//                 return;
//             }
//             if (!stack_a->cheapest->target)
//             {
//                 ft_printf("Error: Target node for cheapest is NULL.\n");
//                 return;
//             }
//             //printf("3\n");
//             ft_target_to_top(stack_b, stack_a->cheapest->target);
//             ft_printf("--------------------Move target to the top B------------------------\n");
//             ft_display_stack(stack_a, stack_b);
//             //printf("4\n");
//             ft_cheapest_to_top(stack_a);
//             ft_printf("-------------------Move cheapest to the top A-------------------------\n");
//             ft_display_stack(stack_a, stack_b);
//             //printf("5\n");
//             pb(stack_b, stack_a);
//             ft_assign_index(stack_a);
//             ft_assign_index(stack_b);
//         }
//         // ft_sort_3(stack_a);
//         // ft_display_stack(stack_a, stack_b);
//         // ft_printf("--------------------------------------------\n");

//         //[4]Push back nodes of stack_b to stack_a
//         while (stack_b->size > 0)
//         {
//             ft_assign_biggest_smallest(stack_b);
//             if (stack_b->biggest->index <= stack_b->size / 2)
//             {
//                 while (stack_b->top != stack_b->biggest)
//                     rb(stack_b, false);
//             }
//             else
//             {
//                 while (stack_b->top != stack_b->biggest)
//                     rrb(stack_b, false);
//             }
//             ft_assign_index(stack_a);
//             ft_assign_index(stack_b);
//             if (stack_a->size == 3)
//             {
//                 ft_sort_3(stack_a);
//                 ft_printf("---------------------Sort 3 nodes in A-----------------------\n");
//                 ft_display_stack(stack_a, stack_b);
//                 while (stack_a->top->value < stack_b->top->value)
//                 {
//                     ra(stack_a, false);
//                     ft_printf("---------------------Change the position of A-----------------------\n");
//                     ft_display_stack(stack_a, stack_b);
//                     pa(stack_a, stack_b);
//                 }
//             }
//             pa(stack_a, stack_b);
//             ft_assign_index(stack_a);
//             ft_assign_index(stack_b);
//             ft_printf("-------------------After pussing back from B to A-------------------------\n");
//             ft_display_stack(stack_a, stack_b);
//         }
//         //[5]Sort stack_a
//         // ft_assign_biggest_smallest(stack_a);
//         // if (stack_a->smallest->index <= stack_a->size / 2)
//         // {
//         //     while (stack_a->top != stack_a->smallest)
//         //         ra(stack_a, false);
//         // }
//         // else
//         // {
//         //     while (stack_a->top != stack_a->smallest)
//         //         rra(stack_a, false);
//         // }
//     }
//     ft_printf("--------------------FINAL------------------------\n");
//     ft_display_stack(stack_a, stack_b);
//     ft_printf("Total operations: %d\n", get_operation_count());
//     ft_free_stack(stack_a);
//     ft_free_stack(stack_b);
// }


