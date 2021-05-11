#ifndef VISUALIZER_H
# define VISUALIZER_H
# define WIDTH 2000
# define HEIGHT 1000
# define GREY_1 0x333333
# define GREY_2 0x222222
# define YELLOW 0xFF0000

# include "push_swap.h"
# include <mlx.h>

typedef struct s_visual
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*data_addr;
	int		bpp;
	int		size_line;
	int		endian;
	double	w_coef;
	double	h_coef;
	int		*a_stack;
	int		index;
}			t_visual;

typedef struct s_area
{
	int		x_start;
	int		x_end;
	int		y_start;
	int		y_end;
}			t_area;

void		index_stack(t_visual *visual, t_stack *stack);
int			get_next_min(t_stack *stack, t_visual *visual);
t_area		*create_area(int x_start, int x_end, int y_start, int y_end);
void		draw(t_visual *vs, t_stack *stack);

#endif
