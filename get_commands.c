#include "push_swap.h"

static void	if_max(t_stack *stack, int max, int i)
{
	int	index;

	index = get_index(stack, max);
	if (index < stack->size_a / 2)
	{
		stack->op_count_a[i] = index + 1;
		stack->op_name_a[i] = "ra";
	}
	else
	{
		stack->op_count_a[i] = stack->size_a - index - 1;
		stack->op_name_a[i] = "rra";
	}
}

static void	if_min(t_stack *stack, int min, int i)
{
	int	index;

	index = get_index(stack, min);
	if (index <= stack->size_a / 2)
	{
		stack->op_count_a[i] = index;
		stack->op_name_a[i] = "ra";
	}
	else
	{
		stack->op_count_a[i] = stack->size_a - index;
		stack->op_name_a[i] = "rra";
	}
}

static void	mid_a(t_stack *stack, int i)
{
	int	j;

	j = -1;
	while (++j < stack->size_a - 1)
	{
		if (stack->b[i] > stack->a[j] && stack->b[i] < stack->a[j + 1])
		{
			if (j < stack->size_a / 2)
			{
				stack->op_count_a[i] = j + 1;
				stack->op_name_a[i] = "ra";
			}
			else
			{
				stack->op_count_a[i] = stack->size_a - (j + 1);
				stack->op_name_a[i] = "rra";
			}
			j = stack->size_a;
		}
	}
}

void	get_cmd_a(t_stack *stack)
{
	int	i;
	int	min;
	int	max;

	i = -1;
	while (++i < stack->size_b)
	{
		max = find_max(stack);
		min = find_min(stack);
		if (stack->b[i] > max)
			if_max(stack, max, i);
		else if (stack->b[i] < min)
			if_min(stack, min, i);
		else
			mid_a(stack, i);
		if (stack->op_count_a[i] == 0)
			stack->op_name_a[i] = NULL;
	}
}

void	get_cmd_b(t_stack *stack)
{
	int	i;

	i = 0;
	while (++i < stack->size_b)
	{
		if (i <= stack->size_b / 2)
		{
			stack->op_count_b[i] = i;
			stack->op_name_b[i] = "rb";
		}
		else
		{
			stack->op_count_b[i] = stack->size_b - i;
			stack->op_name_b[i] = "rrb";
		}
	}
	if (stack->size_b % 2 == 0)
		if (!ft_strcmp(stack->op_name_a[stack->size_b / 2], "rra"))
			stack->op_name_b[stack->size_b / 2] = "rrb";
}
