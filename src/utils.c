/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 11:05:09 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/04/02 11:07:23 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*ft_iter_direction(t_list *l);
static t_list	*ft_start_node(t_list *l);

void	ft_exit(int n)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	exit (n);
}

void	ft_free(t_data *data)
{
	char	**temp;

	temp = NULL;
	if (data)
	{
		ft_lstclear(&data->a->numbers, &free);
		if (data->a)
			free(data->a);
		ft_lstclear(&data->b->numbers, &free);
		if (data->b)
			free(data->b);
		temp = data->split;
		while (temp && *(temp) != NULL)
		{
			free(*temp);
			temp++;
		}
		free(data->split);
		free(data);
	}
}

void	ft_print_stacks(t_data *data)
{
	t_list	*la;
	t_list	*lb;

	la = ft_start_node(data->a->numbers);
	lb = ft_start_node(data->b->numbers);
	write(1, "----------", 10);
	write(1, "\n", 1);
	while (la != NULL || lb != NULL)
	{
		if (la)
			ft_printf("%d", la->content);
		write(1, "\t", 1);
		if (lb)
			ft_printf("%d", lb->content);
		write(1, "\n", 1);
		la = ft_iter_direction(la);
		lb = ft_iter_direction(lb);
	}
	write(1, "-\t-\n", 4);
	write(1, "A\tB\n", 4);
}

static t_list	*ft_iter_direction(t_list *l)
{
	if (l == NULL)
		return (l);
	if (DIRECTION > 0)
		return (l->next);
	else if (DIRECTION < 0)
		return (l->prev);
	return (NULL);
}

static t_list	*ft_start_node(t_list *l)
{
	if (l == NULL || DIRECTION > 0)
		return (l);
	else if (DIRECTION < 0)
		return (ft_lstlast(l));
	return (NULL);
}
