/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 13:04:10 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/03/16 23:22:52 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_push(t_stack *stack);

// (push a)
// Take the first element at the top of b and put it at the top of a.
// Do nothing if b is empty.
int	ft_pa(t_stack *s)
{
	ft_push(s);
	return (0);
}

// (push  b)
// Take the first element at the top of a and put it at the top of b.
// Do nothing if a is empty.
int	ft_pb(t_stack *s)
{
	ft_push(s);
	return (0);
}

static int	ft_push(t_stack *stack)
{
	(void) stack;
	return (0);
}
