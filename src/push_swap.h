/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 14:34:17 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/04/03 18:59:14 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <sys/types.h> /* read */
# include <sys/uio.h> /* read */
# include <unistd.h> /* read, write */
# include <stdlib.h> /* malloc, free, exit */
# include "libft.h" /* ft_printf,... */

# define DIRECTION	1 /* rm this one */
# define FORWARD	1
# define BACKWARD	-1
# define BIGGEST	1
# define SMALLEST	0

typedef struct s_list
{
	int				content;
	int				index;
	char			*content_s;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

typedef struct s_stack
{
	t_list			*numbers;
	char			id;
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
int		ft_parse_arguments(t_data *data, int argc, char **argv);
int		ft_do_logic_mini(t_data *data);
int		ft_case_three(t_stack *stack);
int		ft_do_chunk_method(t_data *data);
void	ft_print_stacks(t_data *data);
void	ft_free(t_data *data);
void	ft_exit(int n);

void	ft_push_2b_by_chunk(t_data *data, int chunk);
void	ft_push_back_2a(t_data *data);
void	ft_bring_top(t_stack *stack, t_list *node, t_list *bottom);
void	ft_bring_top_by_chunk(t_stack *stack, int chunk);
void	ft_bring_top_biggest(t_stack *stack, t_stack *stack_a);
t_list	*ft_find(t_stack *stack, int n);
t_list	*ft_find_by_index(t_stack *stack, int index);
int		ft_nmoves_to(t_stack *stack, t_list *node, int dir);
int		ft_issorted(t_stack *stack);

// checker functions:
int		ft_check_logic(t_data *data, t_list *instructions);

// Instructions: push, rotate,
// reverse rotate and swap.
int		push(t_stack *from, t_stack *to, int c);
int		swap(t_stack *stack, int c);
int		rotate(t_stack *stack, int c);
int		rev_rotate(t_stack *stack, int c);

// List functions:
t_list	*ft_lstnew(int content);
t_list	*ft_lstnew_str(char	*content_s);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_search_from(t_stack *stack, int chunk, int dir);
size_t	ft_lst_position(t_list *list, t_list *node);
size_t	ft_lstsize(t_list *lst);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstiter_s(t_list *lst, void (*f)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));

#endif /* push_swap.h */
