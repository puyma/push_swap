/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 13:04:10 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/03/20 17:02:56 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_push(t_stack *from, t_stack *to);

// (push a)
// Take the first element at the top of b and put it at the top of a.
// Do nothing if b is empty.
int	ft_pa(t_data *data)
{
	if (data->b->numbers == NULL)
		return (0);
	write(1, "pa\n", 3);
	data->n_moves += ft_push(data->b, data->a);
	if (LOG > 0)
		ft_print_stacks(data, DIRECTION);
	return (1);
}

// (push  b)
// Take the first element at the top of a and put it at the top of b.
// Do nothing if a is empty.
int	ft_pb(t_data *data)
{
	if (data->a->numbers == NULL)
		return (0);
	write(1, "pb\n", 3);
	data->n_moves += ft_push(data->a, data->b);
	if (LOG > 0)
		ft_print_stacks(data, DIRECTION);
	return (1);
}

static int	ft_push(t_stack *from, t_stack *to)
{
	t_list	*first;

	first = from->numbers;
	from->numbers = from->numbers->next;
	ft_lstadd_front(&to->numbers, first);
	if (from->numbers != NULL)
		from->numbers->prev = NULL;
	return (1);
}
