#include "push_swap.h"

void	sort_three(t_stack *stack)
{
	if (stack->a[0] > stack->a[1] && stack->a[1] > stack->a[2]
		&& stack->a[2] < stack->a[0])
	{
		sa(stack, 1);
		rra(stack, 1);
	}
	if (stack->a[0] > stack->a[1] && stack->a[1] < stack->a[2]
		&& stack->a[2] < stack->a[0])
		ra(stack, 1);
	if (stack->a[0] < stack->a[1] && stack->a[1] > stack->a[2]
		&& stack->a[2] < stack->a[0])
		rra(stack, 1);
	if (stack->a[0] > stack->a[1] && stack->a[1] < stack->a[2]
		&& stack->a[2] > stack->a[0])
		sa(stack, 1);
	if (stack->a[0] < stack->a[1] && stack->a[1] > stack->a[2]
		&& stack->a[2] > stack->a[0])
	{
		rra(stack, 1);
		sa(stack, 1);
	}
}

void    sort_four(t_stack *stack)
{
    find_min_max_a(stack);
    while (stack->a[0] != stack->min_a)
	{
		if (stack->pos_min < 3)
			ra(stack, 1);
		else
			rra(stack, 1);
	}
    pb(stack, 1);
    sort_three(stack, 1);
    pa(stack, 1);
}

void	sort_five(t_stack *stack)
{
	find_min_max_a(stack);
	if (stack->pos_max < 3 && stack->pos_min < 3)
		case_a(stack, 1);
	else if (stack->pos_max > 2 && stack->pos_min > 2)
		case_b(stack, 1);
	else if ((stack->pos_max == 0 || stack->pos_min == 0)
		&& (stack->pos_max > 3 || stack->pos_min > 3))
		case_c(stack, 1);
	else
		case_d(stack, 1);
	sort_three(stack, 1);
	pa(stack, 1);
	if (stack->a[0] == stack->max_a)
		ra(stack, 1);
	pa(stack, 1);
	if (stack->a[0] == stack->max_a)
		ra(stack, 1);
}