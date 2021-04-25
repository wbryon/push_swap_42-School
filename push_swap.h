#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft/libft.h"

typedef	struct	s_stack
{
	int			*a;
	int			*b;
	int			num_of_ops;
	int			pos_min;
	int			pos_max;
	int			min_a;
	int			max_a;
	int			min_b;
	int			max_b;
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
void			find_min_max_b(t_stack *stack);
int				sort_three(t_stack *stack);
void			sort_five(t_stack *stack);
void			global_sort(t_stack *stack);
void			sort_hundred(t_stack *stack);
void			rot_finder(t_stack *stack);
void			rot_calc(t_stack *stack);
void			do_rr(t_stack *stack);
void			init_vars(t_stack *stack);
int				check_range(t_stack *stack);
