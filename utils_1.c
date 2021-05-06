#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	int	i;

	i = -1;
	while (++i < stack->size_a - 1)
	{
		if (stack->a[i] > stack->a[i + 1])
			return (1);
	}
	return (0);
}

int	find_max(t_stack *stack)
{
	int	i;
	int	max;

	max = stack->a[0];
	i = 0;
	while (i < stack->size_a)
	{
		if (stack->a[i] > max)
			max = stack->a[i];
		i++;
	}
	return (max);
}

int	find_min(t_stack *stack)
{
	int	i;
	int	min;

	min = stack->a[0];
	i = 0;
	while (i < stack->size_a)
	{
		if (stack->a[i] < min)
			min = stack->a[i];
		i++;
	}
	return (min);
}

int	get_index(t_stack *stack, int elem)
{
	int	i;

	i = 0;
	while (i < stack->size_a)
	{
		if (stack->a[i] == elem)
			return (i);
		i++;
	}
	return (i);
}
