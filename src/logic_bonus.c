/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 17:29:39 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/04/02 20:27:22 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_do_instruction(t_data *data, char *str);

int	ft_check_logic(t_data *data, t_list *instructions)
{
	t_list	*l;

	l = instructions;
	while (l != NULL)
	{
		ft_printf("s: %s\n", l->content_s);
		l = l->next;
	}
	if (ft_issorted(data->a) == 0 || data->b->numbers != NULL)
		return (0);
	return (1);
	(void) ft_do_instruction;
}

static void	ft_do_instruction(t_data *data, char *str)
{
	if (ft_strncmp(str, "pa", 2) == 0)
		push(data->b, data->a);
	else if (ft_strncmp(str, "pb", 2) == 0)
		push(data->a, data->b);
	if (ft_strncmp(str, "sa", 2) == 0 || ft_strncmp(str, "ss", 2) == 0)
		swap(data->a);
	if (ft_strncmp(str, "sb", 2) == 0 || ft_strncmp(str, "ss", 2) == 0)
		swap(data->b);
	if (ft_strncmp(str, "rra", 3) == 0 || ft_strncmp(str, "rrr", 3) == 0)
		rev_rotate(data->a);
	if (ft_strncmp(str, "rrb", 3) == 0 || ft_strncmp(str, "rrr", 3) == 0)
		rev_rotate(data->b);
	if (ft_strncmp(str, "ra", 2) == 0 || ft_strncmp(str, "rr", 2) == 0)
		rotate(data->a);
	if (ft_strncmp(str, "rb", 2) == 0 || ft_strncmp(str, "rr", 2) == 0)
		rotate(data->b);
}
