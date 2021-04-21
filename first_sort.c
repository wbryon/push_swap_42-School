#include "push_swap.h"

int	sort_three(t_stack *stack)
{
	if (stack->a[0] > stack->a[1] && stack->a[1] > stack->a[2] && stack->a[2] < stack->a[0])
	{
		sa(stack);
		rra(stack);
	}
	if (stack->a[0] > stack->a[1] && stack->a[1] < stack->a[2] && stack->a[2] < stack->a[0])
		ra(stack);
	if (stack->a[0] < stack->a[1] && stack->a[1] > stack->a[2] && stack->a[2] < stack->a[0])
		rra(stack);
	if (stack->a[0] > stack->a[1] && stack->a[1] < stack->a[2] && stack->a[2] > stack->a[0])
		sa(stack);
	if (stack->a[0] < stack->a[1] && stack->a[1] > stack->a[2] && stack->a[2] > stack->a[0])
	{
		rra(stack);
		sa(stack);
	}
	return (0);
}

void	find_min_max(t_stack *stack)
{
	int	i;

	i = -1;
	stack->min_a = stack->a[0];
	while (++i < stack->size_a)
	{
		if (stack->a[i] > stack->a[i + 1] && stack->a[i + 1] < stack->min_a)
			stack->min_a = stack->a[i + 1];
	}
	i = -1;
	stack->max_a = stack->a[0];
	while (++ i < stack->size_a)
	{
		if (stack->a[i] < stack->a[i + 1] && stack->a[i + 1] > stack->max_a)
			stack->max_a = stack->a[i + 1];
	}
}

int	sort_five(t_stack *stack)
{
	find_min_max(stack);
	if (stack->max_a < 3 || stack->min_a < 3)
	{
		while (stack->a[0] != stack->min_a || stack->a[0] != stack->max_a)
			ra(stack);
		pb(stack);
		while (stack->a[0] != stack->min_a || stack->a[0] != stack->max_a)
			ra(stack);
		pb(stack);
	}
	else
	{
		rra(stack);
		pb(stack);
		rra(stack);
		pb(stack);
	}
	sort_three(stack);
	pa(stack);
	if (stack->a[0] == stack->max_a)
		ra(stack);
	pa(stack);
	if (stack->a[0] == stack->max_a)
		ra(stack);
	return (0);
}
