#include "push_swap.h"

int	ra(t_stack *stack)
{
	int	x;
	int	i;

	i = -1;
	x = stack->a[0];
	while (++i < stack->size_a && stack->a[i] < stack->size_a - 1)
		stack->a[i] = stack->a[i + 1];
	stack->a[stack->size_a - 1] = x;
	stack->op_count+=1;
	return (0);
}

int	rb(t_stack *stack)
{
	int	x;
	int	i;

	i = -1;
	x = stack->b[0];
	while (++i < stack->size_b)
		stack->b[i] = stack->b[i + 1];
	stack->b[i - 1] = x;
	stack->op_count+=1;
	return (0);
}

int	rr(t_stack *stack)
{
	ra(stack);
	rb(stack);
	stack->op_count+=1;
	return (0);
}

int	rra(t_stack *stack)
{
	int	x;
	int	i;

	i = stack->size_a;
	x = stack->a[i - 1];
	while (--i > 0)
		stack->a[i] = stack->a[i - 1];
	stack->a[0] = x;
	stack->op_count+=1;
	return (0);
}

int	rrb(t_stack *stack)
{
	int	x;
	int	i;

	i = stack->size_b;
	x = stack->b[i - 1];
	while (--i > 0)
		stack->b[i] = stack->b[i - 1];
	stack->b[0] = x;
	stack->op_count+=1;
	return (0);
}
