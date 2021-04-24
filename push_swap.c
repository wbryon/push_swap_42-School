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
	stack.size_b = 0;
	stack.op_count_a = 0;
	stack.op_count_b = 0;
	stack.op_name_a = NULL;
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
	rot_finder(&stack);
	i = -1;
	//while (++i < stack.size_a)
	//	printf("%d %d\n", stack.a[i], stack.b[i]);
	//printf("   operations=|%d|\n\n", stack.num_of_ops);
	//if (stack.num_of_ops > 10)
	i = -1;
	while (++i < stack.size_b)
		printf("i=%d a=%d  %s  ops=%d      b=%s ops=%d  sum_ops=%d\n\n", i, stack.a[i], stack.op_name_a[i], stack.op_count_a[i], stack.op_name_b[i], stack.op_count_b[i], stack.sum_ops[i]);
	return (0);
}
