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
	i = -1;
	mid = stack->a[0];
	if (mid == min)
		mid = stack->a[1];
	while (++i < stack->size_a)
	{
		if (stack->a[i] > stack->a[i + 1] && stack->a[i + 1] < mid && stack->a[i + 1] != min)
			mid = stack->a[i + 1];
	}
	if (min == stack->a[0])
		pb(stack);
	if (min == stack->a[1])
	{
		sa(stack);
		pb(stack);
	}
	if (min == stack->a[2])
	{
		ra(stack);
		sa(stack);
		pb(stack);
	}
	if (min == stack->a[3])
	{
		rra(stack);
		rra(stack);
		pb(stack);
	}
	if (min == stack->a[4])
	{
		rra(stack);
		pb(stack);
	}
	if (mid == stack->a[0])
		pb(stack);
	if(mid == stack->a[1])
	{
		sa(stack);
		pb(stack);
	}
	if (mid == stack->a[2])
	{
		rra(stack);
		rra(stack);
		pb(stack);
	}
	if (mid == stack->a[3])
	{
		rra(stack);
		pb(stack);
	}
	sort_three(stack);
	pa(stack);
	pa(stack);
	return (0);
}

int	sort_handred(t_stack *stack)
{
	int	mid;

	mid = stack->size_a / 2;
	return (0);
}
