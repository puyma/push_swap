/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 18:02:31 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/04/02 18:16:13 by mpuig-ma         ###   ########.fr       */
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
