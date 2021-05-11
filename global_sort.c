#include "push_swap.h"

static void	init_cmd(t_stack *stack)
{
	stack->do_a = 0;
	stack->do_b = 0;
	stack->do_ab = 0;
	stack->index = 0;
	stack->op_count_a = (int *)ft_calloc(sizeof(int), stack->size_b);
	stack->op_count_b = (int *)ft_calloc(sizeof(int), stack->size_b);
	stack->op_name_a = (char **)ft_calloc(sizeof(char *), stack->size_b);
	stack->op_name_b = (char **)ft_calloc(sizeof(char *), stack->size_b);
	stack->sum_ops = (int *)ft_calloc(sizeof(int), stack->size_b);
	if (!(stack->op_count_a && stack->op_count_b && stack->op_name_a && \
			stack->op_name_b && stack->sum_ops))
		exit(1);
}

static void	start_sorting(t_stack *stack)
{
	while (stack->size_b)
	{
		init_cmd(stack);
		get_cmd_a(stack);
		get_cmd_b(stack);
		get_sum_ops(stack);
		find_min_cmd(stack);
		get_min_cmd(stack);
		execute_min_cmd(stack);
		pa(stack, 1);
		free(stack->op_count_a);
		free(stack->op_count_b);
		free(stack->op_name_a);
		free(stack->op_name_b);
		free(stack->sum_ops);
	}
}

void	global_sort(t_stack *stack)
{
	int	min;
	int	index_of_min;

	while (stack->size_a > 5)
		pb(stack, 1);
	sort_five(stack);
	start_sorting(stack);
	min = find_min(stack);
	index_of_min = get_index(stack, min);
	while (stack->a[0] != min)
	{
		if (index_of_min <= stack->size_a / 2)
			ra(stack, 1);
		else
			rra(stack, 1);
	}
}
