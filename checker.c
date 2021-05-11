#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		i;
	char	**buff;
	t_stack	stack;

	if (argc == 1)
		exit(1);
	init_stack(&stack);
	i = 1;
	while (i < argc)
	{
		buff = ft_split(argv[i], ' ');
		fill_stack(&stack, buff);
		free(buff);
		i++;
	}
	check_range(&stack);
	read_cmd(&stack);
	if (!is_sorted(&stack) && !stack.size_b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free(stack.a);
	free(stack.b);
	return (0);
}
