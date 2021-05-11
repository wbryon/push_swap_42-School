#include "push_swap.h"

void	sa(t_stack *stack, int flag)
{
	int	tmp;

	if (stack->size_a < 2)
		return ;
	tmp = stack->a[0];
	stack->a[0] = stack->a[1];
	stack->a[1] = tmp;
	if (flag)
		write(1, "sa\n", 3);
}

void	sb(t_stack *stack, int flag)
{
	int	tmp;

	if (stack->size_b < 2)
		return ;
	tmp = stack->b[0];
	stack->b[0] = stack->b[1];
	stack->b[1] = tmp;
	if (flag)
		write(1, "sb\n", 3);
}

void	ss(t_stack *stack, int flag)
{
	sa(stack, 0);
	sb(stack, 0);
	if (flag)
		write(1, "ss\n", 3);
}
