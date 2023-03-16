/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 13:05:59 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/03/16 15:39:49 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_rotate(t_stack *stack);

// ra (rotate a)
// Shift up all elements of stack a by 1.
// The first element becomes the last one.
int	ft_ra(t_stack *a)
{
	ft_rotate(a);
	return (0);
}

// rb (rotate b)
// Shift up all elements of stack b by 1.
// The first element becomes the last one.
int	ft_rb(t_stack *b)
{
	ft_rotate(b);
	return (0);
}

// ra and rb at the same time.
int	ft_rr(t_stack *a, t_stack *b)
{
	ft_ra(a);
	ft_rb(b);
	return (0);
}

static int	ft_rotate(t_stack *stack)
{
	(void) stack;
	return (0);
}
