#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define WIDTH 800
# define HEIGHT 600
# define IMG_SIZE 500

# define GREY_1		0x333333
# define GREY_2		0x222222
# define YELLOW		0xF0D347

# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"
# include "gnl/get_next_line.h"
# include "mlx.h"
# include <stdio.h>

typedef	struct	s_buf
{
	int			w_coef;
	int			h_coef;
	int			*a_stack;
	int			index;
}				t_buf;

typedef struct	s_visual
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*data_addr;
	int			bpp;
	int			size_line;
	int			endian;
}				t_visual;

typedef struct	s_area
{
	int			x_start;
	int			x_end;
	int			y_start;
	int			y_end;
}				t_area;

typedef	struct	s_stack
{
	int			*a;
	int			*b;
	int			flag;
	int			num_of_ops;
	int			ops_min;
	int			pos_min;
	int			pos_max;
	int			min_a;
	int			max_a;
	int			size_a;
	int			size_b;
	int			*sum_ops;
	int			*op_count_a;
	int			*op_count_b;
	char        **op_name_a;
    char        **op_name_b;
}				t_stack;

void			sa(t_stack *stack, int flag);
void			sb(t_stack *stack, int flag);
void			ss(t_stack *stack, int flag);
void			pa(t_stack *stack, int flag);
void			pb(t_stack *stack, int flag);
void			ra(t_stack *stack, int flag);
void			rb(t_stack *stack, int flag);
void			rr(t_stack *stack, int flag);
void			rra(t_stack *stack, int flag);
void			rrb(t_stack *stack, int flag);
void			rrr(t_stack *stack, int flag);
void			do_ra_rrb(t_stack *stack, int i);
void			do_rra_rb(t_stack *stack, int i);
void			do_rr(t_stack *stack, int i);
void			do_rrr(t_stack *stack, int i);
void			case_a(t_stack *stack);
void			case_b(t_stack *stack);
void			case_c(t_stack *stack);
void			case_d(t_stack *stack);
void			if_sorted(t_stack *stack);
void			push_to_b(t_stack *stack);
void			find_min_max_a(t_stack *stack);
void			find_ops_min(t_stack *stack);
void			sort_three(t_stack *stack);
void			sort_five(t_stack *stack);
void			global_sort(t_stack *stack);
void			sort_hundred(t_stack *stack);
void			mid_a(t_stack *stack, int i);
void			get_commands_a(t_stack *stack);
void			get_commands_b(t_stack *stack);
void			get_commands(t_stack *s);
void			rot_calc(t_stack *stack);
void			init_vars(t_stack *stack);
void			flags(t_stack *s, int i);
void			ft_fill_stack(t_stack *stack, char **buff);
void			ft_check_args(char *str);
void			ft_split_args(int argc, char **argv, t_stack *stack);
int				check_range(t_stack *stack);
int				ft_is_sorted(t_stack *stack);
void			final_build(t_stack *stack);
void			free_all(t_stack *stack);
void			read_commands(t_stack *stack);
void			do_commands(t_stack *stack, char *line);
void			ft_error(void);
int				*ft_realloc(int *tmp, int value, int size, int flag);
int				get_next_min(t_stack *stack, t_buf *buffer);
void    		index_stack(t_stack *stack, t_buf *buffer);

#endif