#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft/libft.h"

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

int				sa(t_stack *stack);
int				sb(t_stack *stack);
int				ss(t_stack *stack);
int				pa(t_stack *stack);
int				pb(t_stack *stack);
int				ra(t_stack *stack);
int				rb(t_stack *stack);
int				rr(t_stack *stack);
int				rra(t_stack *stack);
int				rrb(t_stack *stack);
int				rrr(t_stack *stack);
void			case_a(t_stack *stack);
void			case_b(t_stack *stack);
void			case_c(t_stack *stack);
void			case_d(t_stack *stack);
void			if_sorted(t_stack *stack);
void			push_to_b(t_stack *stack);
void			find_min_max_a(t_stack *stack);
void			find_ops_min(t_stack *stack);
int				sort_three(t_stack *stack);
void			sort_five(t_stack *stack);
void			global_sort(t_stack *stack);
void			sort_hundred(t_stack *stack);
void			mid_a(t_stack *stack, int i);
void			get_commands_a(t_stack *stack);
void			get_commands_b(t_stack *stack);
void			get_commands(t_stack *s);
void			rot_calc(t_stack *stack);
void			do_rr(t_stack *stack, int i);
void			do_rrr(t_stack *stack, int i);
void			multi_dir(t_stack *stack, int i);
void			init_vars(t_stack *stack);
void			flags(t_stack *s, int i);
int				check_range(t_stack *stack);
void			free_all(t_stack *stack);
