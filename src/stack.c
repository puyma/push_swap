/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 15:16:18 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/03/16 16:05:17 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_new_stack(char *name)
{
	t_stack	*stack;

	stack = ft_calloc(1, sizeof(t_stack));
	if (stack == NULL)
		return (NULL);
	stack->name = name;
	stack->numbers = NULL;
	return (stack);
}
