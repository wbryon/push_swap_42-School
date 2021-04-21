#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft/libft.h"

typedef	struct	s_stack
{
	int			*a;
	int			*b;
	int			op_count;
	int			min_a;
	int			max_a;
	int			size_a;
	int			size_b;
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
void			find_min_max(t_stack *stack);
int				sort_three(t_stack *stack);
int				sort_five(t_stack *stack);
int				check_range(int *range, int count);
