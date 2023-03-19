/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:04:06 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/03/19 21:17:01 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# include <sys/types.h> /* read */
# include <sys/uio.h> /* read */
# include <unistd.h> /* read, write */
# include <stdlib.h> /* malloc, free, exit */
# include "libft.h" /* ft_printf, ... */

# define FD			1
# define LOG		1
# define DIRECTION	1

typedef struct s_list
{
	int				content;
	int				index;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

typedef struct s_stack
{
	t_list			*numbers;
}					t_stack;

typedef struct s_data
{
	t_stack			*a;
	t_stack			*b;
	int				size;
	int				n_moves;
}					t_data;

t_data	*ft_init_data(void);
int		ft_parse_arguments(t_data *data, int argc, char **argv);
int		ft_do_logic(t_data *data);
void	ft_exit(int n);
void	ft_print_stacks(t_data *data, int dir);

// swap
int		ft_sa(t_data *data);
int		ft_sb(t_data *data);
int		ft_ss(t_data *data);

// push
int		ft_pa(t_data *data);
int		ft_pb(t_data *data);

// rotate
int		ft_ra(t_data *data);
int		ft_rb(t_data *data);
int		ft_rr(t_data *data);

// reverse rotate
int		ft_rra(t_data *data);
int		ft_rrb(t_data *data);
int		ft_rrr(t_data *data);

void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(int content);
int		ft_lstsize(t_list *lst);

#endif /* push_swap.h */
