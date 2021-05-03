#include "push_swap.h"

void	if_max(t_stack *s, int i)
{
	if (s->pos_max < s->size_a / 2 + 1)
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
				break ;
			}
			else
			{
				s->op_name_a[i] = "rra";
				s->op_count_a[i] = s->size_a - j - 1;
				break ;
			}
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
	sort_five(s);
	s->op_count_a = (int *)ft_calloc(s->size_b, sizeof(int));
	s->op_count_b = (int *)ft_calloc(s->size_b, sizeof(int));
	s->op_name_a = (char **)ft_calloc(s->size_b, sizeof(char *));
	s->op_name_b = (char **)ft_calloc(s->size_b, sizeof(char *));
	s->sum_ops = (int *)ft_calloc(s->size_b, sizeof(int));
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
			if (s->sum_ops[i] == s->ops_min && s->flag == 1)
				do_rr(s, i);
			if (s->sum_ops[i] == s->ops_min && s->flag == 2)
				do_rrr(s, i);
			if (s->sum_ops[i] == s->ops_min && s->flag == 3)
				do_ra_rrb(s, i);
			if (s->sum_ops[i] == s->ops_min && s->flag == 4)
				do_rra_rb(s, i);
		}
	}
}