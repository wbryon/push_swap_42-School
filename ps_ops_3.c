#include "push_swap.h"

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
		stack->num_of_ops = stack->num_of_ops;
		/*write(1, "pb\n", 3);*/
}

void	rrr(t_stack *stack, int flag)
{
	rra(stack, flag);
	rrb(stack, flag);
	stack->num_of_ops+=1;
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
		stack->num_of_ops = stack->num_of_ops;
		/*write(1, "pa\n", 3);*/
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

int	*ft_realloc(int *tmp, int value, int size, int flag)
{
	int	i;
	int	*temp;

	temp = (int *)ft_calloc(sizeof(int), size);
	if (!temp)
		ft_error();
	i = 0;
	if (flag)
	{
		temp[0] = value;
		while (i < size - 1)
		{
			temp[i + 1] = tmp[i];
			i++;
		}
	}
	else
	{
		while (i < size)
		{
			temp[i] = tmp[i + 1];
			i++;
		}
	}
	return (temp);
}
