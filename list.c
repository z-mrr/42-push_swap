/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdias-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 18:21:34 by jdias-mo          #+#    #+#             */
/*   Updated: 2022/01/14 00:47:30 by jdias-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_add_link(t_list **list, int content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = *list;
	return (new);
}

t_list	*ft_add_back(t_list **list, int content)
{
	t_list	*new;
	t_list	*tmp;

	if (!*list)
		return (ft_add_link(list, content));
	else
	{
		tmp = *list;
		while ((*list)->next)
			*list = (*list)->next;
		new = malloc(sizeof(t_list));
		if (!new)
			return (NULL);
		(*list)->next = new;
		new->content = content;
		new->next = NULL;
		*list = tmp;
	}
	return (*list);
}

int	ft_last(t_list *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst->content);
}

int	ft_list_size(t_list *lst)
{
	int	i;

	if (!lst)
		return (0);
	i = 0;
	while (lst)
	{
		lst = lst->next;
		++i;
	}
	return (i);
}

void	ft_clear_list(t_list *list)
{
	t_list	*tmp;

	while (list)
	{
		tmp = list;
		list = list->next;
		free (tmp);
	}
}
