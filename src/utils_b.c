/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 19:11:28 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/04/02 19:14:52 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_bring_top(t_stack *stack, t_list *node, t_list *bottom)
{
	if (bottom == NULL)
		bottom = node;
	if (ft_nmoves_to(stack, node, 1)
		<= ft_nmoves_to(stack, bottom, -1))
	{
		while (stack->numbers != node && node != NULL)
			rotate(stack);
	}
	else
	{
		while (stack->numbers != bottom && bottom != NULL)
			rev_rotate(stack);
	}
}

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

int	ft_nmoves_to(t_stack *stack, t_list *node, int dir)
{
	int		i;
	t_list	*l;

	i = 0;
	if (dir == -1)
		l = ft_lstlast(stack->numbers);
	else
		l = stack->numbers;
	while (l != node)
	{
		if (dir == -1)
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
