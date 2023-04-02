/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 10:50:22 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/04/02 10:57:03 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(int content)
{
	t_list	*list;

	list = (t_list *) malloc(sizeof(*list));
	if (list == NULL)
		return (NULL);
	list->content = content;
	list->content_s = NULL;
	list->next = NULL;
	list->prev = NULL;
	return (list);
}

t_list	*ft_lstnew_str(char	*content_s)
{
	t_list	*list;

	list = (t_list *) ft_calloc(1, sizeof(t_list));
	if (list == NULL)
		return (NULL);
	list->content = 0;
	list->content_s = content_s;
	list->next = NULL;
	list->prev = NULL;
	return (list);
}

t_list	*ft_lstlast(t_list *lst)
{
	while (lst != NULL && lst->next != NULL)
		lst = lst->next;
	return (lst);
}

size_t	ft_lst_position(t_list *list, t_list *node)
{
	t_list	*l;
	size_t	position;

	l = list;
	position = 0;
	while (l != NULL && l != node)
	{
		position++;
		l = l->next;
	}
	return (position);
}

size_t	ft_lstsize(t_list *lst)
{
	size_t	i;

	i = 0;
	while (lst != NULL)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

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
		if (l->content < chunk)
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
