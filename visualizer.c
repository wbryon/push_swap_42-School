#include "visualizer.h"

int	exit_hook(void)
{
	exit(0);
	return (0);
}

static void	init_visualizer(t_visual *vs, t_stack *stack)
{
	vs->mlx = mlx_init();
	vs->w_coef = WIDTH / 2 / stack->size_a;
	vs->h_coef = HEIGHT / stack->size_a;
	vs->win = mlx_new_window(vs->mlx, WIDTH, HEIGHT, "Push Swap");
	vs->img = mlx_new_image(vs->mlx, WIDTH, HEIGHT);
	vs->data_addr = mlx_get_data_addr(vs->img,
			&vs->bpp, &vs->size_line, &vs->endian);
}

static void	visualizer(t_visual *vs, t_stack *stack)
{
	char	*line;

	mlx_hook(vs->win, 17, 0, exit_hook, vs);
	draw(vs, stack);
	line = NULL;
	while (get_next_line(0, &line))
	{
		do_cmd(stack, line);
		free(line);
		line = NULL;
		draw(ps, vs, stack);
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
	index_stack(&stack, &vs);
	init_visualizer(&vs, &stack);
	visualizer(&vs, &stack);
	free(stack.a);
	free(stack.b);
	return (0);
}
