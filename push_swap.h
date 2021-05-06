#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"
# include "gnl/get_next_line.h"
# include "mlx.h"
# include <stdio.h>

typedef struct s_stack
{
	int			do_a;
	int			do_b;
	int			do_ab;
	int			index;
	int			*op_count_a;
	int			*op_count_b;
	int			*sum_ops;
	int			*a;
	int			*b;
	int			size_a;
	int			size_b;
	char		**op_name_a;
	char		**op_name_b;
}				t_stack;

void	sa(t_stack *stack, int flag);
void	sb(t_stack *stack, int flag);
void	ss(t_stack *stack, int flag);
void	pa(t_stack *stack, int flag);
void	pb(t_stack *stack, int flag);
void	ra(t_stack *stack, int flag);
void	rb(t_stack *stack, int flag);
void	rr(t_stack *stack, int flag);
void	rra(t_stack *stack, int flag);
void	rrb(t_stack *stack, int flag);
void	rrr(t_stack *stack, int flag);
void	init_stack(t_stack *stack);
void	check_isdigit(char *str);
void	check_range(t_stack *stack);
void	do_cmd(t_stack *stack, char *line);
void	sort_three(t_stack *stack);
void	sort_five(t_stack *stack);
void	global_sort(t_stack *stack);
int		find_max(t_stack *stack);
int		find_min(t_stack *stack);
int		get_index(t_stack *stack, int elem);
void	read_cmd(t_stack *stack);
int		is_sorted(t_stack *stack);
void	fill_stack(t_stack *stack, char **buff);
void	get_cmd_a(t_stack *stack);
void	get_cmd_b(t_stack *stack);
void	get_sum_ops(t_stack *stack);
void	find_min_cmd(t_stack *stack);
void	get_min_cmd(t_stack *stack);
void	execute_min_cmd(t_stack *stack);

#endif