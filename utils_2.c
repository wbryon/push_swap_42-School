#include "push_swap.h"

void	if_sorted(t_stack *stack)
{
	int	i;
	int	flag;

	i = -1;
	flag = 0;
	while (++i < stack->size_a - 1)
	{
		if (stack->a[i] > stack->a[i + 1])
			flag = 1;
	}
	if (flag == 0)
		write(1, "sorted\n", 7);
}

void	push_to_b(t_stack *stack)
{
	int	i;

	i = -1;
	while (stack->size_a > 5)
		pb(stack);
}

void	free_all(t_stack *stack)
{
	free(stack->op_count_a);
	free(stack->op_count_b);
	free(stack->op_name_a);
	free(stack->op_name_b);
	free(stack->sum_ops);
}

void	flags(t_stack *s, int i)
{
	s->op_name_b[0] = "rb";
	s->op_name_a[0] = "ra";
	if (ft_strcmp(s->op_name_a[i], "ra") == 0 && ft_strcmp(s->op_name_b[i], "rb") == 0)
		s->flag = 1;
	else if (ft_strcmp(s->op_name_a[i], "rra") == 0 && ft_strcmp(s->op_name_b[i], "rrb") == 0)
		s->flag = 2;
	else if (ft_strcmp(s->op_name_a[i], "ra") == 0 && ft_strcmp(s->op_name_b[i], "rrb") == 0)
		s->flag = 3;
	else if (ft_strcmp(s->op_name_a[i], "rra") == 0 && ft_strcmp(s->op_name_b[i], "rb") == 0)
		s->flag = 4;
	else
		s->flag = 5;
}