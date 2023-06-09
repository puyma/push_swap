/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 14:17:17 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/04/02 19:34:32 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_data	*ft_init_data(void);
static void		ft_set_index(t_stack *stack);

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc < 2)
		return (0);
	data = ft_init_data();
	if (data == NULL)
		ft_exit(0);
	if (ft_parse_arguments(data, argc, argv) == 0)
	{
		ft_free(data);
		ft_exit(0);
	}
	ft_set_index(data->a);
	if (ft_issorted(data->a) == 1)
		data->size = 0;
	if (data->size == 1)
		return (0);
	else if (data->size <= 5)
		ft_do_logic_mini(data);
	else
		ft_do_chunk_method(data);
	ft_free(data);
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

static void	ft_set_index(t_stack *stack)
{
	int		i;
	t_list	*list;
	t_list	*l;

	list = stack->numbers;
	while (list != NULL)
	{
		i = 0;
		l = stack->numbers;
		while (l != NULL)
		{
			if (list->content > l->content)
				i++;
			l = l->next;
		}
		list->index = i;
		list = list->next;
	}
}
