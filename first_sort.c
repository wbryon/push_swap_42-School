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

int	find_min_stack_a(t_stack *stack)
{
	int	i;
	int	min;

	i = -1;
	min = stack->a[0];
	while (++i < stack->size_a)
	{
		if (stack->a[i] > stack->a[i + 1] && stack->a[i + 1] < min)
			min = stack->a[i + 1];
	}
	return (min);
}

int	sort_four(t_stack *stack)
{
	if (stack->a[0] == find_min(stack))
	{
		pb(stack);
		sort_three(stack);
		pa(stack);
	}
	else if (stack->a[1] == find_min(stack))
	{
		sa(stack);
		pb(stack);
		sort_three(stack);
		pa(stack);
	}
	else if (stack->a[2] == find_min(stack))
	{
		ra(stack);
		ra(stack);
		pb(stack);
		sort_three(stack);
		pa(stack);
	}
	else
	{
		rra(stack);
		pb(stack);
		sort_three(stack);
		pa(stack);
	}
}

int	sort_five(t_stack *stack)
{
	int	i;
	int	min;
	int	mid;

	i = -1;
	min = stack->a[0];;
	while (++i < stack->size_a)
	{
		if (stack->a[i] > stack->a[i + 1] && stack->a[i + 1] < min)
			min = stack->a[i + 1];
	}
	return (0);
}
