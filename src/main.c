/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:56:31 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/03/19 18:22:00 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_print_stacks(t_data *data);
static void	ft_print_stacks_rev(t_data *data);

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc < 2)
		return (0);
	data = ft_calloc(1, sizeof(t_data));
	if (data == NULL)
		return (0);
	if (ft_parse_arguments(data, argc, argv) == 0)
		ft_exit(0);
	ft_do_logic(data);
	ft_print_stacks(data);
	ft_print_stacks_rev(data);
	return (0);
}

static void	ft_print_stacks(t_data *data)
{
	t_list	*la;
	t_list	*lb;

	la = data->a->numbers;
	lb = data->b->numbers;
	write(1, "---------\n", 10);
	while (la != NULL || lb != NULL)
	{
		if (la)
			ft_printf("%d", la->content);
		write(1, "\t", 1);
		if (lb)
			ft_printf("%d", lb->content);
		write(1, "\n", 1);
		if (la != NULL)
			la = la->next;
		if (lb != NULL)
			lb = lb->next;
	}
	write(1, "-\t-\n", 4);
	write(1, "A\tB\n", 4);
}

static void	ft_print_stacks_rev(t_data *data)
{
	t_list	*la;
	t_list	*lb;

	la = ft_lstlast(data->a->numbers);
	lb = ft_lstlast(data->b->numbers);
	write(1, "---------(rev)\n", 16);
	while (la != NULL || lb != NULL)
	{
		if (la)
			ft_printf("%d", la->content);
		write(1, "\t", 1);
		if (lb)
			ft_printf("%d", lb->content);
		write(1, "\n", 1);
		if (la != NULL)
			la = la->prev;
		if (lb != NULL)
			lb = lb->prev;
	}
	write(1, "-\t-\n", 4);
	write(1, "A\tB\n", 4);
}
