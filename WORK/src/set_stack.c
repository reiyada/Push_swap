#include "../includes/push_swap.h"

void ft_ini_stack(t_stack *stack)
{
    stack->top = NULL;
    stack->bottom = NULL;
    stack->size = 0;
    stack->biggest = NULL;
    stack->smallest = NULL;
}

t_node *ft_ini_node(int value)
{
    t_node *new_node;

    new_node = malloc(sizeof(t_node));
    if (!new_node)
    {
        ft_putstr_fd("Error\n", 2);
        return (NULL);
    }
    new_node->value = value;
    new_node->next = NULL;
    new_node->target = NULL;
    new_node->cost = 0;
    new_node->index = 0;
    return (new_node);
}

//to_top
// 0: 1 2 3 4 5 -> 1 2 3 4 5
// 1: 1 2 3 4 5 -> 5 4 3 2 1
void ft_set_next(t_stack *stack, t_node *node, int to_top)
{
    if(to_top || !stack->top)
        node->next = stack->top;
    else if (stack->bottom)
        stack->bottom->next = node;
}

void ft_set_top_bottom(t_stack *stack, t_node *node)
{
    if (!stack->top)
    {
        stack->top = node;
        stack->bottom = node;
    }
    else
    {
        stack->bottom->next = node;
        stack->bottom = node;
    }
}

void ft_set_index(t_stack *stack)
{
    t_node *current;
    int i;

    i = 0;
    current = stack->top;
    while (current)
    {
        current->index = i;
        i++;
        current = current->next;
    }
}

void ft_push_node(t_stack *stack_a, int value, int to_top)
{
    t_node *new_node;

    new_node = ft_ini_node(value);
    if (!new_node)
        return (ft_putstr_fd("Error\n", 2));
    ft_set_next(stack_a, new_node, to_top);
    ft_set_top_bottom(stack_a, new_node);
    ft_set_index(stack_a);
    stack_a->size++;
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
        ft_push_node(stack_a, value, 0);
        i++;
    }
}

void ft_display_stack(t_stack *stack_a, t_stack *stack_b)
{
    // int i;
    // i = 0;
    t_node *current_a;
    t_node *current_b;
    current_a = stack_a->top;
    current_b = stack_b->top;
    ft_printf("    A B\n");
    while(current_a || current_b)
    {
        if (current_a)
        {
            ft_printf("[%d] %d",current_a->index, current_a->value);
            current_a = current_a->next;
        }
        else
            ft_printf("  "); //2 spaces
        if (current_b)
        {
            ft_printf("[%d] %d", current_b->index, current_b->value);
            current_b = current_b->next;
        }
        ft_printf("\n");
    }
}
