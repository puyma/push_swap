/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:56:31 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/03/21 14:39:12 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc < 2)
		return (0);
	data = ft_init_data();
	if (data == NULL)
		ft_exit(0);
	if (ft_parse_arguments(data, argc, argv) == 0)
		ft_exit(0);
	ft_do_logic(data);
	return (0);
}
