#include "push_swap.h"

void	read_cmd(t_stack *stack)
{
	char	*line;

	line = NULL;
	while (get_next_line(0, &line))
	{
		do_cmd(stack, line);
		free(line);
		line = NULL;
	}
	if (line)
	{
		free(line);
		line = NULL;
	}
}

void	do_cmd(t_stack *stack, char *line)
{
	if (!ft_strcmp(line, "sa"))
		sa(stack, 0);
	else if (!ft_strcmp(line, "sb"))
		sb(stack, 0);
	else if (!ft_strcmp(line, "ss"))
		ss(stack, 0);
	else if (!ft_strcmp(line, "pa"))
		pa(stack, 0);
	else if (!ft_strcmp(line, "pb"))
		pb(stack, 0);
	else if (!ft_strcmp(line, "ra"))
		ra(stack, 0);
	else if (!ft_strcmp(line, "rb"))
		rb(stack, 0);
	else if (!ft_strcmp(line, "rr"))
		rr(stack, 0);
	else if (!ft_strcmp(line, "rra"))
		rra(stack, 0);
	else if (!ft_strcmp(line, "rrb"))
		rrb(stack, 0);
	else if (!ft_strcmp(line, "rrr"))
		rrr(stack, 0);
	else
		ft_error();
}
