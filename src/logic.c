/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 17:29:39 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/03/18 18:04:57 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_do_logic(t_stack *a, t_stack *b)
{
	ft_sa(a);
	ft_pb(a, b);
	ft_pb(a, b);
	ft_pb(a, b);
	ft_ra(a);
	ft_rb(b);
	ft_rra(a);
	ft_rrb(b);
	ft_sa(a);
	ft_pa(a, b);
	ft_pa(a, b);
	ft_pa(a, b);
	return (0);
	(void) a;
	(void) b;
}
