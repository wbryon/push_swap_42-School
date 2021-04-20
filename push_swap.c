#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack stack;
	int	i;
	int	j;
	char	*line;

	i = 0;
	stack.size_a = argc - 1;
	stack.size_b = 0;
	if (argc == 1)
	{
		write(1, "Error:wrong ARGC\n", 17);
		exit(-1);
	}
	stack.a = ft_calloc(argc - 1, sizeof(int));
	stack.b = ft_calloc(0, sizeof(int));
	while (argv[++i])
	{
		j = -1;
		while (argv[i][++j])
		{
			if (argv[i][0] == '-' && argv[i][j + 1])
				j++;
			if (!ft_isdigit(argv[i][j]))
			{
				write(2, "Error\n", 6);
				exit(-1);
			}
		}
	}
	i = -1;
	while (++i < argc - 1)
	{
		stack.a[i] = ft_atoi(argv[i + 1]);
		line = ft_itoa(stack.a[i]);
		write(1, line, ft_strlen(line));
		write(1, "\n", 1);
	}
	write(1, "\n", 1);
	check_range(stack.a, argc - 1);
	sort_five(&stack);
	i = -1;
	while (++i < stack.size_a)
		printf("i=|%d| stack_a=|%d| stack_b=|%d|\n", i, stack.a[i], stack.b[i]);
	return (0);
}
