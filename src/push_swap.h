/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:04:06 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/03/29 17:41:11 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# include <sys/types.h> /* read */
# include <sys/uio.h> /* read */
# include <unistd.h> /* read, write */
# include <stdlib.h> /* malloc, free, exit */
# include "libft.h" /* ft_printf, ... */

# define LOG		0
# define DIRECTION	1

typedef struct s_list
{
	int				content;
	char			*content_s;
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
	char			**split;
	int				size;
	int				fd;
	int				n_moves;
	int				chunk_size;
}					t_data;

// push_swap functions:

t_data	*ft_init_data(void);
int		ft_parse_arguments(t_data *data, int argc, char **argv);
int		ft_do_logic(t_data *data);
void	ft_print_stacks(t_data *data);
void	ft_exit(int n);
int		ft_issorted(t_data *data);
void	ft_free(t_data *data);
void	ft_case_two(t_data *data);
void	ft_case_three(t_data *data);
void	ft_case_five(t_data *data);

void	ft_pb_smallest(t_data *data);
int		ft_pb_biggest(t_data *data, int chunk);
void	ft_do_chunk_method(t_data *data);
void	ft_pb_by_chunk(t_data *data, int chunk);
void	ft_push_2a_by_chunk(t_data *data, int chunk);
int		ft_nmoves_to_b(t_data *data, t_list *node, int dir);
int		ft_nmoves_to_a(t_data *data, t_list *node, int dir);
int		ft_pb_node(t_data *data, t_list *node, int (*ft)(t_data *));
int		ft_pa_node(t_data *data, t_list *node, int (*ft)(t_data *));

// checker functions:

int		ft_check_logic(t_data *data, t_list *instructions);

// Instructions: push, rotate, 
// reverse rotate and swap.

int		ft_pa(t_data *data);
int		ft_pb(t_data *data);
int		ft_ra(t_data *data);
int		ft_rb(t_data *data);
int		ft_rr(t_data *data);
int		ft_rra(t_data *data);
int		ft_rrb(t_data *data);
int		ft_rrr(t_data *data);
int		ft_sa(t_data *data);
int		ft_sb(t_data *data);
int		ft_ss(t_data *data);

// List functions:

void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstiter_s(t_list *lst, void (*f)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
size_t	ft_lstsize(t_list *lst);
size_t	ft_lst_position(t_list *list, t_list *node);
t_list	*ft_lstnew_str(char *content_s);
t_list	*ft_lstnew(int content);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_search_from(t_data *data, int chunk, int dir);

#endif /* push_swap.h */
