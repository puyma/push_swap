/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:56:31 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/03/16 22:24:00 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (0);
	a = ft_new_stack("a");
	b = ft_new_stack("b");
	if (ft_parse_arguments(a, argc, argv) == 0)
		ft_exit(0);
	while (a->numbers != NULL)
	{
		ft_printf("%d\n", a->numbers->content);
		a->numbers = a->numbers->next;
	}
	return (0);
}
