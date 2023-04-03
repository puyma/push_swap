/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 17:29:39 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/04/03 15:34:15 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_do_instruction(t_data *data, char *str);
static void	ft_s_patch(int (*func)(t_stack *stack, int c), t_data *data);

int	ft_check_logic(t_data *data, t_list *instructions)
{
	t_list	*l;

	l = instructions;
	while (l != NULL)
	{
		ft_do_instruction(data, l->content_s);
		l = l->next;
	}
	if (ft_issorted(data->a) == 0)
		ft_printf("not sorted\n");
	else if (data->b->numbers != NULL)
		return (0);
	return (1);
}

static void	ft_do_instruction(t_data *data, char *str)
{
	if (ft_strncmp(str, "pa", 2) == 0)
		push(data->b, data->a, 0);
	else if (ft_strncmp(str, "pb", 2) == 0)
		push(data->a, data->b, 0);
	else if (ft_strncmp(str, "sa", 2) == 0)
		swap(data->a, 0);
	else if (ft_strncmp(str, "sb", 2) == 0)
		swap(data->b, 0);
	else if (ft_strncmp(str, "ss", 2) == 0)
		ft_s_patch(&swap, data);
	else if (ft_strncmp(str, "rra", 3) == 0)
		rev_rotate(data->a, 0);
	else if (ft_strncmp(str, "rrb", 3) == 0)
		rev_rotate(data->b, 0);
	else if (ft_strncmp(str, "rrr", 3) == 0)
		ft_s_patch(&rev_rotate, data);
	else if (ft_strncmp(str, "ra", 2) == 0)
		rotate(data->a, 0);
	else if (ft_strncmp(str, "rb", 2) == 0)
		rotate(data->b, 0);
	else if (ft_strncmp(str, "rr", 2) == 0)
		ft_s_patch(&rotate, data);
}

static void	ft_s_patch(int (*func)(t_stack *stack, int c), t_data *data)
{
	func(data->a, 0);
	func(data->b, 0);
}
