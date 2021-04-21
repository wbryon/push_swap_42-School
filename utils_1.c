#include "push_swap.h"

void	find_min_max(t_stack *stack)
{
	int	i;

	i = -1;
	stack->min_a = stack->a[0];
	while (++i < stack->size_a - 1)
	{
		if (stack->a[i] > stack->a[i + 1] && stack->a[i + 1] < stack->min_a)
		{
			stack->min_a = stack->a[i + 1];
			stack->pos_min = i + 1;
		}
	}
	i = -1;
	stack->max_a = stack->a[0];
	while (++ i < stack->size_a - 1)
	{
		if (stack->a[i] < stack->a[i + 1] && stack->a[i + 1] > stack->max_a)
		{
			stack->max_a = stack->a[i + 1];
			stack->pos_max = i + 1;
		}
	}
}

void	case_a(t_stack *stack)
{
	if (stack->pos_max < 2 && stack->pos_min < 2)
	{
		pb(stack);
		pb(stack);
	}
	else if (stack->pos_min != 0 && stack->pos_max != 0)
	{
		ra(stack);
		pb(stack);
		pb(stack);
	}
	else if (stack->pos_min != 1 && stack->pos_max != 1)
	{
		pb(stack);
		ra(stack);
		pb(stack);
	}
}

void	case_b(t_stack *stack)
{
	rra(stack);
	pb(stack);
	rra(stack);
	pb(stack);
}

void	case_c(t_stack *stack)
{
	pb(stack);
	rra(stack);
	pb(stack);
}

void	case_d(t_stack *stack)
{
	if (stack->pos_min < stack->pos_max)
	{
		while (stack->a[0] != stack->min_a)
			ra(stack);
		pb(stack);
		while (stack->a[0] != stack->max_a)
			ra(stack);
		pb(stack);
	}
	else
	{
		while (stack->a[0] != stack->max_a)
			ra(stack);
		pb(stack);
		while (stack->a[0] != stack->min_a)
			ra(stack);
		pb(stack);
	}
}
