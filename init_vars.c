#include "push_swap.h"

void	init_vars(t_stack *stack)
{
	stack->num_of_ops = 0;
	stack->flag = 0;
	stack->pos_min = 0;
	stack->pos_max = 0;;
	stack->min_a = 0;
	stack->max_a = 0;
	stack->size_a = 0;
	stack->size_b = 0;
	stack->ops_min = 0;
	stack->a = NULL;
	stack->b = NULL;
	stack->size_a = 0;
	stack->size_b = 0;
}