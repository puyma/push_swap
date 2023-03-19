/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 17:29:39 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/03/19 21:02:38 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// find smallest and move to b
static void	ft_case_three(t_data *data);
static void	ft_case_five(t_data *data);
static void	ft_pb_smallest(t_data *data);
static int	ft_lst_position(t_list *l, t_list *node);

int	ft_do_logic(t_data *data)
{
	if (data->size == 1)
		return (0);
	else if (data->size == 3)
		ft_case_three(data);
	else if (data->size == 5)
		ft_case_five(data);
	else
		ft_printf("size: %d\n", data->size);
	return (0);
}

static void	ft_pb_smallest(t_data *data)
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

static void	ft_case_five(t_data *data)
{
	ft_pb_smallest(data);
	ft_pb_smallest(data);
	ft_case_three(data);
	ft_pa(data);
	ft_pa(data);
}

static int	ft_lst_position(t_list *list, t_list *node)
{
	t_list	*l;
	int		position;

	l = list;
	position = 1;
	while (l != node)
	{
		position++;
		l = l->next;
	}
	return (position);
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
