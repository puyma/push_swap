/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic_chunks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 11:12:55 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/04/03 18:37:42 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_s_patch(int (*func)(t_stack *stack, int c), t_data *data);

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
		push(data->a, data->b, data->b->id);
		if (ft_find(data->b, BIGGEST)->index
			== ft_lstlast(data->b->numbers)->index)
		{
			ft_printf("rr\n");
			ft_s_patch(&rotate, data);
		}
		if (data->b->numbers->index >= chunk - (data->chunk_size / 2))
		{
			rotate(data->a, 0);
			from_top = ft_search_from(data->a, chunk, 1);
			if (ft_nmoves_to(data->a, from_top, 1)
				<= ft_nmoves_to(data->a, from_top, -1))
			{
				rev_rotate(data->a, 0);
				ft_printf("rr\n");
				ft_s_patch(&rotate, data);
			}
			else
			{
				rev_rotate(data->a, 0);
				rotate(data->b, data->b->id);
			}
		}
	}
}

void	ft_push_2a_by_chunk(t_data *data)
{
	t_list	*biggest;
	t_list	*biggest_prev;

	biggest = ft_find(data->b, BIGGEST);
	if (ft_lst_position(data->b->numbers, biggest) == 1)
	{
		swap(data->b, data->b->id);
		push(data->b, data->a, data->a->id);
	}
	// //biggest = ft_find(data->b, BIGGEST);
	// biggest->index - 1 anywhere
	// //if (data->b->numbers->index == biggest->index - 1)
		// //push(data->b, data->a, data->a->id);
	biggest = ft_find(data->b, BIGGEST);
	biggest_prev = ft_find_by_index(data->b, biggest->index - 1);
	if ((ft_lst_position(data->b->numbers, biggest) < ft_lstsize(data->b->numbers) / 2)
		&& ft_lst_position(data->b->numbers, biggest_prev) < ft_lst_position(data->b->numbers, biggest))
		biggest = biggest_prev;
	else if (ft_lst_position(data->b->numbers, biggest) > ft_lstsize(data->b->numbers) / 2
		&& ft_lst_position(data->b->numbers, biggest_prev) > ft_lst_position(data->b->numbers, biggest))
		biggest = biggest_prev;
	ft_bring_top(data->b, biggest, NULL);
	push(data->b, data->a, data->a->id);
	biggest = ft_find(data->b, BIGGEST);
	ft_bring_top(data->b, biggest, NULL);
	push(data->b, data->a, data->a->id);
	if (data->a->numbers->next
		&& data->a->numbers->next->index == data->a->numbers->index - 1)
	{
		biggest = ft_find(data->b, BIGGEST);
		if (ft_lst_position(data->b->numbers, biggest) == 1)
		{
			ft_printf("ss\n");
			ft_s_patch(&swap, data);
		}
		else
			swap(data->a, data->a->id);
	}
}

static void	ft_s_patch(int (*func)(t_stack *stack, int c), t_data *data)
{
	func(data->a, 0);
	func(data->b, 0);
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
