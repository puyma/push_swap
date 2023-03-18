/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:04:06 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/03/18 18:00:42 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# include <sys/types.h> /* read */
# include <sys/uio.h> /* read */
# include <unistd.h> /* read, write */
# include <stdlib.h> /* malloc, free, exit */
# include "libft.h" /* ft_printf, ... */

# define FD		1

typedef struct s_list
{
	int				content;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

typedef struct s_stack
{
	t_list			*numbers;
}					t_stack;

t_stack	*ft_new_stack(void);
int		ft_parse_arguments(t_stack *stack, int argc, char **argv);
int		ft_do_logic(t_stack *a, t_stack *b);

// swap
int		ft_sa(t_stack *s);
int		ft_sb(t_stack *s);
int		ft_ss(t_stack *a, t_stack *b);

// push
int		ft_pa(t_stack *a, t_stack *b);
int		ft_pb(t_stack *a, t_stack *b);

// rotate
int		ft_ra(t_stack *s);
int		ft_rb(t_stack *s);
int		ft_rr(t_stack *a, t_stack *b);

// reverse rotate
int		ft_rra(t_stack *s);
int		ft_rrb(t_stack *s);
int		ft_rrr(t_stack *a, t_stack *b);

void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(int content);

void	ft_exit(int n);

#endif /* push_swap.h */
