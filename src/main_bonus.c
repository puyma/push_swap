/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:56:31 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/03/21 16:04:46 by mpuig-ma         ###   ########.fr       */
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
	if (instructions == NULL || ft_check_instructions(instructions) == 0)
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

static int	ft_check_instructions(t_list *instructions)
{
	t_list	*l;

	l = instructions;
	while (l != NULL)
	{
		if (ft_strlen(l->content_s) > 3
			|| ft_strchr("spr", *(l->content_s)) == 0)
			return (0);
		if (*(l->content_s) == 's'
			&& ft_strchr("abs", *(l->content_s + 1)) == 0)
			return (0);
		else if (*(l->content_s) == 'p'
			&& ft_strchr("ab", *(l->content + 1)) == 0)
			return (0);
		else if (*(l->content_s) == 'r'
			&& ft_strchr("abr") == 0)
			return (0);
		else if (*(l->content_s + 1) == 'r'
			&& ft_strchr("abr", *(l->content_s + 2)) == 0)
			return (0);
		l = l->next;
	}
	return (1);
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
