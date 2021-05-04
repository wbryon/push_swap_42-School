#include "push_swap.h"

void	find_ops_min(t_stack *stack)
{
	int	i;

	i = -1;
	stack->ops_min = stack->sum_ops[0];
	while (++i < stack->size_b)
	{
		if (stack->ops_min > stack->sum_ops[i])
			stack->ops_min = stack->sum_ops[i];
	}
}

void	case_a(t_stack *stack)
{
	if (stack->pos_max < 2 && stack->pos_min < 2)
	{
		pb(stack, 1);
		pb(stack, 1);
	}
	else if (stack->pos_min != 0 && stack->pos_max != 0)
	{
		ra(stack, 1);
		pb(stack, 1);
		pb(stack, 1);
	}
	else if (stack->pos_min != 1 && stack->pos_max != 1)
	{
		pb(stack, 1);
		ra(stack, 1);
		pb(stack, 1);
	}
}

void	case_b(t_stack *stack)
{
	rra(stack, 1);
	pb(stack, 1);
	rra(stack, 1);
	pb(stack, 1);
}

void	case_c(t_stack *stack)
{
	pb(stack, 1);
	rra(stack, 1);
	pb(stack, 1);
}

void	case_d(t_stack *stack)
{
	if (stack->pos_min < stack->pos_max)
	{
		while (stack->a[0] != stack->min_a)
			ra(stack, 1);
		pb(stack, 1);
		while (stack->a[0] != stack->max_a)
			ra(stack, 1);
		pb(stack, 1);
	}
	else
	{
		while (stack->a[0] != stack->max_a)
			ra(stack, 1);
		pb(stack, 1);
		while (stack->a[0] != stack->min_a)
			ra(stack, 1);
		pb(stack, 1);
	}
}
