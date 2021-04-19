#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft/libft.h"

typedef	struct	s_stack
{
	int			*a;
	int			*b;
	int			size_a;
	int			size_b;
}				t_stack;

int				check_range(int *range, int count);
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
