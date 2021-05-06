#include "push_swap.h"

void	ra(t_stack *stack, int flag)
{
	int	i;
	int	tmp;

	if (stack->size_a < 2)
		return ;
	tmp = stack->a[0];
	i = -1;
	while (++i < stack->size_a - 1)
		stack->a[i] = stack->a[i + 1];
	stack->a[i] = tmp;
	if (flag)
		write(1, "ra\n", 3);
}

void	rb(t_stack *stack, int flag)
{
	int	i;
	int	tmp;

	if (stack->size_b < 2)
		return ;
	tmp = stack->b[0];
	i = -1;
	while (++i < stack->size_b - 1)
		stack->b[i] = stack->b[i + 1];
	stack->b[i] = tmp;
	if (flag)
		write(1, "rb\n", 3);
}

void	rr(t_stack *stack, int flag)
{
	ra(stack, 0);
	rb(stack, 0);
	if (flag)
		write(1, "rr\n", 3);
}