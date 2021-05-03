#include "push_swap.h"

static void	ft_split_args(int argc, char **argv, t_stack *stack)
{
	int		i;
	char	**buff;

	i = 1;
	while (i < argc)
	{
		buff = ft_split(argv[i], ' ');
		ft_fill_stack(stack, buff);
		free(buff);
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
	free_all(&stack);
	return (0);
}
