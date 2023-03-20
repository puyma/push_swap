/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 17:29:39 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/03/20 14:04:48 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#define CHUNK_SIZE	20

static void		ft_case_two(t_data *data);
static void		ft_case_three(t_data *data);
static void		ft_case_five(t_data *data);
static void		ft_pb_smallest(t_data *data);
static int		ft_lst_position(t_list *l, t_list *node);
static int		ft_issorted(t_data *data);
static void		ft_do_chunk_method(t_data *data, int chunk);
static int		ft_nmoves_to_b(t_data *data, t_list *node);
static int		ft_pb_node(t_data *data, t_list *node, int (*ft)(t_data *));
static t_list	*ft_search_from(t_data *data, int chunk, int dir);

int	ft_do_logic(t_data *data)
{
	int	chunk;

	chunk = 0;
	if (data->size == 1)
		return (0);
	else if (data->size == 2)
		ft_case_two(data);
	else if (data->size == 3)
		ft_case_three(data);
	else if (data->size == 4 || data->size == 5)
		ft_case_five(data);
	else if (data->size <= 100)
	{
		chunk = CHUNK_SIZE;
		while (data->a->numbers != NULL)
		{
			ft_do_chunk_method(data, chunk);
			chunk += CHUNK_SIZE;
		}
	}
	return (0);
}

static void	ft_do_chunk_method(t_data *data, int chunk)
{
	int		i;
	t_list	*l;
	t_list	*from_top;
	t_list	*from_bottom;

	l = data->a->numbers;
	i = 0;
	while (data->a->numbers != NULL && i < chunk)
	{
		from_top = ft_search_from(data, chunk, forward);
		from_bottom = ft_search_from(data, chunk, backwards);
		if (from_bottom == NULL)
			break ;
		if (ft_nmoves_to_b(data, from_top) < ft_nmoves_to_b(data, from_bottom))
			ft_pb_node(data, from_top, &ft_ra);
		else
			ft_pb_node(data, from_bottom, &ft_rra);
		i++;
	}
}

static t_list	*ft_search_from(t_data *data, int chunk, int dir)
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

static int	ft_nmoves_to_b(t_data *data, t_list *node)
{
	int		i;
	t_list	*l;

	i = 0;
	l = data->a->numbers;
	while (l != node)
	{
		l = l->next;
		i++;
	}
	return (i);
}

static int	ft_pb_node(t_data *data, t_list *node, int (*ft)(t_data *))
{
	while (data->a->numbers != node)
		ft(data);
	ft_pb(data);
	return (0);
}

static int	ft_issorted(t_data *data)
{
	t_list	*l;

	l = data->a->numbers;
	while (l != NULL && l->next != NULL)
	{
		l = l->next;
		if (l->prev->content > l->content)
			return (0);
	}
	return (1);
}

static void	ft_pb_smallest(t_data *data)
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

static int	ft_lst_position(t_list *list, t_list *node)
{
	t_list	*l;
	int		position;

	l = list;
	position = 1;
	while (l != node)
	{
		position++;
		l = l->next;
	}
	return (position);
}

static void	ft_case_five(t_data *data)
{
	if (ft_issorted(data) == 0)
	{
		while (ft_lstsize(data->a->numbers) != 3)
			ft_pb_smallest(data);
		ft_case_three(data);
		while (data->b->numbers != NULL)
			ft_pa(data);
	}
}

static void	ft_case_three(t_data *data)
{
	int	x;
	int	y;
	int	z;

	x = 0;
	y = 0;
	z = 0;
	if (data->a->numbers->content > data->a->numbers->next->content)
		x = 1;
	if (data->a->numbers->next->content > data->a->numbers->next->next->content)
		y = 1;
	if (data->a->numbers->next->next->content > data->a->numbers->content)
		z = 1;
	if ((x + y + z) >= 2)
		ft_sa(data);
	if (y == z)
		ft_ra(data);
	if (y == 1 && z == 0)
		ft_rra(data);
}

static void	ft_case_two(t_data *data)
{
	t_list	*l;

	l = data->a->numbers;
	if (l->content > l->next->content)
		ft_ra(data);
}
