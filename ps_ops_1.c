#include "push_swap.h"

void	sa(t_stack *stack, int flag)
{
	int	x;

	if (stack->size_a <= 1)
		return ;
	x = stack->a[0];
	stack->a[0] = stack->a[1];
	stack->a[1] = x;
	stack->num_of_ops+=1;
	if (flag)
		/*write(1, "sa\n", 3);*/
		stack->num_of_ops = stack->num_of_ops;
}

void	sb(t_stack *stack, int flag)
{
	int	x;

	if (stack->size_b <= 1)
		return ;
	x = stack->b[0];
	stack->b[0] = stack->b[1];
	stack->b[1] = x;
	stack->num_of_ops+=1;
	if (flag)
		stack->num_of_ops = stack->num_of_ops;
		/*write(1, "sb\n", 3);*/
}

void	ss(t_stack *stack, int flag)
{
	sa(stack, flag);
	sb(stack, flag);
	if (flag)
		stack->num_of_ops = stack->num_of_ops;
		/*write(1, "ss\n", 3);*/
}