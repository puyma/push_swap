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
		data->chunk_size = data->size / 5;
	else
		data->chunk_size = data->size / 8;
	chunk = data->chunk_size;
	while (data->a->numbers != NULL && ft_lstsize(data->a->numbers) > 3)
	{
		i = 0;
		while (i++ <= data->chunk_size)
		{
			ft_bring_top_by_chunk(data->a, chunk);
			push(data->a, data->b, data->b->id);
			// rr / rrr stuff && patch;
			//ft_push_2b_by_chunk(data, chunk);
		}
		chunk += data->chunk_size;
	}
	if (ft_lstsize(data->a->numbers) == 3)
		ft_case_three(data->a);
	while (data->b->numbers != NULL)
	{
		ft_bring_top_biggest(data->b);
		push(data->b, data->a, data->a->id);
		//swap stuff && ss patch;
		//ft_push_back_2a(data);
	}
	return (0);
}

void	ft_bring_top_biggest(t_stack *stack)
{
	int		*func(t_stack, int c);
	t_list	*biggest;
	t_list	*l;

	func = NULL;
	biggest = ft_find(stack->numbers, BIGGEST);
	if (ft_nmoves(stack, biggest, FORWARD)
		<= ft_nmoves(stack, biggest, BACKWARD))
		func = &rotate;
	else
		func = &rev_rotate;
	l = stack->numbers;
	while (l != NULL && l != biggest)
	{
		if (l->index == biggest->index - 1 || l->index == biggest->index - 2)
			break;
		func(stack, stack->id);
		l = l->next;
	}
}

void	ft_bring_top_by_chunk(t_stack *stack, int chunk)
{
	t_list	*from_top;
	t_list	*from_bottom;
	int		*func(t_stack, int c);

	from_top = ft_search_from(stack->numbers, chunk, 1);
	from_bottom = ft_search_from(stack->numbers, chunk, -1);
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

/*
void	ft_push_2b_by_chunk(t_data *data, int chunk)
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
*/

/*
void	ft_bring_top(t_stack *stack, t_list *node, t_list *bottom)
{
	if (bottom == NULL)
		bottom = node;
	if (ft_nmoves_to(stack, node, FORWARD)
		<= ft_nmoves_to(stack, bottom, BACKWARD))
	{
		while (stack->numbers != node && node != NULL)
			rotate(stack, stack->id);
	}
	else
	{
		while (stack->numbers != bottom && bottom != NULL)
			rev_rotate(stack, stack->id);
	}
}
*/

/*
static void	ft_bring_top_a(t_data *data, t_list *node, t_list *bottom)
{
	t_stack	*stack;
	int		(*func)(t_stack *stack, int c);

	stack = data->b;
	func = NULL;
	if (bottom == NULL)
		bottom = node;
	if (ft_nmoves_to(stack, node, FORWARD)
		<= ft_nmoves_to(stack, bottom, BACKWARD))
		func = &rotate;
	else
	{
		func = &rev_rotate;
		node = bottom;
	}
	while (stack->numbers != node && node != NULL)
	{
		func(stack, stack->id);
		if (stack->numbers->index == node->index - 1)
			push(data->b, data->a, data->a->id); //ft_printf("once\n");
	}
}
*/

/*
void	ft_push_back_2a(t_data *data)
{
	t_list	*biggest;

	biggest = ft_find(data->b, BIGGEST);
	if (ft_lst_position(data->b->numbers, biggest) == 1)
	{
		swap(data->b, data->b->id);
		push(data->b, data->a, data->a->id);
	}
	biggest = ft_find(data->b, BIGGEST);
	ft_bring_top_a(data, biggest, NULL);
	//ft_bring_top(data->b, biggest, NULL);
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
	(void) ft_bring_top_a;
}
*/

static void	ft_s_patch(int (*func)(t_stack *stack, int c), t_data *data)
{
	func(data->a, 0);
	func(data->b, 0);
}
