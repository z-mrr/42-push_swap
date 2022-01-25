/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdias-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 18:34:32 by jdias-mo          #+#    #+#             */
/*   Updated: 2022/01/13 16:20:09 by jdias-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_list **list)
{
	int	tmp;

	if (!*list || !(*list)->next)
		return ;
	tmp = (*list)->next->content;
	(*list)->next->content = (*list)->content;
	(*list)->content = tmp;
}

void	ft_push(t_list **s_list, t_list **d_list)
{
	t_list	*tmp;

	if (!*s_list)
		return ;
	*d_list = ft_add_link(d_list, (*s_list)->content);
	tmp = *s_list;
	*s_list = tmp->next;
	free (tmp);
}

void	ft_rotate(t_list **list)
{
	t_list	*tmp;
	int		temp;

	if (!*list || !(*list)->next)
		return ;
	tmp = *list;
	temp = (*list)->content;
	while ((*list)->next)
	{
		(*list)->content = (*list)->next->content;
		(*list) = (*list)->next;
	}
	(*list)->content = temp;
	*list = tmp;
}

void	ft_reverse_rotate(t_list **list)
{
	t_list	*tmp;
	t_list	*tmp2;
	int		temp;

	if (!*list || !(*list)->next)
		return ;
	tmp = *list;
	while ((*list)->next->next)
	{
		(*list) = (*list)->next;
	}
	temp = (*list)->next->content;
	tmp2 = (*list)->next;
	(*list)->next = NULL;
	free (tmp2);
	*list = tmp;
	*list = ft_add_link(list, temp);
}
