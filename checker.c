#include "push_swap.h"

void    do_commands(t_stack *stack, char *line)
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

void	read_commands(t_stack *stack)
{
	char	*line;

	line = NULL;
	while (get_next_line(0, &line))
	{
		do_commands(stack, line);
		free(line);
		line = NULL;
	}
	if (line)
	{
		free(line);
		line = NULL;
	}
}

int	main(int argc, char **argv)
{
	int		i;
	char	**buff;
	t_stack	stack;

	if (argc == 1)
		exit(1);
	init_vars(&stack);
	i = 1;
	while (i < argc)
	{
		buff = ft_split(argv[i], ' ');
		ft_fill_stack(&stack, buff);
		free(buff);
		i++;
	}
	check_range(&stack);
	read_commands(&stack);
	if (!ft_is_sorted(&stack) && !stack.size_b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free(stack.a);
	free(stack.b);
	return (0);
}