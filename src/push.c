/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 13:04:10 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/03/18 15:06:52 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_push(t_stack *from, t_stack *to);

// (push a)
// Take the first element at the top of b and put it at the top of a.
// Do nothing if b is empty.
int	ft_pa(t_stack *from, t_stack *to)
{
	write(1, "pa\n", 3);
	ft_push(from, to);
	return (0);
}

// (push  b)
// Take the first element at the top of a and put it at the top of b.
// Do nothing if a is empty.
int	ft_pb(t_stack *from, t_stack *to)
{
	write(1, "pb\n", 3);
	ft_push(from, to);
	return (0);
}

static int	ft_push(t_stack *from, t_stack *to)
{
	from->numbers = from->numbers->next;
	ft_lstadd_front(&to->numbers, from->numbers->prev);
	from->numbers->prev = NULL;
	return (0);
}
