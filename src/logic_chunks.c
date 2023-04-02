/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic_chunks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 11:12:55 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/04/02 19:24:47 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_do_chunk_method(t_data *data)
{
	int		chunk;

	if (data->size <= 100)
		data->chunk_size = data->size / 5;
	else
		data->chunk_size = data->size / 8;
	chunk = data->chunk_size;
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
		ft_push_2a_by_chunk(data);
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
		ft_bring_top(data->a, from_top, from_bottom);
		push(data->a, data->b);
		if (data->b->numbers->index >= chunk - (data->chunk_size / 2))
			rotate(data->b);
	}
}

void	ft_push_2a_by_chunk(t_data *data)
{
	t_list	*biggest;

	biggest = ft_find(data->b, BIGGEST);
	if (data->b->numbers->index == biggest->index - 1)
		push(data->b, data->a);
	biggest = ft_find(data->b, BIGGEST);
	ft_bring_top(data->b, biggest, NULL);
	push(data->b, data->a);
	if (data->a->numbers->next
		&& data->a->numbers->next->index == data->a->numbers->index - 1)
		swap(data->a);
}

//if -1
//then push to a
//swap a
//if -2 
//then push to a
//rotate a
//...
