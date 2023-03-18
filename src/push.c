/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 13:04:10 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/03/18 18:07:23 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_push(t_stack *from, t_stack *to);

// (push a)
// Take the first element at the top of b and put it at the top of a.
// Do nothing if b is empty.
int	ft_pa(t_stack *a, t_stack *b)
{
	write(1, "pa\n", 3);
	ft_push(b, a);
	return (0);
}

// (push  b)
// Take the first element at the top of a and put it at the top of b.
// Do nothing if a is empty.
int	ft_pb(t_stack *a, t_stack *b)
{
	write(1, "pb\n", 3);
	ft_push(a, b);
	return (0);
}

static int	ft_push(t_stack *from, t_stack *to)
{
	from->numbers = from->numbers->next;
	if (from->numbers == NULL)
		return (0);
	ft_lstadd_front(&to->numbers, from->numbers->prev);
	from->numbers->prev = NULL;
	return (0);
}
