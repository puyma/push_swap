/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:56:31 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/03/21 14:51:55 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_check_logic(void);
static int	ft_read_instructions(void);

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
	ft_read_instructions();
	if (ft_check_logic() == 0)
		ft_printf("KO\n");
	else
		ft_printf("OK\n");
	return (0);
}

static int	ft_read_instructions(void)
{
	return (0);
}

// read from stdin until ^D or EOF
// if coming from ./push_swap, EOF is automatic
// else, is users ^D
//
// then, parse instructions. only a few are valid
// else, "Error\n"
//

static int	ft_check_logic(void)
{
	return (1);
}
