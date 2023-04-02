/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic_mini.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 11:12:27 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/04/02 17:04:00 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_do_logic_mini(t_data *data)
{
	if (ft_issorted(data->a) != 0)
		return (0);
	if (data->size == 2)
	{
		if (data->a->numbers->content > data->a->numbers->next->content)
			rotate(data->a);
	}
	else if (data->size <= 5)
	{
		while (ft_lstsize(data->a->numbers) != 3)
			ft_pb_smallest(data);
		ft_case_three(data->a);
		while (data->b->numbers != NULL)
			push(data->b, data->a);
	}
	return (0);
}

int	ft_case_three(t_stack *stack)
{
	int	xyz[3];

	xyz[0] = 0;
	xyz[1] = 0;
	xyz[2] = 0;
	if (stack->numbers->content > stack->numbers->next->content)
		xyz[0] = 1;
	if (stack->numbers->next->content > stack->numbers->next->next->content)
		xyz[1] = 1;
	if (stack->numbers->next->next->content > stack->numbers->content)
		xyz[2] = 1;
	if ((xyz[0] + xyz[1] + xyz[2]) >= 2)
		swap(stack);
	if (xyz[1] == xyz[2])
		rotate(stack);
	if (xyz[1] == 1 && xyz[2] == 0)
		rev_rotate(stack);
	return (0);
}

void	ft_pb_smallest(t_data *data)
{
	t_list	*smallest;
	int		position;

	smallest = ft_find(data, data->a, SMALLEST);
	position = ft_lst_position(data->a->numbers, smallest);
	while (data->a->numbers != smallest)
	{
		if ((data->size - position) >= data->size / 2)
			rotate(data->a);
		else
			rev_rotate(data->a);
	}
	push(data->a, data->b);
}
