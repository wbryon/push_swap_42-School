#include "push_swap.h"

int get_next_min(t_stack *stack, t_buf *buffer)
{
    int i;
    int min;
    int index;
    int has_min;

    has_min = 0;
    i = -1;
    index = 0;
    while (++i < stack->size_a)
    {
        if ((buffer->a_stack[i] == -1) && (!has_min || stack->a[i] < min))
        {
            has_min = 1;
            min = stack->a[i];
            index = i;
        }
    }
    return (index);
}

void    index_stack(t_stack *stack, t_buf *buffer)
{
    int i;
    int index;

    i = -1;
    index = 0;
    buffer->a_stack = (int *)ft_calloc(stack->size_a, sizeof(int));
    buffer->index = 0;
    while (++i < stack->size_a)
        buffer->a_stack[i] = -1;
    i = -1;
    while (++i < stack->size_a)
    {
        index = get_next_min(stack, buffer);
        buffer->a_stack[index] = buffer->index++;
    }
    i = -1;
    while (i < stack->size_a)
        stack->a[i] = buffer->a_stack[i];
}