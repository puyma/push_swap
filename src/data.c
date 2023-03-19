/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 18:17:10 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/03/19 18:29:54 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_data	*ft_init_data(void)
{
	t_data	*data;

	data = ft_calloc(1, sizeof(t_data));
	if (data == NULL)
		return (NULL);
	data->a = ft_calloc(1, sizeof(t_stack));
	data->b = ft_calloc(1, sizeof(t_stack));
	if (data->a == NULL || data->b == NULL)
		return (NULL);
	return (data);
}
