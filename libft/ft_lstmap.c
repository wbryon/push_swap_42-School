/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbryon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 16:54:39 by wbryon            #+#    #+#             */
/*   Updated: 2021/04/16 14:40:08 by wbryon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_head;
	t_list	*new_next;
	t_list	*tmp;

	if (lst == NULL)
		return (NULL);
	new_head = ft_lstnew(f(lst->content));
	if (new_head == NULL)
		return (NULL);
	tmp = new_head;
	lst = lst->next;
	while (lst)
	{
		new_next = ft_lstnew(f(lst->content));
		if (new_next == NULL)
		{
			ft_lstclear(&new_head, del);
			return (NULL);
		}
		tmp->next = new_next;
		tmp = new_next;
		lst = lst->next;
	}
	return (new_head);
}
