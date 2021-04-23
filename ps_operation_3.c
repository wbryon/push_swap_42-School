#include "push_swap.h"

int	rrr(t_stack *stack)
{
	rra(stack);
	rrb(stack);
	stack->num_of_ops+=1;
	return (0);
}

int	check_range(t_stack *stack)
{
	int	i;
	int	j;

	i = -1;
	while (++i < stack->size_a)
	{
		j = i;
		while (++j < stack->size_a)
		{
			if (stack->a[i] == stack->a[j])
			{
				write(2, "Error: duplicated numbers\n", 27);
				return (0);
			}
		}
	}
	return (0);
}
