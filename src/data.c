/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 18:17:10 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/03/19 18:19:09 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_init_data(t_data *data)
{
	data = ft_calloc(1, sizeof(t_data));
	if (data == NULL)
		return (0);
	data->a = ft_calloc(1, sizeof(t_stack));
	data->b = ft_calloc(1, sizeof(t_stack));
	if (data->a == NULL || data->b == NULL)
		return (0);
	return (1);
}
