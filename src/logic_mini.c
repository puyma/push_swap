/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic_mini.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 15:07:24 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/03/30 12:32:59 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_case_three(t_data *data);

int	ft_do_logic_mini(t_data *data)
{
	if (ft_issorted(data->a) != 0)
		return (0);
	if (data->size == 2)
	{
		if (data->a->numbers->content > data->a->numbers->next->content)
			ft_ra(data);
	}
	else if (data->size <= 5)
	{
		while (ft_lstsize(data->a->numbers) != 3)
			ft_pb_smallest(data);
		ft_case_three(data);
		while (data->b->numbers != NULL)
			ft_pa(data);
	}
	return (0);
}

static void	ft_case_three(t_data *data)
{
	int	xyz[3];

	xyz[0] = 0;
	xyz[1] = 0;
	xyz[2] = 0;
	if (data->a->numbers->content > data->a->numbers->next->content)
		xyz[0] = 1;
	if (data->a->numbers->next->content > data->a->numbers->next->next->content)
		xyz[1] = 1;
	if (data->a->numbers->next->next->content > data->a->numbers->content)
		xyz[2] = 1;
	if ((xyz[0] + xyz[1] + xyz[2]) >= 2)
		ft_sa(data);
	if (xyz[1] == xyz[2])
		ft_ra(data);
	if (xyz[1] == 1 && xyz[2] == 0)
		ft_rra(data);
}
