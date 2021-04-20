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

int	sort_four(t_stack *stack)
{
	int	i;

	i = -1;
	return (0);
}

int	sort_five(t_stack *stack)
{
	int	i;

	i = -1;
	pb(stack);
	pb(stack);
	if (stack->b[0] < stack->b[1])
	sort_three(stack);
	if (stack->a[0] < stack->b[0])
	{
		if (stack->b[0] < stack->a[2])
		{
			rra(stack);
			pa(stack);
			ra(stack);
			ra(stack);
		}
		else
		{
			pa(stack);
			ra(stack);
		}
	}
	else
		pa(stack);
	if (stack->a[0] < stack->b[0])
	{
		if (stack->b[0] < stack->a[1])
		{
			pa(stack);
			sa(stack);
		}
		else if (stack->b[0] < stack->a[2])
		{
			ra(stack);
			pa(stack);
			sa(stack);
			rra(stack);
		}
		else if (stack->b[0] < stack->a[3])
		{
			rra(stack);
			pa(stack);
			ra(stack);
			ra(stack);
		}
	}
	else
		pa(stack);
	return (0);
}
