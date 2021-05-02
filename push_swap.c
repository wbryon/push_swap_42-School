#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack stack;
	int	i;
	int	j;
	char	*line;

	i = 0;
	init_vars(&stack);
	stack.size_a = argc - 1;
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
		//write(1, line, ft_strlen(line));
		//write(1, " ", 1);
	}
	//write(1, "\n", 1);
	check_range(&stack);
	global_sort(&stack);
	i = -1;
	printf("\n");
	while (++i < stack.size_a)
	printf("%d   ", stack.a[i]);
	printf("\n\n");
	//printf("   operations=|%d|\n\n", stack.num_of_ops);
	//if (stack.num_of_ops > 10)
	//i = -1;
	//printf("\n");
	//while (++i < stack.size_b)
	//	printf("i=%d  num_b=%d  op_b=%s  ops=%d\n\n", i, stack.b[i], stack.op_name_b[i], stack.op_count_b[i]);
	//i = -1;
	//printf("\n");
	//while (++i < stack.size_a)
	//	printf("i=%d  num_a=%d  op_a=%s  ops=%d\n\n", i, stack.a[i], stack.op_name_a[i], stack.op_count_a[i]);
	free_all(&stack);
	return (0);
}
