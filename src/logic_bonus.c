/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 17:29:39 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/03/23 15:28:07 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	(*ft_set_func(char *str))(t_data *data);

int	ft_check_logic(t_data *data, t_list *instructions)
{
	t_list	*l;
	int		(*do_instruction)(t_data *);

	l = instructions;
	do_instruction = NULL;
	data->fd = -1;
	while (l != NULL)
	{
		do_instruction = ft_set_func(l->content_s);
		if (do_instruction != NULL)
			do_instruction(data);
		do_instruction = NULL;
		l = l->next;
	}
	if (ft_issorted(data) == 0 || data->b->numbers != NULL)
		return (0);
	return (1);
}

static int	(*ft_set_func(char *str))(t_data *data)
{
	if (ft_strncmp(str, "pa", 2) == 0)
		return (&ft_pa);
	else if (ft_strncmp(str, "pb", 2) == 0)
		return (&ft_pb);
	else if (ft_strncmp(str, "sa", 2) == 0)
		return (&ft_sa);
	else if (ft_strncmp(str, "sb", 2) == 0)
		return (&ft_sb);
	else if (ft_strncmp(str, "ss", 2) == 0)
		return (&ft_ss);
	else if (ft_strncmp(str, "rra", 3) == 0)
		return (&ft_rra);
	else if (ft_strncmp(str, "rrb", 3) == 0)
		return (&ft_rrb);
	else if (ft_strncmp(str, "rrr", 3) == 0)
		return (&ft_rrr);
	else if (ft_strncmp(str, "ra", 2) == 0)
		return (&ft_ra);
	else if (ft_strncmp(str, "rb", 2) == 0)
		return (&ft_rb);
	else if (ft_strncmp(str, "rr", 2) == 0)
		return (&ft_rr);
	return (NULL);
}
