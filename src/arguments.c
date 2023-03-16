/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 15:52:36 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/03/16 20:14:51 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "push_swap.h"

static int	ft_check_number(char *argument);
static int	ft_str_isdigit(char *str);
static int	ft_islimit(char *s);

int	ft_parse_arguments(t_stack *stack, int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_check_number(argv[i]) == 0)
			return (0);
		if (ft_islimit(argv[i]) == 0)
			return (0);
		ft_lstadd_back(&stack->numbers, ft_lstnew(ft_atoi(argv[i])));
		i++;
	}
	return (1);
}

static int	ft_check_number(char *argument)
{
	char	*s;

	s = (char *) argument;
	if (ft_isdigit(*s) == 0)
	{
		if (*s != '+' && *s != '-')
			return (0);
		s++;
		if (ft_str_isdigit(s) == 0)
			return (0);
	}
	else
	{
		if (ft_str_isdigit(s) == 0)
			return (0);
	}
	return (1);
}

static int	ft_str_isdigit(char *str)
{
	char	*s;

	s = str;
	while (s && *s != '\0')
	{
		if (ft_isdigit(*s++) == 0)
			return (0);
	}
	return (1);
}

static int	ft_islimit(char *s)
{
	(void) s;
	// check if length is longer than INT_MAX or INT_MIN
	// else
	// check with strncmp if str is bigger than INT_MAX or INT_MIN
	return (1);
}
