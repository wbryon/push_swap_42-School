#include "push_swap.h"

void	if_sorted(t_stack *stack)
{
	int	i;
	int	flag;

	i = -1;
	flag = 0;
	while (++i < stack->size_a - 1)
	{
		if (stack->a[i] > stack->a[i + 1])
			flag = 1;
	}
	if (flag == 0)
		write(1, "sorted\n", 7);
}

void	push_to_b(t_stack *stack)
{
	int	i;

	i = -1;
	while (stack->size_a > 5)
		pb(stack);
}
