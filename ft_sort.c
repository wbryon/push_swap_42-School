#include "push_swap.h"

int	sort_three(t_stack *s)
{
	if (s->a[0] > s->a[1] && s->a[1] > s->a[2]
		&& s->a[2] < s->a[0])
	{
		sa(s);
		rra(s);
	}
	if (s->a[0] > s->a[1] && s->a[1] < s->a[2]
		&& s->a[2] < s->a[0])
		ra(s);
	if (s->a[0] < s->a[1] && s->a[1] > s->a[2]
		&& s->a[2] < s->a[0])
		rra(s);
	if (s->a[0] > s->a[1] && s->a[1] < s->a[2]
		&& s->a[2] > s->a[0])
		sa(s);
	if (s->a[0] < s->a[1] && s->a[1] > s->a[2]
		&& s->a[2] > s->a[0])
	{
		rra(s);
		sa(s);
	}
	return (0);
}

void	sort_five(t_stack *s)
{
	find_min_max_a(s);
	if (s->pos_max < 3 && s->pos_min < 3)
		case_a(s);
	else if (s->pos_max > 2 && s->pos_min > 2)
		case_b(s);
	else if ((s->pos_max == 0 || s->pos_min == 0)
		&& (s->pos_max > 3 || s->pos_min > 3))
		case_c(s);
	else
		case_d(s);
	sort_three(s);
	pa(s);
	if (s->a[0] == s->max_a)
		ra(s);
	pa(s);
	if (s->a[0] == s->max_a)
		ra(s);
}

void	if_max(t_stack *s, int i)
{
	if (s->b[i] > s->max_a)
	{
		if (s->pos_max < s->size_a / 2)
		{
			s->op_name_a[i] = "ra";
			s->op_count_a[i] = s->pos_max + 1;
		}
		else
		{
			s->op_name_a[i] = "rra";
			s->op_count_a[i] = s->size_a - s->pos_max - 1;
		}
	}
}

void	if_min(t_stack *s, int i)
{
	if (s->b[i] < s->min_a)
	{
		if (s->pos_min < s->size_a / 2 + 1)
		{
			s->op_name_a[i] = "ra";
			s->op_count_a[i] = s->pos_min;
		}
		else
		{
			s->op_name_a[i] = "rra";
			s->op_count_a[i] = s->size_a - s->pos_min;
		}
	}
}

void	mid_a(t_stack *s, int i)
{
	int	j;

	j = -1;
	while (++j < s->size_a - 1)
	{
		if (s->b[i] > s->a[j] && s->b[i] < s->a[j + 1])
		{
			if (j < s->size_a / 2)
			{
				s->op_name_a[i] = "ra";
				s->op_count_a[i] = j + 1;
			}
			else
			{
				s->op_name_a[i] = "rra";
				s->op_count_a[i] = s->size_a - j - 1;
			}
			j = s->size_a;
		}
	}
}

void	get_commands_a(t_stack *s)
{
	int	i;

	i = -1;
	while (++i < s->size_b)
	{
		find_min_max_a(s);
		if (s->b[i] > s->max_a)
			if_max(s, i);
		else if (s->b[i] < s->min_a)
			if_min(s, i);
		else
			mid_a(s, i);
	}
	//printf("sum_ops=%d   ops_min=%d   %-7s=%d   stack_b=%d   %-7s=%d\n", s->sum_ops[i], s->ops_min, s->op_name_a[i], s->op_count_a[i], s->b[i], s->op_name_b[i], s->op_count_b[i]);
	//printf("\n");
}

void	get_commands_b(t_stack *s)
{
	int	i;

	i = 0;
	while (++i < s->size_b)
	{
		if (i < s->size_b / 2 + 1)
		{
			s->op_name_b[i] = "rb";
			s->op_count_b[i] = i;
		}
		else
		{
			s->op_name_b[i] = "rrb";
			s->op_count_b[i] = s->size_b - i;
		}
	}
	if (s->size_b % 2 == 0)
		if (!ft_strcmp(s->op_name_a[s->size_b / 2], "rra"))
			s->op_name_a[s->size_b / 2] = "rrb";
}

void	get_commands(t_stack *s)
{
	get_commands_a(s);
	get_commands_b(s);
	}

void	rot_calc(t_stack *s, int i)
{
	s->sum_ops[0] = s->op_count_a[0];
	if (s->flag == 1)
	{
		if (s->op_count_a[i] >= s->op_count_b[i])
			s->sum_ops[i] = s->op_count_a[i];
		else
			s->sum_ops[i] = s->op_count_b[i];
	}
	else if (s->flag == 2)
	{
		if (s->op_count_a[i] >= s->op_count_b[i])
			s->sum_ops[i] = s->op_count_a[i];
		else
			s->sum_ops[i] = s->op_count_b[i];
	}
	else if (s->flag == 3 || s->flag == 4)
		s->sum_ops[i] = s->op_count_a[i] + s->op_count_b[i];
	else if (!s->op_name_a[i])
		s->sum_ops[i] = s->op_count_b[i];
		//printf("sum_ops=%d\n", s->sum_ops[i]);
		//printf("\n");
}

void	do_rr(t_stack *s, int i)
{
	int	j;

	{
		j = -1;
		if (s->op_count_a[i] > s->op_count_b[i])
		{
			while (++j < s->op_count_b[i])
				rr(s);
			while (j++ < s->op_count_a[i])
				ra(s);
			/*int k = -1;
			while (++k < s->size_a)
				printf("k=%d  rr=%d\n", k, s->a[k]);
			printf("\n");*/
		}
		else if (s->op_count_a[i] < s->op_count_b[i])
		{
			while (++j < s->op_count_a[i])
				rr(s);
			while (j++ < s->op_count_b[i])
				rb(s);
			/*k = -1;
			while (++k < s->size_a)
				printf("k=%d  rr=%d\n", k, s->a[k]);
			printf("\n");*/
		}
		else
		{
			while (++j < s->op_count_a[i])
				rr(s);
			/*k = -1;
			while (++k < s->size_a)
				printf("k=%d  rr=%d\n", k, s->a[k]);
			printf("\n");*/
		}
	}
}

void	do_rrr(t_stack *s, int i)
{
	int	j;

	j = 0;
	if (s->op_count_a[i] > s->op_count_b[i])
	{
		while (j < s->op_count_b[i])
		{
			rrr(s);
			j++;
		}
		while (j < s->op_count_a[i])
		{
			rra(s);
			j++;
		}
		/*int k = -1;
		while (++k < s->size_a)
			printf("k=%d  rrr=%d\n", k, s->a[k]);
		printf("\n");*/
	}
	else if (s->op_count_a[i] < s->op_count_b[i])
	{
		while (j < s->op_count_a[i])
		{
			rrr(s);
			j++;
		}
		while (j < s->op_count_b[i])
		{
			rrb(s);
			j++;
		}
		/*k = -1;
		while (++k < s->size_a)
			printf("k=%d  rrr=%d\n", k, s->a[k]);
		printf("\n");*/
	}
	else
	{
		while (j < s->op_count_a[i])
		{
			rrr(s);
			j++;
		}
		/*k = -1;
		while (++k < s->size_a)
			printf("k=%d  rrr=%d\n", k, s->a[k]);
		printf("\n");*/
	}
}

void	multi_dir(t_stack *s, int i)
{
	int	j;

	j = 0;
	//printf("i=%-2d  flag_dir=%d     stack_a=%d     %-4s %-5d  stack_b=%-5d  %-4s %-5d\n", i, s->flag, s->a[i], s->op_name_a[i], s->op_count_a[i], s->b[i], s->op_name_b[i], s->op_count_b[i]);
	if (s->op_count_a[i] > 0 && s->op_count_b[i] > 0)
	{
		if (s->flag == 3)
		{
			while (j < s->op_count_a[i])
			{
				ra(s);
				j++;
			}
			while (j < s->sum_ops[i])
			{
				rrb(s);
				j++;
			}
			/*int k = -1;
			while (++k < s->size_a)
				printf("k=%d  dir=%d\n", k, s->a[k]);
			printf("\n");*/
		}
		else if (s->flag == 4)
		{
			while (j < s->op_count_a[i])
			{
				rra(s);
				j++;
			}
			while (j < s->sum_ops[i])
			{
				rb(s);
				j++;
			}
			/*k = -1;
			while (++k < s->size_a)
				printf("k=%d  dir=%d\n", k, s->a[k]);
			printf("\n");*/
		}
		else
		{
			while (j < s->op_count_a[i])
			{
				ra(s);
				j++;
			}
			while (j < s->sum_ops[i])
			{
				rb(s);
				j++;
			}
			/*k = -1;
			while (++k < s->size_a)
				printf("k=%d  dir=%d\n", k, s->a[k]);
			printf("\n");*/
		}
	}
	else if (s->op_count_a[i] > 0 && s->op_count_b[i] == 0)
	{
		if (ft_strcmp(s->op_name_a[i], "ra") == 0)
		{
			while (j < s->op_count_a[i])
			{
				ra(s);
				j++;
			}
			/*k = -1;
			while (++k < s->size_a)
				printf("k=%d  dir=%d\n", k, s->a[k]);
			printf("\n");*/
		}
		else if (ft_strcmp(s->op_name_a[i], "rra") == 0)
		{
			while (j < s->op_count_a[i])
			{
				rra(s);
				j++;
			}
		}
			/*k = -1;
			while (++k < s->size_a)
				printf("k=%d  dir=%d\n", k, s->a[k]);
			printf("\n");*/
	}
	else if (s->op_count_a[i] == 0 && s->op_count_b[i] > 0)
	{
		if (ft_strcmp(s->op_name_b[i], "rb") == 0)
		{
			while (j < s->op_count_b[i])
			{
				rb(s);
				j++;
			}
			/*k = -1;
			while (++k < s->size_a)
				printf("k=%d  dir=%d\n", k, s->a[k]);
			printf("\n");*/
		}
		else if (ft_strcmp(s->op_name_b[i], "rrb") == 0)
		{
			while (j < s->op_count_b[i])
			{
				rrb(s);
				j++;
			}
			/*k = -1;
			while (++k < s->size_a)
				printf("k=%d  dir=%d\n", k, s->a[k]);
			printf("\n");*/
		}
	}
}

void	global_sort(t_stack *s)
{
	int	i;

	i = 0;
	push_to_b(s);
	s->op_count_a = (int *)ft_calloc(s->size_b, sizeof(int));
	s->op_count_b = (int *)ft_calloc(s->size_b, sizeof(int));
	s->op_name_a = (char **)ft_calloc(s->size_b, sizeof(char *));
	s->op_name_b = (char **)ft_calloc(s->size_b, sizeof(char *));
	s->sum_ops = (int *)ft_calloc(s->size_b, sizeof(int));
	sort_five(s);
	while (s->size_b)
	{
		find_min_max_a(s);
		get_commands(s);
		rot_calc(s, i);
		printf("sum_ops=%d  ops_min=%d\n", s->sum_ops[i], s->ops_min);
		find_ops_min(s);
		/*j = -1;
		while (++j < s->size_a)
		{
			printf("i=%d   sum_ops=%d   ops_min=%d   stack_a=%d   %-2s=%d   stack_b=%d   %-2s=%d  flag=%d\n", i, s->sum_ops[i], s->ops_min, s->a[i], s->op_name_a[i], s->op_count_a[i], s->b[i], s->op_name_b[i], s->op_count_b[i], s->flag);
			printf("\n");
		}*/
		//printf("i=%d   sum_ops=%d   ops_min=%d   stack_a=%d   %-2s=%d   stack_b=%d   %-2s=%d  flag=%d\n", i, s->sum_ops[i], s->ops_min, s->a[i], s->op_name_a[i], s->op_count_a[i], s->b[i], s->op_name_b[i], s->op_count_b[i], s->flag);
		printf("\n");
		if (s->sum_ops[i] == s->ops_min && s->flag == 1)
			do_rr(s, i);
		else if (s->sum_ops[i] == s->ops_min && s->flag == 2)
			do_rrr(s, i);
		else
			multi_dir(s, i);
		pa(s);
		i++;
	}
}
