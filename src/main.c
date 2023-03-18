/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:56:31 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/03/18 17:18:12 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_print_stack(t_stack *stack, int c);
static void	ft_print_stack_rev(t_stack *stack, int c);

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (0);
	a = ft_new_stack();
	b = ft_new_stack();
	if (a == NULL || b == NULL)
		return (0);
	if (ft_parse_arguments(a, argc, argv) == 0)
		ft_exit(0);
	ft_print_stack(a, 'A');
	ft_rra(a);
	ft_print_stack(a, 'A');
	return (0);
	(void) ft_print_stack_rev;
}

static void	ft_print_stack(t_stack *stack, int c)
{
	t_list	*l;

	l = stack->numbers;
	write(1, "-- ", 3);
	write(1, &c, 1);
	write(1, "\n", 1);
	while (l != NULL)
	{
		ft_printf("%d\n", l->content);
		l = l->next;
	}
	write(1, "--\n", 3);
}

static void	ft_print_stack_rev(t_stack *stack, int c)
{
	t_list	*l;

	l = ft_lstlast(stack->numbers);
	write(1, "-- ", 3);
	write(1, &c, 1);
	write(1, "\n", 1);
	while (l != NULL)
	{
		ft_printf("%d\n", l->content);
		l = l->prev;
	}
}
