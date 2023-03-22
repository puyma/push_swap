/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 17:29:39 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/03/22 13:50:50 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_logic(t_data *data, t_list *instructions)
{
	t_list	*l;
	int		*do_instruction(t_data *data);

	l = instructions;
	while (l != NULL)
	{
		do_instruction = ft_set_func(l->content_s);
		if (do_instruction != NULL)
			do_instruction(data);
		l = l->next;
	}
	if (ft_issorted(data) == 0)
		return (0);
	return (1);
}
