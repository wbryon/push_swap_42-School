#include "push_swap.h"

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

void	sort_five(t_stack *stack)
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
		case_d(stack);
	sort_three(stack);
	pa(stack);
	if (stack->a[0] == stack->max_a)
		ra(stack);
	pa(stack);
	if (stack->a[0] == stack->max_a)
		ra(stack);
}

void	sort_hundred(t_stack *stack)
{
	int	i;
	int	count;
	int	top;
	int	bottom;

	i = -1;
	count = -1;
	while (++i < stack->size_a - 1)
	{
		count++;
		if (stack->a[i] < stack->a[i + 1])
		{
			count++;
			if (count == 5)
			{
				if (i <= stack->size_a / 2)
				{
					top = stack->a[i + 1];
					bottom = stack->a[i - 4];
					while (stack->a[0] != top)
						ra(stack);
					while (stack->a[0] != bottom)
						pb(stack);
				}
			}
		}
	}
}
