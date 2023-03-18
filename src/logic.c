/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 17:29:39 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/03/18 19:25:34 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_case_three(t_stack *a);
static void	ft_case_five(t_stack *a, t_stack *b);

int	ft_do_logic(t_stack *a, t_stack *b)
{
	int	size;

	size = ft_lstsize(a->numbers);
	if (size == 1)
		return (0);
	else if (size == 3)
		ft_case_three(a);
	else if (size == 5)
		ft_case_five(a, b);
	else
		ft_printf("size: %d\n", size);
	return (0);
}

static void	ft_case_five(t_stack *a, t_stack *b)
{
	ft_pb(a, b);
	ft_pb(a, b);
	ft_case_three(a);
	ft_pa(a, b);
	if (a->numbers->content > b->numbers->content)
		ft_ra(a);
	ft_pa(a, b);
}

static void	ft_case_three(t_stack *a)
{
	int	x;
	int	y;
	int	z;

	x = 0;
	y = 0;
	z = 0;
	if (a->numbers->content > a->numbers->next->content)
		x = 1;
	if (a->numbers->next->content > a->numbers->next->next->content)
		y = 1;
	if (a->numbers->next->next->content > a->numbers->content)
		z = 1;
	if ((x + y + z) >= 2)
		ft_sa(a);
	if (y == z)
		ft_ra(a);
	if (y == 1 && z == 0)
		ft_rra(a);
}
