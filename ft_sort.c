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
		case_d(stack);
	sort_three(stack);
	pa(stack);
	if (stack->a[0] == stack->max_a)
		ra(stack);
	pa(stack);
	if (stack->a[0] == stack->max_a)
		ra(stack);
}
/*
void	if_b_lower_then_min_a(t_stack *stack)
{
	int	i;

	i = -1;
	while (++i < stack->size_b)
	{
		if (stack->b[i] < stack->min_a)
		{
			if (i < stack->size_b / 2 + 1)
			{
				while (i > 0)
				{
					stack->op_name_b[i] = "rb";
					stack->op_count_b[i] = i;
				}
			}
			else
			{
				while (stack->b[i] != stack->b[0])
					rrb(stack);
			}
		}
	}
			
}

void	if_b_bigger_then_max_a(t_stack *stack)
{
	int	i;

	i = -1;
	while (++i < stack->size_b)
	{
		if (stack->b[i] > stack->max_a)
		{
			if (i < stack->size_b / 2 + 1)
			{
				while
			}
		}
	}
}*/

void	rot_finder(t_stack *stack)
{
	int	i;
	int	j;

	i = -1;
	stack->op_count_a = (int *)ft_calloc(stack->size_b, sizeof(int));
	stack->op_count_b = (int *)ft_calloc(stack->size_b, sizeof(int));
	stack->op_name_a = (char **)ft_calloc(stack->size_b, sizeof(char *));
	stack->op_name_b = (char **)ft_calloc(stack->size_b, sizeof(char *));
	while (++i < stack->size_b)
	{
		if (i < stack->size_b / 2 + 1)
		{
			stack->op_name_b[i] = "rb";
			stack->op_count_b[i] = i;
			printf("i=%3d  size_a=%d  %3s  %d   stack_a=%d\n", i, stack->size_a, stack->op_name_a[i], stack->op_count_a[i], stack->a[i]);
			printf("i=%3d  size_b=%d  %3s  %d   stack_b=%d\n", i, stack->size_b, stack->op_name_b[i], stack->op_count_b[i], stack->b[i]);
			printf("\n");
		}
		else
		{
			stack->op_name_b[i] = "rrb";
			stack->op_count_b[i] = stack->size_b - i;
			printf("i=%3d  size_a=%d  %3s  %d   stack_a=%d\n", i, stack->size_a, stack->op_name_a[i], stack->op_count_a[i], stack->a[i]);
			printf("i=%3d  size_b=%d  %3s  %d   stack_b=%d\n", i, stack->size_b, stack->op_name_b[i], stack->op_count_b[i], stack->b[i]);
			printf("\n");
		}
		j = -1;
		while (++j < stack->size_a - 1)
		{
			if (stack->b[i] < stack->min_a || stack->b[i] > stack->max_a)
			{
				stack->op_name_a[i] = "ra";
				stack->op_count_a[i] = 0;
				printf("i=%3d  size_a=%d  %3s  %d   stack_a=%d\n", i, stack->size_a, stack->op_name_a[i], stack->op_count_a[i], stack->a[i]);
				printf("i=%3d  size_b=%d  %3s  %d   stack_b=%d\n", i, stack->size_b, stack->op_name_b[i], stack->op_count_b[i], stack->b[i]);
				printf("\n");
			}
			if (stack->b[i] > stack->a[j] && stack->b[i] < stack->a[j + 1])
			{
				if (j < stack->size_a / 2)
				{
					stack->op_name_a[i] = "ra";
					stack->op_count_a[i] = j + 1;
					printf("i=%3d  size_a=%d  %3s  %d   stack_a=%d\n", i, stack->size_a, stack->op_name_a[i], stack->op_count_a[i], stack->a[i]);
					printf("i=%3d  size_b=%d  %3s  %d   stack_b=%d\n", i, stack->size_b, stack->op_name_b[i], stack->op_count_b[i], stack->b[i]);
					printf("\n");
				}
				else
				{
					stack->op_name_a[i] = "rra";
					stack->op_count_a[i] = stack->size_a - j - 1;
					printf("i=%3d  size_a=%d  %3s  %d   stack_a=%d\n", i, stack->size_a, stack->op_name_a[i], stack->op_count_a[i], stack->a[i]);
					printf("i=%3d  size_b=%d  %3s  %d   stack_b=%d\n", i, stack->size_b, stack->op_name_b[i], stack->op_count_b[i], stack->b[i]);
					printf("\n");
				}
			}
		}
	}
}

void	rot_calc(t_stack *stack)
{
	int	i;

	i = -1;
	rot_finder(stack);
	stack->sum_ops = ft_calloc(stack->size_b, sizeof(int));
	while (++i < stack->size_b)
	{
		if (ft_strcmp(stack->op_name_a[i], "ra") == 0 && ft_strcmp(stack->op_name_b[i], "rb") == 0)
		{
			if (stack->op_count_a[i] >= stack->op_count_b[i])
				stack->sum_ops[i] = stack->op_count_a[i];
			else
				stack->sum_ops[i] = stack->op_count_b[i];
		}
		else if (ft_strcmp(stack->op_name_a[i], "rra") == 0 && ft_strcmp(stack->op_name_b[i], "rrb") == 0)
		{
			if (stack->op_count_a[i] >= stack->op_count_b[i])
				stack->sum_ops[i] = stack->op_count_a[i];
			else
				stack->sum_ops[i] = stack->op_count_b[i];
		}
		else
			stack->sum_ops[i] = stack->op_count_a[i] + stack->op_count_b[i];
	}
}

void	do_rr(t_stack *stack)
{
	int	i;
	int	j;
	//int	k;

	push_to_b(stack);
	sort_five(stack);
	while (stack->size_b > 0)
	{
		i = -1;
		while (++i < stack->size_b)
		{
			rot_calc(stack);
			/*k = -1;
			printf("\n");
			while (++k < stack->size_b)
				printf("k=%3d  size_b=%d  %3s  %d   stack_b=%d\n",k, stack->size_b, stack->op_name_b[k], stack->op_count_b[k], stack->b[k]);
			k = -1;
			printf("\n");
			while (++k < stack->size_a)
				printf("k=%3d  size_a=%d  %3s  %d   stack_a=%d\n",k, stack->size_a, stack->op_name_a[k], stack->op_count_a[k], stack->a[k]);*/
			j = 0;
			if (ft_strcmp(stack->op_name_a[i], "ra") == 0 && ft_strcmp(stack->op_name_b[i], "rb") == 0)
			{
				if (stack->op_count_a[i] > stack->op_count_b[i])
				{
					while (j < stack->op_count_b[i])
					{
							rr(stack);
							j++;
					}
					while (j < stack->op_count_a[i])
					{
							ra(stack);
							j++;
					}
				}
				else if (stack->op_count_a[i] < stack->op_count_b[i])
				{
					while (j < stack->op_count_a[i])
					{
							rr(stack);
							j++;
					}
					while (j < stack->op_count_b[i])
					{
							rb(stack);
							j++;
					}
				}
				else
				{
					while (j < stack->op_count_a[i])
					{
						rr(stack);
						j++;
					}
				}
			}
			else if (ft_strcmp(stack->op_name_a[i], "rra") == 0 && ft_strcmp(stack->op_name_b[i], "rrb") == 0)
			{
				if (stack->op_count_a[i] > stack->op_count_b[i])
				{
					while (j < stack->op_count_b[i])
					{
						rrr(stack);
						j++;
					}
					while (j < stack->op_count_a[i])
					{
						rra(stack);
						j++;
					}
				}
				else if (stack->op_count_a[i] < stack->op_count_b[i])
				{
					while (j < stack->op_count_a[i])
					{
						rrr(stack);
						j++;
					}
					while (j < stack->op_count_b[i])
					{
						rrb(stack);
						j++;
					}
				}
				else
				{
					while (j < stack->op_count_a[i])
					{
						rrr(stack);
						j++;
					}
				}
			}
			else
			{
				if (stack->op_count_a[i] > 0 && stack->op_count_b[i] > 0)
				{
					if (ft_strcmp(stack->op_name_a[i], "ra") == 0 && ft_strcmp(stack->op_name_b[i], "rrb") == 0)
					{
						while (j < stack->op_count_a[i])
						{
							ra(stack);
							j++;
						}
						while (j < stack->sum_ops[i])
						{
							rrb(stack);
							j++;
						}
					}
					else if (ft_strcmp(stack->op_name_a[i], "rra") == 0 && ft_strcmp(stack->op_name_b[i], "rb") == 0)
					{
						while (j < stack->op_count_a[i])
						{
							rra(stack);
							j++;
						}
						while (j < stack->sum_ops[i])
						{
							rb(stack);
							j++;
						}
					}
					else
					{
						while (j < stack->op_count_a[i])
						{
							ra(stack);
							j++;
						}
						while (j < stack->sum_ops[i])
						{
							rb(stack);
							j++;
						}
					}
				}
				else if (stack->op_count_a[i] > 0 && stack->op_count_b[i] == 0)
				{
					if (ft_strcmp(stack->op_name_a[i], "ra") == 0)
					{
						while (j < stack->op_count_a[i])
						{
							ra(stack);
							j++;
						}
					}
					else if (ft_strcmp(stack->op_name_a[i], "rra") == 0)
					{
						while (j < stack->op_count_a[i])
						{
							rra(stack);
							j++;
						}
					}
				}
				else if (stack->op_count_a[i] == 0 && stack->op_count_b[i] > 0)
				{
					if (ft_strcmp(stack->op_name_b[i], "rb") == 0)
					{
						while (j < stack->op_count_b[i])
						{
							rb(stack);
							j++;
						}
					}
					else if (ft_strcmp(stack->op_name_b[i], "rrb") == 0)
					{
						while (j < stack->op_count_b[i])
						{
							rrb(stack);
							j++;
						}
					}
				}
			}
			pa(stack);
			while (stack->a[0] != stack->min_a)
				ra(stack);
			/*k = -1;
			printf("\n");
			while (++k < stack->size_b)
				printf("k=%3d   %3s  %d   stack_b=%d\n",k, stack->op_name_b[k], stack->op_count_b[k], stack->b[k]);
			k = -1;
			printf("\n");
			while (++k < stack->size_a)
				printf("k=%3d   %3s  %d   stack_a=%d\n",k, stack->op_name_a[k], stack->op_count_a[k], stack->a[k]);*/
		}
	}
}
/*
void	do_rrr(t_stack *stack)
{
	int	i;
	int	j;

	i = -1;
	while (++i < stack->size_b)
	{
		j = -1;
		if (ft_strcmp(stack->op_name_a[i], "rra") == 0 && ft_strcmp(stack->op_name_b[i], "rrb") == 0)
		{
			if (stack->op_count_a[i] >= stack->op_count_b[i])
			{
				while (++j < stack->op_count_b[i])
					rrr(stack);
				while (j < stack->op_count_a[i])
					rra(stack);
			}
			else
			{
				while (++j < stack->op_count_a[i])
					rrr(stack);
				while (j < stack->op_count_b[i])
					rrb(stack);
			}
		}
	}
}

void	multi_dir(t_stack *stack)
{
	int	i;

	i = -1;
	while (i < stack->size_b)
	{
		if (stack->op_count_a[i] > 0 && stack->op_count_b[i] > 0)
		{
			if (ft_strcmp(stack->op_name_a[i], "ra") == 0 && ft_strcmp(stack->op_name_b[i], "rrb") == 0)
			{
				while (i < stack->op_count_a[i])
					ra(stack);
				while (i < stack->sum_ops[i])
					rrb(stack);
			}
			else if (ft_strcmp(stack->op_name_a[i], "rra") == 0 && ft_strcmp(stack->op_name_b[i], "rb") == 0)
			{
				while (i < stack->op_count_a[i])
					rra(stack);
				while (i < stack->sum_ops[i])
					rb(stack);
			}
		}
		else if (stack->op_count_a[i] > 0 && stack->op_count_b[i] == 0)
		{
			if (ft_strcmp(stack->op_name_a[i], "ra") == 0)
			{
				while (i < stack->op_count_a[i])
					ra(stack);
			}
			if (ft_strcmp(stack->op_name_a[i], "rra") == 0)
			{
				while (i < stack->op_count_a[i])
					rra(stack);
			}
		}
		else if (stack->op_count_a[i] == 0 && stack->op_count_b[i] > 0)
		{
			if (ft_strcmp(stack->op_name_b[i], "rb") == 0)
			{
				while (i < stack->op_count_b[i])
					rb(stack);
			}
			if (ft_strcmp(stack->op_name_b[i], "rrb") == 0)
			{
				while (i < stack->op_count_b[i])
					rrb(stack);
			}
		}
	}
}*/

void	global_sort(t_stack *stack)
{
	int	i;

	i = -1;
	rot_calc(stack);
	do_rr(stack);
}
