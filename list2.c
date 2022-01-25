/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdias-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 00:40:57 by jdias-mo          #+#    #+#             */
/*   Updated: 2022/01/14 00:42:34 by jdias-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_sort(t_list *lst)
{
	while (lst->next)
	{
		if (lst->content < lst->next->content)
			lst = lst->next;
		else
			return (0);
	}
	return (1);
}

int	ft_check_sort_b(t_list *lst)
{
	while (lst->next)
	{
		if (lst->content > lst->next->content)
			lst = lst->next;
		else
			return (0);
	}
	return (1);
}

void	ft_sort_list(t_list **aux)
{
	t_list	*tmp;

	tmp = *aux;
	while (!ft_check_sort(*aux))
	{
		while ((*aux)->next)
		{
			if ((*aux)->content > (*aux)->next->content)
				ft_swap(aux);
			(*aux) = (*aux)->next;
		}
		*aux = tmp;
	}
}

void	ft_sort_list_b(t_list **aux)
{
	t_list	*tmp;

	tmp = *aux;
	while (!ft_check_sort_b(*aux))
	{
		while ((*aux)->next)
		{
			if ((*aux)->content < (*aux)->next->content)
				ft_swap(aux);
			(*aux) = (*aux)->next;
		}
		*aux = tmp;
	}
}

void	ft_clone_list(t_list *list, t_list **clone)
{
	int	i;

	i = ft_list_size(list);
	while (i)
	{
		*clone = ft_add_back(clone, list->content);
		i--;
		list = list->next;
	}
}
