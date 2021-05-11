#include "visualizer.h"

int	get_next_min(t_stack *stack, t_visual *vs)
{
	int	i;
	int	min;
	int	index;
	int	has_min;

	has_min = 0;
	i = -1;
	index = 0;
	while (++i < stack->size_a)
	{
		if ((vs->a_stack[i] == -1) && (!has_min || stack->a[i] < min))
		{
			has_min = 1;
			min = stack->a[i];
			index = i;
		}
	}
	return (index);
}

void	index_stack(t_visual *vs, t_stack *stack)
{
	int	i;
	int	index;

	i = -1;
	index = 0;
	vs->a_stack = (int *)ft_calloc(stack->size_a, sizeof(int));
	vs->index = 0;
	while (++i < stack->size_a)
		vs->a_stack[i] = -1;
	i = -1;
	while (++i < stack->size_a)
	{
		index = get_next_min(stack, vs);
		vs->a_stack[index] = vs->index++;
	}
	i = -1;
	while (++i < stack->size_a)
		stack->a[i] = vs->a_stack[i];
}
