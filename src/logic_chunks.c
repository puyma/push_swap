/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic_chunks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 11:12:55 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/04/03 20:55:02 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_sort_by_chunks(t_data *data, int chunk);
static void	ft_do_rotate(t_data *data, int chunk);
static void	ft_sort_by_index(t_data *data);

int	ft_do_chunk_method(t_data *data)
{
	int		chunk;

	if (data->size <= 100)
		data->chunk_size = 20;
	else
		data->chunk_size = 60;
	chunk = data->chunk_size;
	ft_sort_by_chunks(data, chunk);
	ft_sort_by_index(data);
	return (0);
}

static void	ft_sort_by_chunks(t_data *data, int chunk)
{
	int	i;

	i = 0;
	while (ft_lstsize(data->a->numbers))
	{
		if (data->a->numbers && data->a->numbers->index > chunk)
			rotate(data->a, data->a->id);
		else
		{
			push(data->a, data->b, data->b->id);
			if (data->b->numbers
				&& data->b->numbers->index < chunk - (data->chunk_size / 2))
				ft_do_rotate(data, chunk);
			i++;
		}
		if (i == data->chunk_size)
		{
			chunk += data->chunk_size;
			i = 0;
		}
	}
}

static void	ft_do_rotate(t_data *data, int chunk)
{
	if (data->a->numbers && data->a->numbers->index > chunk)
	{
		ft_printf("rr\n");
		rotate(data->b, 0);
		rotate(data->a, 0);
	}
	else
		rotate(data->b, data->b->id);
}

static void	ft_sort_by_index(t_data *data)
{
	while (data->b->numbers != NULL)
	{
		ft_bring_top_biggest(data->b, data->a);
		push(data->b, data->a, data->a->id);
		if (data->a->numbers && data->a->numbers->next
			&& data->a->numbers->next->index == data->a->numbers->index - 1)
			swap(data->a, data->a->id);
	}
}

void	ft_bring_top_biggest(t_stack *stack, t_stack *stack_a)
{
	int		(*func)(t_stack *stack, int c);
	t_list	*biggest;

	func = NULL;
	biggest = ft_find(stack, BIGGEST);
	if (ft_nmoves_to(stack, biggest, FORWARD)
		<= ft_nmoves_to(stack, biggest, BACKWARD))
		func = &rotate;
	else
		func = &rev_rotate;
	while (stack->numbers != NULL && stack->numbers != biggest)
	{
		func(stack, stack->id);
		if (stack->numbers->index == biggest->index - 1)
			push(stack, stack_a, stack_a->id);
	}
}
