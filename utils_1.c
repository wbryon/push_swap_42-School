#include "push_swap.h"

void	find_min_max_a(t_stack *stack)
{
	int	i;

	i = 0;
	stack->min_a = stack->a[0];
	while (++i < stack->size_a)
	{
		if (stack->a[i] < stack->min_a)
		{
			stack->min_a = stack->a[i];
			stack->pos_min = i;
		}
	}
	i = 0;
	stack->max_a = stack->a[0];
	while (++i < stack->size_a)
	{
		if (stack->a[i] > stack->max_a)
		{
			stack->max_a = stack->a[i];
			stack->pos_max = i;
		}
	}
}
void	find_ops_min(t_stack *stack)
{
	int	i;

	i = -1;
	stack->ops_min = stack->sum_ops[0];
	while (++i < stack->size_b)
	{
		if (stack->ops_min > stack->sum_ops[i])
		{
			stack->ops_min = stack->sum_ops[i];
			stack->pos_min = i;
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
