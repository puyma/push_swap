/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:04:06 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/03/16 16:48:37 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# include <sys/types.h> /* read */
# include <sys/uio.h> /* read */
# include <unistd.h> /* read, write */
# include <stdlib.h> /* malloc, free, exit */
# include "libft.h" /* ft_printf, ... */

# define FD		1

typedef struct s_stack
{
	char	*name;
	int		*numbers;
}			t_stack;

t_stack	*ft_new_stack(char *name);
int		*ft_parse_arguments(int argc, char **argv);

// swap
int		ft_sa(t_stack *s);
int		ft_sb(t_stack *s);
int		ft_ss(t_stack *a, t_stack *b);

// push
int		ft_pa(t_stack *s);
int		ft_pb(t_stack *s);

// rotate
int		ft_ra(t_stack *s);
int		ft_rb(t_stack *s);
int		ft_rr(t_stack *a, t_stack *b);

// reverse rotate
int		ft_rra(t_stack *s);
int		ft_rrb(t_stack *s);
int		ft_rrr(t_stack *a, t_stack *b);

#endif /* push_swap.h */
