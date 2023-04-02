/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:56:31 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/04/02 20:21:47 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_data	*ft_init_data(void);
static void		ft_delete_nl(void *ptr);
static int		ft_read_instructions(t_list *instructions);
static int		ft_check_instruction(char *instruction);

int	main(int argc, char **argv)
{
	t_data	*data;
	t_list	*instructions;

	if (argc < 2)
		return (0);
	data = ft_init_data();
	instructions = NULL;
	if (data == NULL || ft_parse_arguments(data, argc, argv) == 0)
	{
		ft_free(data);
		ft_exit(0);
	}
	if (ft_read_instructions(instructions) == 0)
	{
		ft_free(data);
		ft_exit(0);
	}
	if (ft_check_logic(data, instructions) == 0)
		ft_printf("KO\n");
	else
		ft_printf("OK\n");
	ft_free(data);
	ft_lstclear(&instructions, &free);
	return (0);
}

static t_data	*ft_init_data(void)
{
	t_data	*data;

	data = ft_calloc(1, sizeof(t_data));
	if (data == NULL)
		return (NULL);
	data->a = ft_calloc(1, sizeof(t_stack));
	data->b = ft_calloc(1, sizeof(t_stack));
	if (data->a == NULL || data->b == NULL)
		return (NULL);
	data->a->id = 'a';
	data->b->id = 'b';
	data->fd = STDOUT_FILENO;
	data->size = 0;
	data->n_moves = 0;
	data->chunk_size = 0;
	return (data);
}

static int	ft_read_instructions(t_list *instructions)
{
	t_list	*list;
	char	*line;

	list = NULL;
	line = get_next_line(STDIN_FILENO);
	while (line != NULL && *line != '\0')
	{
		if (ft_check_instruction(line) == 0)
		{
			ft_lstclear(&list, &free);
			return (0);
		}
		ft_lstadd_back(&list, ft_lstnew_str(line));
		line = get_next_line(STDIN_FILENO);
	}
	if (list == NULL)
		return (0);
	ft_lstiter_s(list, &ft_delete_nl);
	instructions = list;
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

static int	ft_check_instruction(char *str)
{
	size_t		len;

	ft_delete_nl(str);
	if (str == NULL || *str == '\0')
		return (1);
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
	return (0);
}
