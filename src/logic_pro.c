/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic_pro.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 15:26:09 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/03/29 17:50:48 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// need to add support for negative numbers
// might add data->lowest and data->highest

void	ft_do_chunk_method(t_data *data)
{
	int	chunk_size;
	int	chunk;

	if (data->size <= 100)
		chunk_size = 20;
	else
		chunk_size = 44;
	chunk = chunk_size;
	while (data->a->numbers != NULL)
	{
		ft_pb_by_chunk(data, chunk);
		chunk += chunk_size;
	}
	while (data->b->numbers != NULL)
	{
		ft_push_2a_by_chunk(data, chunk);
		if (ft_pb_biggest(data, chunk) == -1)
			chunk -= chunk_size;
	}
}
