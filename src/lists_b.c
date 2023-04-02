/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 18:00:47 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/04/02 18:15:56 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	t_list	*first;

	first = *lst;
	if (*lst != NULL)
		first->prev = new;
	new->prev = NULL;
	new->next = first;
	*lst = new;
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	last = ft_lstlast(*lst);
	if (last == NULL)
	{
		*lst = new;
		new->prev = NULL;
		new->next = NULL;
	}
	else
	{
		last->next = new;
		new->prev = last;
		new->next = NULL;
	}
}

t_list	*ft_search_from(t_stack *stack, int chunk, int dir)
{
	t_list	*l;
	t_list	*node;

	if (dir == -1)
		l = ft_lstlast(stack->numbers);
	else
		l = stack->numbers;
	node = NULL;
	while (l != NULL)
	{
		if (l->index < chunk)
			return (l);
		if (dir == -1)
			l = l->prev;
		else
			l = l->next;
	}
	return (node);
}

void	ft_lstiter_s(t_list *lst, void (*f)(void *))
{
	while (lst != NULL)
	{
		f(lst->content_s);
		lst = lst->next;
	}
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	while (*lst != NULL)
	{
		del((*lst)->content_s);
		temp = (*lst)->next;
		free(*lst);
		*lst = temp;
	}
	lst = NULL;
}
