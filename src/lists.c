/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 18:53:32 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/03/16 22:47:34 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	last = ft_lstlast(*lst);
	if (last == NULL)
		*lst = new;
	else
	{
		last->next = new;
		new->prev = last;
	}
}

t_list	*ft_lstlast(t_list *lst)
{
	while (lst != NULL && lst->next != NULL)
		lst = lst->next;
	return (lst);
}

t_list	*ft_lstnew(int content)
{
	t_list	*list;

	list = (t_list *) malloc(sizeof(*list));
	if (list == NULL)
		return (NULL);
	list->content = content;
	list->next = NULL;
	list->prev = NULL;
	return (list);
}
