/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 17:29:39 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/03/28 17:43:12 by mpuig-ma         ###   ########.fr       */
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

// next to FIX---
void	ft_push_2a_by_chunk(t_data *data, int chunk)
{
	int	n_moves;
	int	i;

	n_moves = ft_pb_biggest(data, chunk);
	//ft_printf("n_moves: %d\n", n_moves);
	i = 0;
	while (i < n_moves)
	{
		//write(1, "d\t", 2);
		ft_rb(data);
		i++;
	}
	if (n_moves >= 0)
		ft_pa(data);
	i = 0;
	while (i < n_moves)
	{
		//write(1, "e\t", 2);
		ft_rrb(data);
		i++;
	}
	if (ft_lstsize(data->b->numbers) == 0)
		ft_pa(data);
}

int	ft_pb_biggest(t_data *data, int chunk)
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
		from_top = ft_search_from(data, chunk, 1);
		from_bottom = ft_search_from(data, chunk, -1);
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

int	ft_nmoves_to_b(t_data *data, t_list *node, int dir)
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

int	ft_pb_node(t_data *data, t_list *node, int (*ft)(t_data *))
{
	while (data->a->numbers != node)
	{
		//write(1, "c\t", 2);
		ft(data);
	}
	ft_pb(data);
	return (0);
}
