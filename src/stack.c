/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 15:16:18 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/03/18 15:31:40 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_new_stack(void)
{
	t_stack	*stack;

	stack = ft_calloc(1, sizeof(t_stack));
	if (stack == NULL)
		return (NULL);
	stack->numbers = NULL;
	return (stack);
}
