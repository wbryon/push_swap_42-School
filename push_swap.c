#include "push_swap.h"

void	ft_split_args(int argc, char **argv, t_stack *stack)
{
	int		i;
	char	**buffer;

	i = 1;
	while (i < argc)
	{
		buffer = ft_split(argv[i], ' ');
		ft_fill_stack(stack, buffer);
		free(buffer);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_stack stack;

	if (argc == 1)
		exit(-1);
	init_vars(&stack);
	ft_split_args(argc, argv, &stack);
	check_range(&stack);
	global_sort(&stack);
	while (stack.a[0] != stack.min_a)
	{
		if (stack.pos_min <= stack.size_a / 2)
			ra(&stack, 1);
		else
			rra(&stack, 1);
	}
	
	free_all(&stack);
	return (0);
}