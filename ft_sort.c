#include "push_swap.h"

int	sort_three(t_stack *stack)
{
	if (stack->a[0] > stack->a[1] && stack->a[1] > stack->a[2]
		&& stack->a[2] < stack->a[0])
	{
		sa(stack);
		rra(stack);
	}
	if (stack->a[0] > stack->a[1] && stack->a[1] < stack->a[2]
		&& stack->a[2] < stack->a[0])
		ra(stack);
	if (stack->a[0] < stack->a[1] && stack->a[1] > stack->a[2]
		&& stack->a[2] < stack->a[0])
		rra(stack);
	if (stack->a[0] > stack->a[1] && stack->a[1] < stack->a[2]
		&& stack->a[2] > stack->a[0])
		sa(stack);
	if (stack->a[0] < stack->a[1] && stack->a[1] > stack->a[2]
		&& stack->a[2] > stack->a[0])
	{
		rra(stack);
		sa(stack);
	}
	return (0);
}

void	sort_five(t_stack *stack)
{
	find_min_max_a(stack);
	if (stack->pos_max < 3 && stack->pos_min < 3)
		case_a(stack);
	else if (stack->pos_max > 2 && stack->pos_min > 2)
		case_b(stack);
	else if ((stack->pos_max == 0 || stack->pos_min == 0)
		&& (stack->pos_max > 3 || stack->pos_min > 3))
		case_c(stack);
	else
	{
		case_d(stack);
	}
	sort_three(stack);
	pa(stack);
	if (stack->a[0] == stack->max_a)
		ra(stack);
	pa(stack);
	if (stack->a[0] == stack->max_a)
		ra(stack);
}

void	sort_ten(t_stack *stack)
{
	int	i;
	int	j;

	i = -1;
	push_to_b(stack);
	stack->op_count_a = ft_calloc(stack->size_b, sizeof(int));
	stack->op_count_b = ft_calloc(stack->size_b, sizeof(int));
	stack->op_name_a = (char **)ft_calloc(stack->size_b, sizeof(char *));
	stack->op_name_b = (char **)ft_calloc(stack->size_b, sizeof(char *));
	sort_five(stack);
	while (++i < stack->size_b)
	{
		if (i < stack->size_b / 2 + 1)
		{
			stack->op_name_b[i] = "rb";
			stack->op_count_b[i] = i;
		}
		else
		{
			stack->op_name_b[i] = "rrb";
			stack->op_count_b[i] = stack->size_b - i;
		}
		j = -1;
		while (++j < stack->size_a)
			if (stack->b[i] > stack->a[j] && stack->b[i] < stack->a[j + 1])
			{
				if (j < stack->size_a / 2)
				{
					stack->op_name_a[i] = "ra";
					stack->op_count_a[i] = j + 1;
				}
				else
				{
					stack->op_name_a[i] = "rra";
					stack->op_count_a[i] = stack->size_a - j - 1;
				}
			}
	}
}
