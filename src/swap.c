/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 13:02:47 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/03/19 18:23:13 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_swap(t_stack *stack);

// (swap a)
// Swap the first 2 elements at the top of stack a.
// Do nothing if there is only one or no elements.
int	ft_sa(t_data *data)
{
	write(1, "sa\n", 3);
	ft_swap(data->a);
	return (0);
}

// (swap b)
// Swap the first 2 elements at the top of stack b.
// Do nothing if there is only one or no elements.
int	ft_sb(t_data *data)
{
	write(1, "sb\n", 3);
	ft_swap(data->b);
	return (0);
}

// sa and sb at the same time.
int	ft_ss(t_data *data)
{
	write(1, "ss\n", 3);
	ft_swap(data->a);
	ft_swap(data->b);
	return (0);
}

static int	ft_swap(t_stack *stack)
{
	t_list	*first;
	t_list	*second;

	if (stack->numbers == NULL)
		return (0);
	first = stack->numbers;
	second = stack->numbers->next;
	if (second == NULL)
		return (0);
	if (second->next != NULL)
		second->next->prev = first;
	first->next = second->next;
	second->next = first;
	first->prev = second;
	second->prev = NULL;
	stack->numbers = second;
	return (0);
}
