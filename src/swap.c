/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 13:02:47 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/03/18 15:10:34 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_swap(t_stack *stack);

// (swap a)
// Swap the first 2 elements at the top of stack a.
// Do nothing if there is only one or no elements.
int	ft_sa(t_stack *a)
{
	write(1, "sa\n", 3);
	ft_swap(a);
	return (0);
}

// (swap b)
// Swap the first 2 elements at the top of stack b.
// Do nothing if there is only one or no elements.
int	ft_sb(t_stack *b)
{
	write(1, "sb\n", 3);
	ft_swap(b);
	return (0);
}

// sa and sb at the same time.
int	ft_ss(t_stack *a, t_stack *b)
{
	write(1, "ss\n", 3);
	ft_swap(a);
	ft_swap(b);
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
	if (second->next != NULL)
		second->next->prev = first;
	first->next = second->next;
	second->next = first;
	first->prev = second;
	second->prev = NULL;
	stack->numbers = second;
	return (0);
}
