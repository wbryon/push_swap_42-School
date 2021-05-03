#include "push_swap.h"

void	ft_check_args(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			ft_error();
		i++;
	}
}

void	ft_fill_stack(t_stack *stack, char **buff)
{
	int	i;
	int	*tmp;

	i = 0;
	while (buff[i])
		i++;
	tmp = stack->a;
	stack->a = (int *)ft_calloc(sizeof(int), stack->size_a + i);
	if (!stack->a)
		exit(1);
	i = -1;
	while (++i < stack->size_a)
		stack->a[i] = tmp[i];
	if (tmp)
		free(tmp);
	i = 0;
	while (buff[i])
	{
		ft_check_args(buff[i]);
		stack->a[stack->size_a] = ft_atoi(buff[i]);
		stack->size_a++;
		free(buff[i]);
		i++;
	}
}

int	ft_is_sorted(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->size_a - 1)
	{
		if (stack->a[i] > stack->a[i + 1])
			return (1);
		i++;
	}
	return (0);
}

void	find_min_max_a(t_stack *stack)
{
	int	i;

	i = 0;
	stack->min_a = stack->a[0];
	while (++i < stack->size_a)
	{
		if (stack->a[i] < stack->min_a)
		{
			stack->min_a = stack->a[i];
			stack->pos_min = i;
		}
	}
	i = 0;
	stack->max_a = stack->a[0];
	while (++i < stack->size_a)
	{
		if (stack->a[i] > stack->max_a)
		{
			stack->max_a = stack->a[i];
			stack->pos_max = i;
		}
	}
}

void	ft_error(void)
{
	write(1, "Error\n", 6);
	exit(1);
}