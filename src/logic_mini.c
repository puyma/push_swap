/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic_mini.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 15:07:24 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/03/28 15:42:35 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_case_five(t_data *data)
{
	if (ft_issorted(data) == 0)
	{
		while (ft_lstsize(data->a->numbers) != 3)
			ft_pb_smallest(data);
		ft_case_three(data);
		while (data->b->numbers != NULL)
			ft_pa(data);
	}
}

void	ft_case_three(t_data *data)
{
	int	x;
	int	y;
	int	z;

	x = 0;
	y = 0;
	z = 0;
	if (data->a->numbers->content > data->a->numbers->next->content)
		x = 1;
	if (data->a->numbers->next->content > data->a->numbers->next->next->content)
		y = 1;
	if (data->a->numbers->next->next->content > data->a->numbers->content)
		z = 1;
	if ((x + y + z) >= 2)
		ft_sa(data);
	if (y == z)
		ft_ra(data);
	if (y == 1 && z == 0)
		ft_rra(data);
}

void	ft_case_two(t_data *data)
{
	t_list	*l;

	l = data->a->numbers;
	if (l->content > l->next->content)
		ft_ra(data);
}

void	ft_pb_smallest(t_data *data)
{
	t_list	*la;
	t_list	*smallest;
	int		position;

	la = data->a->numbers;
	smallest = la;
	while (la != NULL)
	{
		if (smallest->content > la->content)
			smallest = la;
		la = la->next;
	}
	position = ft_lst_position(data->a->numbers, smallest);
	while (data->a->numbers->content != smallest->content)
	{
		if ((data->size - position) >= data->size / 2)
			ft_ra(data);
		else
			ft_rra(data);
	}
	ft_pb(data);
}
