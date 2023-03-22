/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:03:15 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/03/22 16:56:44 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(t_data *data)
{
	char	**temp;

	temp = NULL;
	if (data)
	{
		ft_lstclear(&data->a->numbers, &free);
		if (data->a)
			free(data->a);
		ft_lstclear(&data->b->numbers, &free);
		if (data->b)
			free(data->b);
		temp = data->split;
		while (temp && *(temp) != NULL)
		{
			free(*temp);
			temp++;
		}
		free(data->split);
		free(data);
	}
}
