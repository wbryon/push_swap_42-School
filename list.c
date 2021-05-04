#include "push_swap.h"

t_arg   *ft_lstnew(int number, int index)
{
	t_arg   *new;

	new = (t_arg *)malloc(sizeof(t_arg));
	if (!new)
		return (NULL);
	new->number = number;
    new->index = index;
	new->next = NULL;
	return (new);
}

void	ft_lstadd_front(t_arg **lst, t_arg *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

    void	ft_lstadd_back(t_arg **lst, t_arg *new)
{
	t_arg	*last;

	if (!lst || !new)
		return ;
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	new->next = last->next;
	last->next = new;
}

t_arg	*ft_lstlast(t_arg *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void add_last(t_stack *stack, t_elem *elem)
{
    int i;
    t_arg   *arg;

    elem->a = (t_arg *)malloc(sizeof(t_arg));
    i = -1;
    elem->len_a = 0;
    while (++i < stack->size_a)
    {
        arg = ft_lstnew(stack->a[i], -1);
        ft_lstadd_back(&elem->a, arg);
        elem->len_a++;
    }
    int k = 0;
    while (k < elem->len_a)
    {
        elem->a = elem->a->next;
        //printf("after %d  %d\n", elem->a->number, elem->a->index);
		k++;
    }
}