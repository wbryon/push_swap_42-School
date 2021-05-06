#include "push_swap.h"

static void	split_args(int argc, char **argv, t_stack *stack)
{
	int		i;
	char	**buffer;

	i = 0;
	while (++i < argc)
	{
		buffer = ft_split(argv[i], ' ');
		fill_stack(stack, buffer);
		free(buffer);
	}
}

int	main(int argc, char **argv)
{
	t_stack stack;

	if (argc == 1)
		exit(-1);
	init_stack(&stack);
	split_args(argc, argv, &stack);
	check_range(&stack);
	if (stack.size_a <= 3)
		sort_three(&stack);
	else if (stack.size_a <= 5)
		sort_five(&stack);
	else
		global_sort(&stack);
	
	free(stack.a);
	free(stack.b);
	return (0);
}