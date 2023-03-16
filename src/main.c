/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:56:31 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/03/16 23:27:30 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_print_stack(t_stack *stack);

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (0);
	a = ft_new_stack("a");
	b = ft_new_stack("b");
	if (ft_parse_arguments(a, argc, argv) == 0)
		ft_exit(0);
	ft_print_stack(a);
	ft_sa(a);
	ft_print_stack(a);
	return (0);
}

static void	ft_print_stack(t_stack *stack)
{
	t_list	*l;

	l = stack->numbers;
	ft_printf("stack: %s\n", stack->name);
	while (l != NULL)
	{
		ft_printf("%d\n", l->content);
		l = l->next;
	}

}
