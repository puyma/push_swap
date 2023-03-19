/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 18:53:27 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/03/19 19:06:37 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*ft_iter_direction(t_list *l, int dir);

void	ft_print_stacks(t_data *data, int dir)
{
	t_list	*la;
	t_list	*lb;

	la = data->a->numbers;
	lb = data->b->numbers;
	write(1, "----------", 10);
	if (dir < 0)
		write(1, "(rev)", 5);
	write(1, "\n", 1);
	while (la != NULL || lb != NULL)
	{
		if (la)
			ft_printf("%d", la->content);
		write(1, "\t", 1);
		if (lb)
			ft_printf("%d", lb->content);
		write(1, "\n", 1);
		la = ft_iter_direction(la, dir);
		lb = ft_iter_direction(lb, dir);
	}
	write(1, "-\t-\n", 4);
	write(1, "A\tB\n", 4);
}

static t_list	*ft_iter_direction(t_list *l, int dir)
{
	if (l == NULL)
		return (l);
	if (dir > 0)
		return (l->next);
	else if (dir < 0)
		return (l->prev);
	return (NULL);
}
