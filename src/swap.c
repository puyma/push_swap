/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 13:02:47 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/03/16 23:27:43 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_swap(t_stack *stack);

// (swap a)
// Swap the first 2 elements at the top of stack a.
// Do nothing if there is only one or no elements.
int	ft_sa(t_stack *a)
{
	ft_swap(a);
	return (0);
}

// (swap b)
// Swap the first 2 elements at the top of stack b.
// Do nothing if there is only one or no elements.
int	ft_sb(t_stack *b)
{
	ft_swap(b);
	return (0);
}

// sa and sb at the same time.
int	ft_ss(t_stack *a, t_stack *b)
{
	ft_swap(a);
	ft_swap(b);
	return (0);
}

static int	ft_swap(t_stack *stack)
{
	t_list	*l;
	t_list	*temp;
	
	ft_printf("s%s\n", stack->name);
	l = stack->numbers;
	temp = l->next;
	l->next = l;
	l = temp;
	return (0);
}
