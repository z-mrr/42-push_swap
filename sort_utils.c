/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdias-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 00:52:56 by jdias-mo          #+#    #+#             */
/*   Updated: 2022/02/07 23:22:33 by jdias-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lower_up(t_list **a, t_list **b, t_list **aux)
{
	if (ft_find_pos(*aux, *a) <= (ft_list_size(*a) / 2) + 1)
	{
		while ((*a)->content != (*aux)->content)
			ft_do_rotate(a, b, 'a');
	}
	else
	{
		while ((*a)->content != (*aux)->content)
			ft_do_reverse_rotate(a, b, 'a');
	}
}

void	ft_push_low(t_list **a, t_list **b, t_list **aux, t_big big)
{
	while (big.index < ft_list_size(*aux) - 1)
	{
		while (ft_list_size(*b) < big.index)
		{
			if (ft_find_low(*a, *aux, big.index)
				<= (ft_list_size(*aux) / 2) + 1)
			{
				while (ft_find_low(*a, *aux, big.index) != 1)
					ft_do_rotate(a, b, 'a');
			}
			else
			{
				while (ft_find_low(*a, *aux, big.index) != 1)
					ft_do_reverse_rotate(a, b, 'a');
			}
			if (*b && (*b)->content < (*a)->content)
				ft_do_rotate(a, b, 'b');
			if (*b && (*b)->next && (*b)->content < (*b)->next->content)
				ft_do_swap(a, b, 'b');
			ft_do_push(a, b, 'b');
		}
		big.index += ft_list_size(*aux) / big.partes;
	}
}

void	ft_push_higher(t_list **a, t_list **b, t_list **aux)
{
	t_list	*tmp;

	tmp = *aux;
	while (*b)
	{
		if (ft_find_pos(*aux, *b) == 2 && ft_find_pos((*aux)->next, *b) == 1)
		{
			ft_do_swap(a, b, 'b');
			ft_do_push(a, b, 'a');
		}
		else if (ft_find_pos(*aux, *b) <= (ft_list_size(*b) / 2) + 1)
		{
			while ((*b)->content != (*aux)->content)
				ft_do_rotate(a, b, 'b');
			ft_do_push(a, b, 'a');
		}
		else
		{
			while ((*b)->content != (*aux)->content)
				ft_do_reverse_rotate(a, b, 'b');
			ft_do_push(a, b, 'a');
		}
		*aux = (*aux)->next;
	}
	*aux = tmp;
}

int	ft_find_low(t_list *a, t_list *aux, int index)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (a->next)
	{
		i++;
		if (ft_find_pos(a, aux) <= index)
		{
			if (i <= ft_list_size(aux) / 2 && !j)
				j = i;
			else if (i > ft_list_size(aux) / 2)
				k = i;
		}
		a = a->next;
	}
	if ((ft_list_size(aux) - j) > k)
		return (j);
	else
		return (k);
}

int	ft_find_pos(t_list *deste, t_list *neste)
{
	int	i;

	i = 0;
	while (neste)
	{
		i++;
		if (neste->content == deste->content)
			return (i);
		neste = neste->next;
	}
	return (0);
}
