/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:56:31 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/03/21 13:00:25 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	**ft_read_from(int fd);

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc < 2)
	{
		argv = ft_read_from(STDIN_FILENO);
		exit(0);
	}

	// first, parse arguments
	// if no arguments or one of the is bad/duplicate,..
	// "Error\n"
	//
	// CASE IF ARGC == 2
	// 	check that the list of integers is not contained in a single string
	// 	if that is the case, ft_split
	//
	// then, read from stdin until ^D
	// if coming from ./push_swap, EOF is automatic
	// else, is users ^D
	//
	// then, parse instructions. only a few are valid
	// else, "Error\n"
	//
	// then ft_do_check(data)

	data = ft_init_data();
	if (data == NULL)
		return (0);
	if (ft_parse_arguments(data, argc, argv) == 0)
		ft_exit(0);
	ft_check_logic(data);
	return (data->n_moves);
}
