/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 17:29:39 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/03/30 12:57:59 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_2a_by_chunk(t_data *data, int chunk)
{
	t_list	*biggest;

	biggest = ft_find(data->b, BIGGEST);
	if (ft_nmoves_to(data->b, biggest, 1)
		<= ft_nmoves_to(data->b, biggest, -1))
	{
		while (data->b->numbers != biggest && biggest != NULL)
			ft_rb(data);
		ft_pa(data);
	}
	else
	{
		while (data->b->numbers != biggest && biggest != NULL)
			ft_rrb(data);
		ft_pa(data);
	}
	(void) chunk;
}

t_list	*ft_find(t_stack *stack, int n)
{
	t_list 	*node;
	t_list	*l;

	l = stack->numbers;
	node = l;
	while (l != NULL)
	{
		if ((n == BIGGEST && l->content > node->content)
			|| (n == SMALLEST && l->content < node->content))
			node = l;
		l = l->next;
	}
	return (node);
}

void	ft_pb_smallest(t_data *data)
{
	t_list	*la;
	t_list	*smallest;
	int		position;

	la = data->a->numbers;
	smallest = la;
	while (la != NULL)
	{
		if (smallest->content > la->content)
			smallest = la;
		la = la->next;
	}
	position = ft_lst_position(data->a->numbers, smallest);
	while (data->a->numbers->content != smallest->content)
	{
		if ((data->size - position) >= data->size / 2)
			ft_ra(data);
		else
			ft_rra(data);
	}
	ft_pb(data);
}

int	ft_pb_biggest(t_data *data, int chunk)
{
	int		n_moves;
	t_list	*lb;
	t_list	*biggest;

	n_moves = 0;
	lb = data->b->numbers;
	biggest = lb;
	while (lb != NULL && biggest != NULL)
	{
		if (biggest->content < lb->content && lb->content > chunk)
			biggest = lb;
		lb = lb->next;
	}
	if (biggest != NULL && biggest->content < chunk)
		return (-1);
	if (biggest)
		n_moves = ft_lst_position(data->b->numbers, biggest);
	return (n_moves);
}

void	ft_pb_by_chunk(t_data *data, int chunk)
{
	int		i;
	t_list	*l;
	t_list	*from_top;
	t_list	*from_bottom;

	l = data->a->numbers;
	i = 0;
	while (data->a->numbers != NULL && i++ <= chunk)
	{
		from_top = ft_search_from(data->a, chunk, 1);
		from_bottom = ft_search_from(data->a, chunk, -1);
		if (from_bottom == NULL)
			break ;
		if (ft_nmoves_to(data->a, from_top, 1)
			<= ft_nmoves_to(data->a, from_bottom, -1))
		{
			while (data->a->numbers != from_top && from_top != NULL)
				ft_ra(data);
		}
		else
		{
			while (data->a->numbers != from_bottom && from_bottom != NULL)
				ft_rra(data);
		}
		ft_pb(data);
	}
}

void	ft_do_chunk_method(t_data *data)
{
	int	chunk_size;
	int	chunk;

	if (data->size <= 100)
		chunk_size = 20;
	else
		chunk_size = 44;
	chunk = chunk_size;
	while (data->a->numbers != NULL)
	{
		ft_pb_by_chunk(data, chunk);
		chunk += chunk_size;
	}
	while (data->b->numbers != NULL)
	{
		ft_push_2a_by_chunk(data, chunk);
		if (ft_pb_biggest(data, chunk) == -1)
			chunk -= chunk_size;
	}
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
