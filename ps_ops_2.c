#include "push_swap.h"

void	ra(t_stack *stack)
{
	int	x;
	int	i;

	i = -1;
	x = stack->a[0];
	while (++i < stack->size_a - 1)
		stack->a[i] = stack->a[i + 1];
	stack->a[i] = x;
	stack->num_of_ops+=1;
}

void	rb(t_stack *stack)
{
	int	x;
	int	i;

	i = -1;
	x = stack->b[0];
	while (++i < stack->size_b - 1)
		stack->b[i] = stack->b[i + 1];
	stack->b[i] = x;
	stack->num_of_ops+=1;
}

void	rr(t_stack *stack)
{
	ra(stack);
	rb(stack);
	stack->num_of_ops+=1;
}

void	rra(t_stack *stack)
{
	int	x;
	int	i;

	i = stack->size_a;
	x = stack->a[i - 1];
	while (--i > 0)
		stack->a[i] = stack->a[i - 1];
	stack->a[0] = x;
	stack->num_of_ops+=1;
}

void	rrb(t_stack *stack)
{
	int	x;
	int	i;

	i = stack->size_b;
	x = stack->b[i - 1];
	while (--i > 0)
		stack->b[i] = stack->b[i - 1];
	stack->b[0] = x;
	stack->num_of_ops+=1;
}
