/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:56:31 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/03/16 17:18:45 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		i;

	if (argc < 2)
		return (0);
	a = ft_new_stack("a");
	b = ft_new_stack("b");
	a->numbers = ft_parse_arguments(argc, argv);
	i = 0;
	while (i < argc - 1)
	{
		ft_printf("%d\n", a->numbers[i]);
		i++;
	}
	return (0);
}
