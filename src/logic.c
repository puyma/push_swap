/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 17:29:39 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/03/19 18:21:12 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_case_three(t_data *data);
static void	ft_case_five(t_data *data);

int	ft_do_logic(t_data *data)
{
	int	size;

	size = ft_lstsize(data->a->numbers);
	if (size == 1)
		return (0);
	else if (size == 3)
		ft_case_three(data);
	else if (size == 5)
		ft_case_five(data);
	else
		ft_printf("size: %d\n", size);
	return (0);
}

static void	ft_case_five(t_data *data)
{
	ft_pb(data);
	ft_pb(data);
	ft_case_three(data);
	ft_pa(data);
	if (data->a->numbers->content > data->b->numbers->content)
		ft_ra(data);
	ft_pa(data);
}

static void	ft_case_three(t_data *data)
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
