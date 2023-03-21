/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:13:39 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/03/21 15:19:49 by mpuig-ma         ###   ########.fr       */
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
