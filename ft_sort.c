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
	if (s->pos_max < s->size_a / 2 + 1)
	{
		printf("pos_max=%d\n", s->pos_max);
		s->op_name_a[i] = "ra";
		s->op_count_a[i] = s->pos_max + 1;
	}
	else
	{
		s->op_name_a[i] = "rra";
		s->op_count_a[i] = s->size_a - s->pos_max - 1;
	}
}

void	if_min(t_stack *s, int i)
{
	if (s->a[i] < s->size_a / 2 + 1)
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
		if (s->b[i] > s->max_a)
			if_max(s, i);
		else if (s->b[i] < s->min_a)
			if_min(s, i);
		else
			mid_a(s, i);
	}
}

void	get_commands_b(t_stack *s)
{
	int	i;

	i = -1;
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
		if (ft_strcmp(s->op_name_a[s->size_b / 2], "rra") == 0)
			s->op_name_b[s->size_b / 2] = "rrb";
}

void	get_commands(t_stack *s)
{
	get_commands_a(s);
	get_commands_b(s);
}

void	rot_calc(t_stack *s)
{
	int	i;

	i = -1;
	s->sum_ops[0] = s->op_count_a[0];
	while (++i < s->size_b)
	{
		flags(s, i);
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
	}
}

void	global_sort(t_stack *s)
{
	int	i;
	push_to_b(s);
	s->op_count_a = (int *)ft_calloc(s->size_b, sizeof(int));
	s->op_count_b = (int *)ft_calloc(s->size_b, sizeof(int));
	s->op_name_a = (char **)ft_calloc(s->size_b, sizeof(char *));
	s->op_name_b = (char **)ft_calloc(s->size_b, sizeof(char *));
	s->sum_ops = (int *)ft_calloc(s->size_b, sizeof(int));
	sort_five(s);
	while (s->size_b)
	{
		i = -1;
		while (++i < s->size_b)
		{
			find_min_max_a(s);
			get_commands_a(s);
			get_commands_b(s);
			rot_calc(s);
			find_ops_min(s);
			flags(s, i);
			int k = -1;
			while (++k < s->size_a)
				printf("i=%d   a=%d\n", i, s->a[k]);
			printf("\n");
			printf("after  cycle: i=%d  op_min=%d  b=%d  %-4s  %d  %-4s  %d\n", s->ops_min, i, s->b[i], s->op_name_a[i], s->op_count_a[i], s->op_name_b[i], s->op_count_b[i]);
			if (s->sum_ops[i] == s->ops_min && s->flag == 1)
			{
				do_rr(s, i);
				pa(s);
				break ;
			}
			if (s->sum_ops[i] == s->ops_min && s->flag == 2)
			{
				do_rrr(s, i);
				pa(s);
			}
			if (s->sum_ops[i] == s->ops_min && s->flag == 3)
			{
				do_ra_rrb(s, i);
				pa(s);
				break ;
			}
			if (s->sum_ops[i] == s->ops_min && s->flag == 4)
			{
				do_rra_rb(s, i);
				pa(s);
				break ;
			}
		}
	}
}