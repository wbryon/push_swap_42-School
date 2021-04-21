#include "push_swap.h"

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

int	sort_three(t_stack *stack)
{
	if (stack->a[0] > stack->a[1] && stack->a[1] > stack->a[2]
		&& stack->a[2] < stack->a[0])
	{
		sa(stack);
		rra(stack);
	}
	if (stack->a[0] > stack->a[1] && stack->a[1] < stack->a[2]
		&& stack->a[2] < stack->a[0])
		ra(stack);
	if (stack->a[0] < stack->a[1] && stack->a[1] > stack->a[2]
		&& stack->a[2] < stack->a[0])
		rra(stack);
	if (stack->a[0] > stack->a[1] && stack->a[1] < stack->a[2]
		&& stack->a[2] > stack->a[0])
		sa(stack);
	if (stack->a[0] < stack->a[1] && stack->a[1] > stack->a[2]
		&& stack->a[2] > stack->a[0])
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

int	sort_five(t_stack *stack)
{
	find_min_max(stack);
	if (stack->pos_max < 3 && stack->pos_min < 3)
		case_a(stack);
	else if (stack->pos_max > 2 && stack->pos_min > 2)
		case_b(stack);
	else if ((stack->pos_max == 0 || stack->pos_min == 0)
		&& (stack->pos_max > 3 || stack->pos_min > 3))
		case_c(stack);
	else
	{
		case_d(stack);
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
