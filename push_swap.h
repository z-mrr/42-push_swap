/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdias-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 18:35:06 by jdias-mo          #+#    #+#             */
/*   Updated: 2022/01/24 15:01:33 by jdias-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}				t_list;

typedef struct s_big
{
	int	partes;
	int	index;
}				t_big;

//checker
int			ft_checker_parse(char *op, t_list **a, t_list **b);
void		ft_checker(t_list **a, t_list **b);
//checker_utils
void		ft_checker_swap(t_list **a, t_list **b, char op);
void		ft_checker_rotate(t_list **a, t_list **b, char op);
void		ft_checker_reverse_rotate(t_list **a, t_list **b, char op);
void		ft_checker_push(t_list **a, t_list **b, char op);
//get_next_line
size_t		ft_pos(char const *s, char c);
void		ft_read(char *buffer, char **str);
char		*ft_line(char **str);
char		*get_next_line(char **str);
size_t		ft_strlen(const char *s);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strdup(const char *s);
//push_swap
int			ft_check_error(int ac, char **av);
void		ft_push_swap(int ac, char **av);
//sort
void		ft_sort_3(t_list **a, t_list **b);
void		ft_sort_small(t_list **a, t_list **b);
void		ft_sort_100(t_list **a, t_list **b);
void		ft_sort_500(t_list **a, t_list **b);
//sort_utils
void		ft_lower_up(t_list **list, t_list **b, t_list **aux);
void		ft_push_low(t_list **a, t_list **b, t_list **aux, t_big big);
void		ft_push_higher(t_list **a, t_list **b, t_list **aux);
int			ft_find_low(t_list *a, t_list *aux, int index);
int			ft_find_pos(t_list *neste, t_list *deste);
//list
t_list		*ft_add_link(t_list **list, int content);
t_list		*ft_add_back(t_list **list, int content);
int			ft_last(t_list *lst);
int			ft_list_size(t_list *lst);
void		ft_clear_list(t_list *list);
//list2
int			ft_check_sort(t_list *lst);
int			ft_check_sort_b(t_list *lst);
void		ft_sort_list(t_list **aux);
void		ft_sort_list_b(t_list **aux);
void		ft_clone_list(t_list *list, t_list **clone);
//ops
void		ft_swap(t_list **list);
void		ft_push(t_list **s_list, t_list **d_list);
void		ft_rotate(t_list **list);
void		ft_reverse_rotate(t_list **list);
//do_ops
void		ft_do_swap(t_list **a, t_list **b, char stack);
void		ft_do_rotate(t_list **a, t_list **b, char stack);
void		ft_do_reverse_rotate(t_list **a, t_list **b, char stack);
void		ft_do_push(t_list **a, t_list **b, char stack);
//utils
long int	ft_atoi(const char *nptr);
void		ft_putchar(char c);
void		ft_putnbr(int n);

#endif
