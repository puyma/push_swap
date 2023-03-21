/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_search.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:24:04 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/03/21 15:55:11 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_search_from(t_data *data, int chunk, int dir)
{
	t_list	*l;
	t_list	*node;

	if (dir == backwards)
		l = ft_lstlast(data->a->numbers);
	else
		l = data->a->numbers;
	node = NULL;
	while (l != NULL)
	{
		if (l->content < chunk)
			return (l);
		if (dir == backwards)
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
