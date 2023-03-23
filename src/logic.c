/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 17:29:39 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/03/23 12:10:08 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		ft_case_two(t_data *data);
static void		ft_case_three(t_data *data);
static void		ft_case_five(t_data *data);
static void		ft_pb_smallest(t_data *data);
static int		ft_pb_biggest(t_data *data, int chunk);
static void		ft_do_chunk_method(t_data *data);
static void		ft_pb_by_chunk(t_data *data, int chunk);
static void		ft_push_2a_by_chunk(t_data *data, int chunk);
static int		ft_nmoves_to_b(t_data *data, t_list *node, int dir);
static int		ft_pb_node(t_data *data, t_list *node, int (*ft)(t_data *));

int	ft_do_logic(t_data *data)
{
	int	chunk;
	int	chunk_size;

	exit(0);
	chunk = 0;
	chunk_size = 20;
	if (data->size == 1)
		return (0);
	else if (data->size == 2)
		ft_case_two(data);
	else if (data->size == 3)
		ft_case_three(data);
	else if (data->size == 4 || data->size == 5)
		ft_case_five(data);
	else
		ft_do_chunk_method(data);
	return (0);
}

// need to add support for negative numbers
// might add data->lowest and data->highest
static void	ft_do_chunk_method(t_data *data)
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

static void	ft_push_2a_by_chunk(t_data *data, int chunk)
{
	int	n_moves;
	int	i;

	n_moves = ft_pb_biggest(data, chunk);
	i = 0;
	while (i < n_moves)
	{
		ft_rb(data);
		i++;
	}
	if (n_moves >= 0)
		ft_pa(data);
	i = 0;
	while (i < n_moves)
	{
		ft_rrb(data);
		i++;
	}
	if (ft_lstsize(data->b->numbers) == 0)
		ft_pa(data);
}

static int	ft_pb_biggest(t_data *data, int chunk)
{
	int		n_moves;
	t_list	*lb;
	t_list	*biggest;

	n_moves = 0;
	lb = data->b->numbers;
	biggest = lb;
	while (lb != NULL)
	{
		if (biggest->content < lb->content && lb->content > chunk)
			biggest = lb;
		lb = lb->next;
	}
	if (biggest && biggest->content < chunk)
		return (-1);
	n_moves = ft_lst_position(data->b->numbers, biggest);
	return (n_moves);
}

static void	ft_pb_by_chunk(t_data *data, int chunk)
{
	int		i;
	t_list	*l;
	t_list	*from_top;
	t_list	*from_bottom;

	l = data->a->numbers;
	i = 0;
	while (data->a->numbers != NULL && i <= chunk)
	{
		from_top = ft_search_from(data, chunk, 1);
		from_bottom = ft_search_from(data, chunk, -1);
		if (from_bottom == NULL)
			break ;
		if (ft_nmoves_to_b(data, from_top, 1)
			< ft_nmoves_to_b(data, from_bottom, -1))
			ft_pb_node(data, from_top, &ft_ra);
		else
			ft_pb_node(data, from_bottom, &ft_rra);
		i++;
	}
}

static int	ft_nmoves_to_b(t_data *data, t_list *node, int dir)
{
	int		i;
	t_list	*l;

	i = 0;
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

static int	ft_pb_node(t_data *data, t_list *node, int (*ft)(t_data *))
{
	while (data->a->numbers != node)
		ft(data);
	ft_pb(data);
	return (0);
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
