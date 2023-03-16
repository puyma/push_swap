/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 15:52:36 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/03/16 17:25:39 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_isnumber(char *str);

int	*ft_parse_arguments(int argc, char **argv)
{
	int			*numbers;
	long int	temp;
	int			i;

	numbers = ft_calloc(argc + 1, sizeof(int));
	if (numbers == NULL)
		exit (88);
	i = 1;
	while (i < argc)
	{
		if (ft_isnumber(argv[i]) == 0)
			return (NULL);
		temp = ft_atoi(argv[i]);
		if (ft_strlen(argv[i]) > (size_t) ft_count_digits(INT_MAX, 10))
			ft_printf("exit\n");
		numbers[i - 1] = (int) temp;
		i++;
	}
	return (numbers);
}

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
