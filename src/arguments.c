/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 15:52:36 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/03/16 22:49:54 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "push_swap.h"

static int	ft_check_number(char *argument);
static int	ft_str_isdigit(char *str);
static int	ft_islimit(char *s);
static int	ft_check_duplicates(t_list *list);

int	ft_parse_arguments(t_stack *stack, int argc, char **argv)
{
	int			i;

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
	if (ft_check_duplicates(stack->numbers) == 0)
		return (0);
	return (1);
}

static int	ft_check_duplicates(t_list *list)
{
	t_list	*l;
	t_list	*l_temp;

	// check prev(s)
	// check next(s)
	return (0);
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
	if (ft_str_isdigit(s) == 0)
		return (0);
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
	const size_t	max = ft_count_digits(INT_MAX, 10);
	const size_t	min = ft_count_digits(INT_MIN, 10) + 1;
	size_t			len;

	len = ft_strlen(s);
	if (*s == '-' && len > min)
		return (0);
	if (*s == '+' && len > (max + 1))
		return (0);
	if (*s != '+' && *s != '-' && len > max)
		return (0);
	if (*s == '-' && ft_strncmp(s, ft_itoa(INT_MIN), min) > 0)
		return (0);
	if (*s == '+' && ft_strncmp(s + 1, ft_itoa(INT_MAX), max) > 0)
		return (0);
	if (*s != '+' && *s != '-' && len == max && ft_strncmp(s, ft_itoa(INT_MAX), max) > 0)
		return (0);
	return (1);
}
