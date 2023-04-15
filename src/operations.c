/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 14:50:20 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/04/03 13:42:38 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push(t_stack *from, t_stack *to, int c)
{
	t_list	*first;

	if (from->numbers == NULL)
		return (0);
	if (c != 0)
		ft_printf("p%c\n", c);
	first = from->numbers;
	from->numbers = from->numbers->next;
	ft_lstadd_front(&to->numbers, first);
	if (from->numbers != NULL)
		from->numbers->prev = NULL;
	return (1);
}

// will need to implement ss, rs, rrs properly !!

int	swap(t_stack *stack, int c)
{
	t_list	*first;
	t_list	*second;

	if (stack->numbers == NULL || ft_lstsize(stack->numbers) == 1)
		return (0);
	if (c != 0)
		ft_printf("s%c\n", c);
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
	return (1);
}

int	rotate(t_stack *stack, int c)
{
	if (stack->numbers == NULL || ft_lstsize(stack->numbers) == 1)
		return (0);
	if (stack->numbers == NULL)
		return (0);
	if (c != 0)
		ft_printf("r%c\n", c);
	stack->numbers = stack->numbers->next;
	if (stack->numbers == NULL)
		return (1);
	ft_lstadd_back(&stack->numbers, stack->numbers->prev);
	stack->numbers->prev = NULL;
	return (1);
}

int	rev_rotate(t_stack *stack, int c)
{
	t_list	*last;

	if (stack->numbers == NULL || ft_lstsize(stack->numbers) == 1)
		return (0);
	if (c != 0)
		ft_printf("rr%c\n", c);
	last = ft_lstlast(stack->numbers);
	if (last->prev != NULL)
		last->prev->next = NULL;
	ft_lstadd_front(&stack->numbers, last);
	stack->numbers = last;
	return (1);
}
