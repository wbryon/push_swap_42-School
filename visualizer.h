#ifndef VISUAL_H
# define VISUAL_H
# define WIDTH 2000
# define HEIGHT 1000
# define GREY_1 0x333333
# define GREY_2 0x222222
# define YELLOW 0xFF0000

# include "push_swap.h"
#include <mlx.h>

typedef struct	s_visual
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*data_addr;
	int			bpp;
	int			size_line;
	int			endian;
	int			w_coef;
	int			h_coef;
	int			*a_stack;
	int			index;
}				t_visual;

typedef struct	s_area
{
	int			x_start;
	int			x_end;
	int			y_start;
	int			y_end;
}				t_area;

void			index_stack(t_stack *stack, t_buf *buffer);
int				get_next_min(t_stack *stack, t_buf *buffer);
void			draw(t_buf *ps, t_visual *vs, t_stack *stack);

#endif
