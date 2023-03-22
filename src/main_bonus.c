/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:56:31 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/03/22 15:30:49 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		ft_delete_nl(void *ptr);
static t_list	*ft_read_instructions(void);
static int		ft_check_instructions(t_list *instructions);

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
	if (ft_check_instructions(instructions) == 0)
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
	ft_lstiter_s(list, &ft_delete_nl);
	return (list);
}

static void	ft_delete_nl(void *ptr)
{
	char	*str;

	str = (char *) ptr;
	while (*str != '\0')
	{
		if (*str == '\n')
			*str = '\0';
		str++;
	}
}

static int	ft_check_instructions(t_list *instructions)
{
	t_list	*l;
	char	*str;
	size_t	len;

	l = instructions;
	if (l == NULL)
		return (1);
	while (l != NULL)
	{
		str = l->content_s;
		len = ft_strlen(str);
		if (*str == 'p' && ft_strchr("ab", *(str + 1)) != 0 && len == 2)
			return (1);
		if (ft_strchr("sr", *str) != 0
			&& (ft_strchr("ab", *(str + 1)) != 0
				|| *(str + 1) == *str) && len == 2)
			return (1);
		else if (*str == 'r' && *(str + 1) == 'r'
			&& (ft_strchr("ab", *(str + 2)) != 0
				|| *(str + 2) == *str) && len == 3)
			return (1);
		l = l->next;
	}
	return (0);
}
