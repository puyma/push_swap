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

static void	ft_s_patch(int (*func)(t_stack *stack, int c), t_data *data);

int	ft_do_chunk_method(t_data *data)
{
	int		chunk;
	int		i;

	if (data->size <= 100)
		data->chunk_size = 20;
	else
		data->chunk_size = 60;
	chunk = data->chunk_size;
	while (data->a->numbers != NULL) // && ft_lstsize(data->a->numbers) > 3)
	{
		i = 0;
		while (i++ <= data->chunk_size)
		{
			ft_bring_top_by_chunk(data->a, chunk);
			push(data->a, data->b, data->b->id);

			// start rr patch
			if (ft_find(data->b, BIGGEST)->index
				== ft_lstlast(data->b->numbers)->index)
			{
				ft_printf("rr\n");
				ft_s_patch(&rotate, data);
			}
			if (data->b->numbers->index >= chunk - (data->chunk_size / 2))
			{
				rotate(data->a, 0);
				t_list *node = ft_search_from(data->a, chunk, 1);
				if (ft_nmoves_to(data->a, node, 1)
					<= ft_nmoves_to(data->a, node, -1))
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
			// end rr patch

		}
		chunk += data->chunk_size;
	}
	//if (ft_lstsize(data->a->numbers) == 3)
	//	ft_case_three(data->a);
	while (data->b->numbers != NULL)
	{
		ft_bring_top_biggest(data->b);
		push(data->b, data->a, data->a->id);

		

		// start ss patch
		if (data->a->numbers->next
			&& data->a->numbers->next->index == data->a->numbers->index - 1)
		{
			t_list *biggest = ft_find(data->b, BIGGEST);
			if (ft_lst_position(data->b->numbers, biggest) == 1)
			{
				ft_printf("ss\n");
				ft_s_patch(&swap, data);
			}
			else
				swap(data->a, data->a->id);
		}
		// end ss patch
		(void) ft_s_patch;
	}
	return (0);
}

void	ft_bring_top_biggest(t_stack *stack)
{
	int		(*func)(t_stack *stack, int c);
	t_list	*biggest;
	t_list	*l;

	func = NULL;
	biggest = ft_find(stack, BIGGEST);
	if (ft_nmoves_to(stack, biggest, FORWARD)
		<= ft_nmoves_to(stack, biggest, BACKWARD))
		func = &rotate;
	else
		func = &rev_rotate;
	l = stack->numbers;
	while (l != NULL && l != biggest)
	{
		//if (l->index == biggest->index - 1 || l->index == biggest->index - 2)
		//	break;
		func(stack, stack->id);
		l = l->next;
	}
}

void	ft_bring_top_by_chunk(t_stack *stack, int chunk)
{
	int		(*func)(t_stack *stacak, int c);
	t_list	*node;
	t_list	*from_top;
	t_list	*from_bottom;

	func = NULL;
	node = NULL;
	from_top = ft_search_from(stack, chunk, 1);
	from_bottom = ft_search_from(stack, chunk, -1);
	if (ft_nmoves_to(stack, from_top, FORWARD)
		<= ft_nmoves_to(stack, from_bottom, BACKWARD))
	{
		node = from_top;
		func = &rotate;
	}
	else
	{
		node = from_bottom;
		func = &rev_rotate;
	}
	while (stack->numbers != node && node != NULL && func != NULL)
		func(stack, stack->id);
}

static void	ft_s_patch(int (*func)(t_stack *stack, int c), t_data *data)
{
	func(data->a, 0);
	func(data->b, 0);
}
