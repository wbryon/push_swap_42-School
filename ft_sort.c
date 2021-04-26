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
	stack->op_count_a = (int *)ft_calloc(stack->size_a, sizeof(int));
	stack->op_count_b = (int *)ft_calloc(stack->size_b, sizeof(int));
	stack->op_name_a = (char **)ft_calloc(stack->size_a, sizeof(char *));
	stack->op_name_b = (char **)ft_calloc(stack->size_b, sizeof(char *));
	while (++i < stack->size_b)
	{
		if (i < stack->size_b / 2 + 1)
		{
			stack->op_name_b[i] = "rb";
			stack->op_count_b[i] = i;
			//printf("b=%d   %5s  %d\n\n", stack->b[i], stack->op_name_b[i], stack->op_count_b[i]);
		}
		else
		{
			stack->op_name_b[i] = "rrb";
			stack->op_count_b[i] = stack->size_b - i;
			//printf("b=%d   %5s  %d\n\n", stack->b[i], stack->op_name_b[i], stack->op_count_b[i]);
		}
		j = -1;
		while (++j < stack->size_a - 1)
		{
			//printf("a=%d   b=%d\n\n", stack->a[j], stack->b[i]);
			if (stack->b[i] > stack->max_a)
			{
				if (stack->pos_max < stack->size_a / 2 + 1)
				{
					stack->op_name_a[j] = "ra";
					stack->op_count_a[j] = j + 1;
					//printf("b=%d   %5s  %d\n\n", stack->b[i], stack->op_name_a[j], stack->op_count_a[j]);
					break ;
				}
				else
				{
					stack->op_name_a[j] = "rra";
					stack->op_count_a[j] = stack->size_a - stack->pos_max - 1;
					//printf("b=%d   %5s  %d\n\n", stack->b[i], stack->op_name_a[j], stack->op_count_a[j]);
					break ;
				}
			}
			else if (stack->b[i] < stack->min_a)
			{
				if (stack->pos_min < stack->size_a / 2 + 1)
				{
					stack->op_name_a[j] = "ra";
					stack->op_count_a[j] = j;
					//printf("b=%d   %5s  %d\n\n", stack->b[i], stack->op_name_a[j], stack->op_count_a[j]);
					break ;
				}
				else
				{
					stack->op_name_a[j] = "rra";
					stack->op_count_a[j] = stack->size_a - j;
					//printf("b=%d   %5s  %d\n\n", stack->b[i], stack->op_name_a[j], stack->op_count_a[j]);
					break ;
				}
			}
			else if (stack->b[i] > stack->a[j] && stack->b[i] < stack->a[j + 1])
			{
				if (j < stack->size_a / 2)
				{
					stack->op_name_a[j] = "ra";
					stack->op_count_a[j] = j + 1;
					//printf("b=%d   %5s  %d\n\n", stack->b[i], stack->op_name_a[j], stack->op_count_a[j]);
					break ;
				}
				else
				{
					stack->op_name_a[j] = "rra";
					stack->op_count_a[j] = stack->size_a - j - 1;
					//printf("a=%d   %5s  %d\n\n", stack->a[j], stack->op_name_a[j], stack->op_count_a[j]);
					break ;
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
		//printf("%s\n\n", stack->op_name_a[i]);
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
	int	k;

	push_to_b(stack);
	sort_five(stack);
	while (stack->size_b > 0)
	{
		i = -1;
		while (++i < stack->size_b)
		{
			find_min_max_a(stack);
			rot_calc(stack);
			k = -1;
			printf("\n");
			while (++k < stack->size_b)
				printf("k=%d   %-8s %d   stack_b=%d\n",k, stack->op_name_b[k], stack->op_count_b[k], stack->b[k]);
			k = -1;
			printf("\n");
			while (++k < stack->size_a)
				printf("k=%d   %-8s %d   stack_=%d\n",k, stack->op_name_a[k], stack->op_count_a[k], stack->a[k]);
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
			k = -1;
			printf("\n");
			while (++k < stack->size_b)
				printf("k=%d   %-8s %d   stack_b=%d\n", k, stack->op_name_b[k], stack->op_count_b[k], stack->b[k]);
			k = -1;
			printf("\n");
			while (++k < stack->size_a)
				printf("k=%d   %-8s %d   stack_=%d\n", k, stack->op_name_a[k], stack->op_count_a[k], stack->a[k]);
			//k = -1;
			//printf("\n");
			//while (++k < stack->size_a)
			//	printf("k=%3d   stack_a=%d\n",k, stack->a[k]);
		}
	}
}

/*void	do_rrr(t_stack *stack)
{
	int	i;
	int	j;

	i = -1;
	while (++i < stack->size_b)
	{
		j = 0;
		if (ft_strcmp(stack->op_name_a[i], "rra") == 0 && ft_strcmp(stack->op_name_b[i], "rrb") == 0)
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
