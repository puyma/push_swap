/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 10:09:35 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/03/22 10:12:12 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_printf("Usage: ./generator number\n");
		return (0);
	}
	ft_printf("This should generate %d random numbers\n", ft_atoi(argv[1]));
	return (0);
}
