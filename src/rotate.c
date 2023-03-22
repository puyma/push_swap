/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 13:05:59 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/03/22 15:41:27 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_rotate(t_stack *stack);

// ra (rotate a)
// Shift up all elements of stack a by 1.
// The first element becomes the last one.
int	ft_ra(t_data *data)
{
	if (data->a->numbers == NULL || ft_lstsize(data->a->numbers) == 1)
		return (0);
	write(data->fd, "ra\n", 3);
	data->n_moves += ft_rotate(data->a);
	if (LOG > 0)
		ft_print_stacks(data, DIRECTION);
	return (1);
}

// rb (rotate b)
// Shift up all elements of stack b by 1.
// The first element becomes the last one.
int	ft_rb(t_data *data)
{
	if (data->b->numbers == NULL || ft_lstsize(data->b->numbers) == 1)
		return (0);
	write(data->fd, "rb\n", 3);
	data->n_moves += ft_rotate(data->b);
	if (LOG > 0)
		ft_print_stacks(data, DIRECTION);
	return (1);
}

// ra and rb at the same time.
int	ft_rr(t_data *data)
{
	write(data->fd, "rr\n", 3);
	ft_ra(data);
	ft_rb(data);
	return (1);
}

static int	ft_rotate(t_stack *stack)
{
	if (stack->numbers == NULL)
		return (0);
	stack->numbers = stack->numbers->next;
	if (stack->numbers == NULL)
		return (1);
	ft_lstadd_back(&stack->numbers, stack->numbers->prev);
	stack->numbers->prev = NULL;
	return (1);
}
