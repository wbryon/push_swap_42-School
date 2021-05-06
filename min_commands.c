#include "push_swap.h"

void	get_sum_ops(t_stack *stack)
{
	int	i;

	stack->sum_ops[0] = stack->op_count_a[0];
	i = 1;
	while (i < stack->size_b)
	{
		if ((!ft_strcmp(stack->op_name_a[i], "ra") && \
			!ft_strcmp(stack->op_name_b[i], "rb")) || \
			(!ft_strcmp(stack->op_name_a[i], "rra") && \
			 !ft_strcmp(stack->op_name_b[i], "rrb")))
		{
			if (stack->op_count_a[i] > stack->op_count_b[i])
				stack->sum_ops[i] = stack->op_count_a[i];
			else
				stack->sum_ops[i] = stack->op_count_b[i];
		}
		else if ((!ft_strcmp(stack->op_name_a[i], "ra") && \
				!ft_strcmp(stack->op_name_b[i], "rrb")) || \
				(!ft_strcmp(stack->op_name_a[i], "rra") && \
				 !ft_strcmp(stack->op_name_b[i], "rb")))
			stack->sum_ops[i] = stack->op_count_a[i] + stack->op_count_b[i];
		else if (!stack->op_name_a[i])
			stack->sum_ops[i] = stack->op_count_b[i];
		i++;
	}
}

void	find_min_cmd(t_stack *stack)
{
	int	i;
	int	cmd_min;

	cmd_min = stack->sum_ops[0];
	stack->index = 0;
	i = 1;
	while (i < stack->size_b)
	{
		if (stack->sum_ops[i] < cmd_min)
		{
			cmd_min = stack->sum_ops[i];
			stack->index = i;
		}
		i++;
	}
}

void	get_min_cmd(t_stack *s)
{
	if ((!ft_strcmp(s->op_name_a[s->index], "ra") && \
			!ft_strcmp(s->op_name_b[s->index], "rb")) || \
			(!ft_strcmp(s->op_name_a[s->index], "rra") && \
			 !ft_strcmp(s->op_name_b[s->index], "rrb")))
	{
		if (s->op_count_a[s->index] > s->op_count_b[s->index])
		{
			s->do_a = s->op_count_a[s->index] - s->op_count_b[s->index];
			s->do_ab = s->op_count_b[s->index];
		}
		else
		{
			s->do_b = s->op_count_b[s->index] - s->op_count_a[s->index];
			s->do_ab = s->op_count_a[s->index];
		}
	}
	else
	{
		s->do_a = s->op_count_a[s->index];
		s->do_b = s->op_count_b[s->index];
	}
}

void	execute_min_cmd(t_stack *stack)
{
	while (stack->do_a)
	{
		if (!ft_strcmp(stack->op_name_a[stack->index], "ra"))
			ra(stack, 1);
		else if (!ft_strcmp(stack->op_name_a[stack->index], "rra"))
			rra(stack, 1);
		stack->do_a--;
	}
	while (stack->do_b)
	{
		if (!ft_strcmp(stack->op_name_b[stack->index], "rb"))
			rb(stack, 1);
		else if (!ft_strcmp(stack->op_name_b[stack->index], "rrb"))
			rrb(stack, 1);
		stack->do_b--;
	}
	while (stack->do_ab)
	{
		if (!ft_strcmp(stack->op_name_a[stack->index], "ra"))
			rr(stack, 1);
		else if (!ft_strcmp(stack->op_name_a[stack->index], "rra"))
			rrr(stack, 1);
		stack->do_ab--;
	}
}
