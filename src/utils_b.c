/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 19:11:28 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/04/03 20:55:09 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_find(t_stack *stack, int n)
{
	t_list	*node;
	t_list	*l;

	l = stack->numbers;
	node = l;
	while (l != NULL)
	{
		if ((n == BIGGEST && l->index > node->index)
			|| (n == SMALLEST && l->index < node->index))
			node = l;
		l = l->next;
	}
	return (node);
}

t_list	*ft_find_by_index(t_stack *stack, int index)
{
	t_list	*l;

	l = stack->numbers;
	while (l != NULL)
	{
		if (l->index == index)
			return (l);
		l = l->next;
	}
	return (NULL);
}

int	ft_nmoves_to(t_stack *stack, t_list *node, int dir)
{
	int		i;
	t_list	*l;

	i = 0;
	if (dir == BACKWARD)
		l = ft_lstlast(stack->numbers);
	else
		l = stack->numbers;
	while (l != node)
	{
		if (dir == BACKWARD)
			l = l->prev;
		else
			l = l->next;
		i++;
	}
	return (i);
}

int	ft_issorted(t_stack *stack)
{
	t_list	*l;

	l = stack->numbers;
	while (l != NULL && l->next != NULL)
	{
		l = l->next;
		if (l->prev->content > l->content)
			return (0);
	}
	return (1);
}
