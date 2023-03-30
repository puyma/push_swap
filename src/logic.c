/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 17:29:39 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/03/30 12:18:28 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_do_logic(t_data *data)
{
	int	chunk;
	int	chunk_size;

	chunk = 0;
	chunk_size = 20;
	if (data->size == 1)
		return (0);
	else if (data->size <= 5)
		ft_do_logic_mini(data);
	else
		ft_do_chunk_method(data);
	return (0);
}

// next to FIX---
void	ft_push_2a_by_chunk(t_data *data, int chunk)
{
	t_list	*biggest;

	biggest = ft_find(data->b, BIGGEST);
	if (ft_nmoves_to_a(data, biggest, 1)
		<= ft_nmoves_to_a(data, biggest, -1))
		ft_pa_node(data, biggest, &ft_rb);
	else
		ft_pa_node(data, biggest, &ft_rrb);
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
	while (data->a->numbers != NULL && i <= chunk)
	{
		from_top = ft_search_from(data->a, chunk, 1);
		from_bottom = ft_search_from(data->a, chunk, -1);
		if (from_bottom == NULL)
			break ;
		if (ft_nmoves_to_b(data, from_top, 1)
			<= ft_nmoves_to_b(data, from_bottom, -1))
			ft_pb_node(data, from_top, &ft_ra);
		else
			ft_pb_node(data, from_bottom, &ft_rra);
		i++;
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

int	ft_nmoves_to_b(t_data *data, t_list *node, int dir)
{
	int		i;
	t_list	*l;

	i = 0;
	//if (node == NULL)
	//	return (0);
	if (dir == -1)
		l = ft_lstlast(data->a->numbers);
	else
		l = data->a->numbers;
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

int	ft_nmoves_to_a(t_data *data, t_list *node, int dir)
{
	int		i;
	t_list	*l;

	i = 0;
	//if (node == NULL)
	//	return (0);
	if (dir == -1)
		l = ft_lstlast(data->b->numbers);
	else
		l = data->b->numbers;
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

int	ft_pb_node(t_data *data, t_list *node, int (*ft)(t_data *))
{
	while (data->a->numbers != node && node != NULL)
		ft(data);
	ft_pb(data);
	return (0);
}

int	ft_pa_node(t_data *data, t_list *node, int (*ft)(t_data *))
{
	while (data->b->numbers != node && node != NULL)
		ft(data);
	ft_pa(data);
	return (0);
}
