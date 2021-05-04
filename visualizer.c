#include "push_swap.h"

static	void	visualizer(t_visual *vs, t_buf *ps, t_stack *stack)
{
	size_t			size;
	char			*line;

	line = NULL;
	mlx_hook(vs->win, 17, 0, close, vs);
	draw(ps, vs);
	while ((size = get_next_line(0, &line)) > 0)
	{
		do_commands(stack, line);
		free(line);
		line = NULL;
		draw(ps, vs);
	}
	if (line)
	{
		free(line);
		line = NULL;
	}
	mlx_loop(vs->mlx);
}

int	main(int argc, char **argv)
{
	int			i;
	char		**buff;
	t_stack		stack;
	t_visual	vs;
	t_buf		ps;

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
	index_stack(&stack, &ps);
	visualizer(&vs, &ps, &stack);
	free(stack.a);
	free(stack.b);
	return (0);
}