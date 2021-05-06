#include "visualizer.h"

static void	put_pixel(t_visual *vs, int x, int y, int color)
{
	int		i;

	i = (x * vs->bpp / 8) + (y * vs->size_line);
	vs->data_addr[i] = color;
	vs->data_addr[++i] = color >> 8;
	vs->data_addr[++i] = color >> 16;
}

static void	draw_area(t_visual *vs, t_area *rectangle)
{
	int	x;
	int	y;
	int	width;
	int	height;

	x = rectangle->x_start;
	width = rectangle->x_end;
	height = rectangle->y_end;
	while (x < width)
	{
		y = rectangle->y_start;
		while (y < height)
		{
			put_pixel(vs, x, y, YELLOW);
			y++;
		}
		x++;
	}
}

static void	draw_stack(t_visual *vs, int *stack, int x_start, int size)
{
	int		i;
	t_area	*area;

	i = 0;
	while (i < size)
	{
		area = create_area(x_start, x_start + (stack[i] + 1) * vs->w_coef,
				i * vs->h_coef, (i + 1) * vs->h_coef);
		draw_area(vs, area);
		free(area);
		i++;
	}
}

static void	draw_background(t_visual *vs)
{
	int	*image;
	int	i;

	ft_bzero(vs->data_addr, WIDTH * HEIGHT * (vs->bpp / 8));
	image = (int *)(vs->data_addr);
	i = -1;
	while (++i < HEIGHT * WIDTH)
	{
		if (i % WIDTH < WIDTH / 2)
			image[i] = GREY_1;
		else
			image[i] = GREY_2;
	}
}

void	draw(t_visual *vs, t_stack *stack)
{
	draw_background(vs);
	draw_stack(vs, stack->a, 0, stack->size_a);
	draw_stack(vs, stack->b, WIDTH / 2, stack->size_b);
	mlx_put_image_to_window(vs->mlx, vs->win, vs->img, 0, 0);
	mlx_do_sync(vs->mlx);
}
