#include "push_swap.h"

int	sa(t_stack *stack)
{
	int	x;

	if (stack->size_a <= 1)
		return (0);
	x = stack->a[0];
	stack->a[0] = stack->a[1];
	stack->a[1] = x;
	stack->op_count+=1;
	return (0);
}

int	sb(t_stack *stack)
{
	int	x;

	if (stack->size_b <= 1)
		return (0);
	x = stack->b[0];
	stack->b[0] = stack->b[1];
	stack->b[1] = x;
	stack->op_count+=1;
	return (0);
}

int	ss(t_stack *stack)
{
	sa(stack);
	sb(stack);
	return (0);
}

int	pa(t_stack *stack)
{
	int	*tmp_a;
	int	*tmp_b;
	int	i;

	if (stack->size_b == 0)
		return (0);
	stack->size_a+=1;
	tmp_a = ft_calloc(stack->size_a, sizeof(int));
	tmp_a[0] = stack->b[0];
	i = 0;
	while (++i < stack->size_a)
		tmp_a[i] = stack->a[i - 1];
	free(stack->a);
	stack->a = ft_calloc(stack->size_a, sizeof(int));
	i = -1;
	while (++i < stack->size_a)
		stack->a[i] = tmp_a[i];
	free(tmp_a);
	i = -1;
	tmp_b = ft_calloc(stack->size_b - 1, sizeof(int));
	while (++i < stack->size_b - 1)
		tmp_b[i] = stack->b[i + 1];
	free(stack->b);
	stack->b = ft_calloc(stack->size_b, sizeof(int));
	i = -1;
	while (++i < stack->size_b)
		stack->b[i] = tmp_b[i];
	stack->size_b-=1;
	free(tmp_b);
	stack->op_count+=1;
	return (0);
}

int	pb(t_stack *stack)
{
	int	*tmp_b;
	int	*tmp_a;
	int	i;

	if (stack->size_a == 0)
		return (0);
	stack->size_b+=1;
	tmp_b = ft_calloc(stack->size_b, sizeof(int));
	tmp_b[0] = stack->a[0];
	i = 0;
	while (++i < stack->size_b)
		tmp_b[i] = stack->b[i - 1];
	free(stack->b);
	stack->b = ft_calloc(stack->size_b, sizeof(int));
	i = -1;
	while (++i < stack->size_b)
		stack->b[i] = tmp_b[i];
	free(tmp_b);
	i = -1;
	tmp_a = ft_calloc(stack->size_a - 1, sizeof(int));
	while (++i < stack->size_a - 1)
		tmp_a[i] = stack->a[i + 1];
	free(stack->a);
	stack->a = ft_calloc(stack->size_a, sizeof(int));
	i = -1;
	while (++i < stack->size_a)
		stack->a[i] = tmp_a[i];
	stack->size_a-=1;
	free(tmp_a);
	stack->op_count+=1;
	return (0);
}
