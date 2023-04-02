/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic_chunks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 11:12:55 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/04/02 14:09:29 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_do_chunk_method(t_data *data)
{
	int		chunk;
	t_list	*smallest;

	if (data->size <= 100)
		data->chunk_size = data->size / 5;
	else
		data->chunk_size = data->size / 8;
	smallest = ft_find(data->a, SMALLEST);
	chunk = smallest->content + data->chunk_size;
	while (data->a->numbers != NULL)
	{
		ft_pb_by_chunk(data, chunk);
		chunk += data->chunk_size;
		if (ft_lstsize(data->a->numbers) == 3)
		{
			ft_case_three(data->a);
			break ;
		}
	}
	while (data->b->numbers != NULL)
		ft_push_2a_by_chunk(data, chunk);
	return (0);
}

void	ft_pb_by_chunk(t_data *data, int chunk)
{
	int		i;
	t_list	*l;
	t_list	*from_top;
	t_list	*from_bottom;

	l = data->a->numbers;
	i = 0;
	while (data->a->numbers != NULL && i++ <= data->chunk_size)
	{
		from_top = ft_search_from(data->a, chunk, 1);
		from_bottom = ft_search_from(data->a, chunk, -1);
		if (from_bottom == NULL)
			break ;
		if (ft_nmoves_to(data->a, from_top, 1)
			<= ft_nmoves_to(data->a, from_bottom, -1))
		{
			while (data->a->numbers != from_top && from_top != NULL)
				rotate(data->a);
		}
		else
		{
			while (data->a->numbers != from_bottom && from_bottom != NULL)
				rev_rotate(data->a);
		}
		push(data->a, data->b);
		if (data->b->numbers->content >= chunk - (data->chunk_size / 2))
			rotate(data->b);
	}
}

void	ft_push_2a_by_chunk(t_data *data, int chunk)
{
	t_list	*biggest;

	(void) chunk;
	biggest = ft_find(data->b, BIGGEST);
	if (ft_nmoves_to(data->b, biggest, 1)
		<= ft_nmoves_to(data->b, biggest, -1))
	{
		while (data->b->numbers != biggest && biggest != NULL)
		{
			rotate(data->b);
		}
	}
	else
	{
		while (data->b->numbers != biggest && biggest != NULL)
		{
			rev_rotate(data->b);
		}
	}
	push(data->b, data->a);
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
