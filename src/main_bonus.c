/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:56:31 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/03/21 15:38:26 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*ft_read_instructions(void);

int	main(int argc, char **argv)
{
	t_data	*data;
	t_list	*instructions;

	data = NULL;
	instructions = NULL;
	if (argc < 2)
		return (0);
	data = ft_init_data();
	if (data == NULL)
		ft_exit(0);
	if (ft_parse_arguments(data, argc, argv) == 0)
		ft_exit(0);
	instructions = ft_read_instructions();
	if (instructions == NULL)
		ft_exit(0);
	if (ft_check_logic(data, instructions) == 0)
		ft_printf("KO\n");
	else
		ft_printf("OK\n");
	return (0);
}

static t_list	*ft_read_instructions(void)
{
	t_list	*list;
	char	*line;

	list = NULL;
	line = NULL;
	line = get_next_line(STDIN_FILENO);
	while (line != NULL && *line != '\0')
	{
		ft_lstadd_back(&list, ft_lstnew_str(line));
		line = get_next_line(STDIN_FILENO);
	}
	return (list);
}
