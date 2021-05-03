#include "push_swap.h"

void	do_rr(t_stack *stack, int i)
{
	int	j;

	j = -1;
	if (stack->op_count_a[i] >= stack->op_count_b[i])
	{
		while (++j < stack->op_count_b[i])
			rr(stack, 1);
		while (j < stack->ops_min)
		{
			ra(stack, 1);
			j++;
		}
	}
	else
	{
		while (++j < stack->op_count_a[i])
			rr(stack, 1);
		while (j < stack->ops_min)
		{
			rb(stack, 1);
			j++;
		}
	}
	pa(stack, 1);
	return ;
}

void	do_rrr(t_stack *stack, int i)
{
	int	j;

	j = -1;

	if (stack->op_count_a[i] >= stack->op_count_b[i])
	{
		while (++j < stack->op_count_b[i])
			rrr(stack, 1);
		while (j < stack->ops_min)
		{
			rra(stack, 1);
			j++;
		}		
	}
	else
	{
		while (++j < stack->op_count_a[i])
			rrr(stack, 1);
		while (j < stack->ops_min)
		{
			rrb(stack, 1);
			j++;
		}
	}
	pa(stack, 1);
	return ;
}

void	do_ra_rrb(t_stack *stack, int i)
{
	int	j;

	j = -1;
	while (++j < stack->op_count_a[i])
		ra(stack, 1);
	while (j < stack->ops_min)
		{
			rrb(stack, 1);
			j++;
		}
	pa(stack, 1);
	return ;
}

void	do_rra_rb(t_stack *stack, int i)
{
	int	j;

	j = -1;
	while (++j < stack->op_count_a[i])
		rra(stack, 1);
	while (j < stack->ops_min)
	{
		rb(stack, 1);
		j++;
	}
	pa(stack, 1);
	return ;
}

void	final_build(t_stack *stack)
{
	find_min_max_a(stack, 1);
	while (stack->a[0] != stack->min_a)
	{
		if (stack->pos_min < stack->size_a / 2 + 1)
			ra(stack, 1);
		else
			rra(stack, 1);
	}
	pa(stack, 1);
	return ;
}