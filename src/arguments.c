/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 15:52:36 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/03/16 19:21:30 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//static int	ft_isnumber(char *str);

int	ft_parse_arguments(t_stack *stack, int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		ft_lstadd_back(&stack->numbers, ft_lstnew(ft_atoi(argv[i])));
		i++;
	}
	return (0);
}

/*
static int	ft_isnumber(char *str)
{
	char	*s;

	s = str;
	if (str == NULL || *str == '\0')
		return (0);
	if (*str == '+' || *str == '-')
		str++;
	while (*str != '\0')
	{
		if (ft_isdigit(*str) == 0)
			return (0);
		str++;
	}
	return (1);
}
*/
