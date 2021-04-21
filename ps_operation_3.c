#include "push_swap.h"

int	rrr(t_stack *stack)
{
	rra(stack);
	rrb(stack);
	stack->op_count+=1;
	return (0);
}

int	check_range(int *range, int count)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (++i < count)
	{
		tmp = range[i];
		j = i;
		while (++j < count)
		{
			if (tmp == range[j])
			{
				write(2, "Error: duplicated numbers\n", 27);
				return (0);
			}
		}
	}
	return (0);
}
