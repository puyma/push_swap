/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_issorted.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:05:19 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/03/21 15:05:51 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_issorted(t_data *data)
{
	t_list	*l;

	l = data->a->numbers;
	while (l != NULL && l->next != NULL)
	{
		l = l->next;
		if (l->prev->content > l->content)
			return (0);
	}
	return (1);
}
