/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 13:05:59 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/03/18 18:33:27 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_rotate(t_stack *stack);

// ra (rotate a)
// Shift up all elements of stack a by 1.
// The first element becomes the last one.
int	ft_ra(t_stack *a)
{
	write(1, "ra\n", 3);
	ft_rotate(a);
	return (0);
}

// rb (rotate b)
// Shift up all elements of stack b by 1.
// The first element becomes the last one.
int	ft_rb(t_stack *b)
{
	write(1, "rb\n", 3);
	ft_rotate(b);
	return (0);
}

// ra and rb at the same time.
int	ft_rr(t_stack *a, t_stack *b)
{
	write(1, "rr\n", 3);
	ft_ra(a);
	ft_rb(b);
	return (0);
}

static int	ft_rotate(t_stack *stack)
{
	if (stack->numbers == NULL)
		return (0);
	stack->numbers = stack->numbers->next;
	if (stack->numbers == NULL)
		return (0);
	ft_lstadd_back(&stack->numbers, stack->numbers->prev);
	stack->numbers->prev = NULL;
	return (0);
}
