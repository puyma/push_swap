/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 15:52:36 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/03/19 20:31:59 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "push_swap.h"

static int	ft_check_number(char *argument);
static int	ft_str_isdigit(char *str);
static int	ft_islimit(char *s);
static int	ft_check_duplicates(t_list *list);

int	ft_parse_arguments(t_data *data, int argc, char **argv)
{
	int		i;
	t_list	*list;

	i = 1;
	while (i < argc)
	{
		if (ft_check_number(argv[i]) == 0 || ft_islimit(argv[i]) == 0)
			return (0);
		list = ft_lstnew(ft_atoi(argv[i]));
		list->index = i++;
		ft_lstadd_back(&data->a->numbers, list);
	}
	list = data->a->numbers;
	while (list != NULL)
	{
		if (ft_check_duplicates(list) == 0)
			return (0);
		list = list->next;
	}
	data->size = ft_lstsize(data->a->numbers);
	return (1);
}

static int	ft_check_duplicates(t_list *list)
{
	int		content;
	t_list	*l;

	content = list->content;
	l = list->next;
	while (l != NULL)
	{
		if (content == l->content)
			return (0);
		l = l->next;
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
	if (*s == '-' && len == min \
		&& ft_strncmp(s, ft_itoa(INT_MIN), min) > 0)
		return (0);
	if (*s == '+' && len == max + 1 \
		&& ft_strncmp(s + 1, ft_itoa(INT_MAX), max) > 0)
		return (0);
	if (*s != '+' && *s != '-' && len == max \
		&& ft_strncmp(s, ft_itoa(INT_MAX), max) > 0)
		return (0);
	return (1);
}
