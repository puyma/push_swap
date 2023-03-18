/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 15:21:51 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/03/18 17:18:04 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int static	ft_reverse_rotate(t_stack *stack);

// (reverse rotate a)
// Shift down all elements of stack a by 1.
// The last element becomes the first one.
int	ft_rra(t_stack *a)
{
	write(1, "rra\n", 4);
	ft_reverse_rotate(a);
	return (0);
}

// (reverse rotate b)
// Shift down all elements of stack b by 1.
// The last element becomes the first one.
int	ft_rrb(t_stack *b)
{
	write(1, "rrb\n", 4);
	ft_reverse_rotate(b);
	return (0);
}

// rra and rrb at the same time.
int	ft_rrr(t_stack *a, t_stack *b)
{
	write(1, "rrr\n", 4);
	ft_rra(a);
	ft_rrb(b);
	return (0);
}

static int	ft_reverse_rotate(t_stack *stack)
{
	t_list	*last;

	if (stack->numbers == NULL)
		return (0);
	last = ft_lstlast(stack->numbers);
	last->prev->next = NULL;
	ft_lstadd_front(&stack->numbers, last);
	stack->numbers = last;
	return (0);
}
