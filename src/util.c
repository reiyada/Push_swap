#include "../includes/push_swap.h"

static int g_operation_count = 0;

void increment_operation_count(void)
{
        g_operation_count++;
}

int get_operation_count(void)
{
    return g_operation_count;
}

void reset_operation_count(void)
{
    g_operation_count = 0;
}

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

void ft_free_stack(t_stack **stack)
{
    t_node *current;
    t_node *next;

    if (!stack)
        return;
    current = (*stack)->top;
    while (current)
    {
        next = current->next;
        free(current);
        current = next;
    }
    free(*stack);
    *stack = NULL;
}

int ft_is_sorted(t_stack *stack_a)
{
    t_node *current;

    if (!stack_a || !stack_a->top) 
        return (1);
    current = stack_a->top;
    while (current->next)
    {
        if (current->value > current->next->value)
            return (0);
        current = current->next;
    }
    return (1);
}