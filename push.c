#include "push_swap.h"

static int	*ft_realloc(int *tmp, int value, int size, int flag)
{
	int	i;
	int	*temp;

	temp = (int *)ft_calloc(sizeof(int), size);
	if (!temp)
		ft_error();
	i = -1;
	if (flag)
	{
		temp[0] = value;
		while (++i < size - 1)
			temp[i + 1] = tmp[i];
	}
	else
	{
		while (++i < size)
			temp[i] = tmp[i + 1];
	}
	return (temp);
}

void	pa(t_stack *stack, int flag)
{
	int	*tmp;

	if (!stack->size_b)
		return ;
	stack->size_a++;
	tmp = stack->a;
	stack->a = ft_realloc(tmp, stack->b[0], stack->size_a, 1);
	free(tmp);
	stack->size_b--;
	tmp = stack->b;
	stack->b = ft_realloc(tmp, stack->a[0], stack->size_b, 0);
	free(tmp);
	if (flag)
		write(1, "pa\n", 3);
}

void	pb(t_stack *stack, int flag)
{
	int	*tmp;

	if (!stack->size_a)
		return ;
	stack->size_b++;
	tmp = stack->b;
	stack->b = ft_realloc(tmp, stack->a[0], stack->size_b, 1);
	free(tmp);
	stack->size_a--;
	tmp = stack->a;
	stack->a = ft_realloc(tmp, stack->b[0], stack->size_a, 0);
	free(tmp);
	if (flag)
		write(1, "pb\n", 3);
}
