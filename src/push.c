/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 13:04:10 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/03/19 18:08:03 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_push(t_stack *from, t_stack *to);

// (push a)
// Take the first element at the top of b and put it at the top of a.
// Do nothing if b is empty.
int	ft_pa(t_data *data)
{
	write(1, "pa\n", 3);
	ft_push(data->b, data->a);
	return (0);
}

// (push  b)
// Take the first element at the top of a and put it at the top of b.
// Do nothing if a is empty.
int	ft_pb(t_data *data)
{
	write(1, "pb\n", 3);
	ft_push(data->a, data->b);
	return (0);
}

static int	ft_push(t_stack *from, t_stack *to)
{
	t_list	*first;

	first = from->numbers;
	if (from->numbers == NULL)
		return (0);
	from->numbers = from->numbers->next;
	ft_lstadd_front(&to->numbers, first);
	if (from->numbers != NULL)
		from->numbers->prev = NULL;
	return (0);
}
