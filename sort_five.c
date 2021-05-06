#include "push_swap.h"

void	sort_three(t_stack *stack)
{
	int	max;

	max = find_max(stack);
	if (stack->size_a == 1)
		return ;
	else if (stack->size_a == 2)
	{
		if (stack->a[0] > stack->a[1])
			sa(stack, 1);
		return ;
	}
	else if (stack->size_a == 3)
	{
		if (stack->a[0] == max)
			ra(stack, 1);
		if (stack->a[1] == max)
			rra(stack, 1);
		if (stack->a[0] > stack->a[1])
			sa(stack, 1);
	}
}

void	sort_five(t_stack *stack)
{
	int	i;
	int	min;
	int	max;

	i = stack->size_b;
	min = find_min(stack);
	max = find_max(stack);
	while (stack->size_b - i != 2)
	{
		if (stack->a[0] == min || stack->a[0] == max)
			pb(stack, 1);
		else
			ra(stack, 1);
	}
	sort_three(stack);
	pa(stack, 1);
	pa(stack, 1);
	if (stack->a[0] == max)
		ra(stack, 1);
	else
	{
		sa(stack, 1);
		ra(stack, 1);
	}
}