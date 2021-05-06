#include "push_swap.h"

void	check_isdigit(char *str)
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

void	check_range(t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	while (++i < stack->size_a)
	{
		j = -1;
		while (++j < i)
		{
			if (stack->a[j] == stack->a[i])
				ft_error();
		}
	}
}

void	init_stack(t_stack *stack)
{
	stack->a = NULL;
	stack->b = NULL;
	stack->size_a = 0;
	stack->size_b = 0;
}

void	fill_stack(t_stack *stack, char **buff)
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
		check_isdigit(buff[i]);
		stack->a[stack->size_a] = ft_atoi(buff[i]);
		stack->size_a++;
		free(buff[i]);
		i++;
	}
}