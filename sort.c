/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdias-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 13:07:22 by jdias-mo          #+#    #+#             */
/*   Updated: 2022/02/09 14:50:36 by jdias-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_3(t_list **a, t_list **b)
{
	while (!ft_check_sort(*a))
	{
		if (ft_last(*a) > (*a)->content
			&& (*a)->content > (*a)->next->content)
			ft_do_swap(a, b, 'a');
		else if ((*a)->content > ft_last(*a)
			&& (*a)->content < (*a)->next->content)
			ft_do_reverse_rotate(a, b, 'a');
		else if ((*a)->next->content < ft_last(*a)
			&& ft_last(*a) < (*a)->content)
			ft_do_rotate(a, b, 'a');
		else
			ft_do_swap(a, b, 'a');
	}
}

void	ft_sort_small(t_list **a, t_list **b)
{
	t_list	*aux;
	t_list	*tmp;
	int		i;

	i = 0;
	aux = NULL;
	ft_clone_list(*a, &aux);
	ft_sort_list(&aux);
	tmp = aux;
	if ((*a)->next->next && ft_check_sort((*a)->next) && (*a)->next->content
		< (*a)->content && (*a)->content < (*a)->next->next->content)
		ft_do_swap(a, b, 'a');
	while (ft_list_size(*a) > 3 && !ft_check_sort(*a))
	{
		ft_lower_up(a, b, &aux);
		ft_do_push(a, b, 'b');
		aux = (aux)->next;
		i++;
	}
	ft_sort_3(a, b);
	while (i--)
		ft_do_push(a, b, 'a');
	ft_clear_list(tmp);
}

void	ft_sort_100(t_list **a, t_list **b)
{
	t_big	big;
	t_list	*aux_a;
	t_list	*aux_b;

	aux_a = NULL;
	aux_b = NULL;
	ft_clone_list(*a, &aux_a);
	ft_sort_list(&aux_a);
	big.partes = 4;
	big.index = ft_list_size(aux_a) / big.partes;
	ft_push_low(a, b, &aux_a, big);
	ft_sort_small(a, b);
	ft_clone_list(*b, &aux_b);
	ft_sort_list_b(&aux_b);
	ft_push_higher(a, b, &aux_b);
	ft_clear_list(aux_a);
	ft_clear_list(aux_b);
}

void	ft_sort_500(t_list **a, t_list **b)
{
	t_big	big;
	t_list	*aux_a;
	t_list	*aux_b;

	aux_a = NULL;
	aux_b = NULL;
	ft_clone_list(*a, &aux_a);
	ft_sort_list(&aux_a);
	big.partes = 11;
	big.index = ft_list_size(aux_a) / big.partes;
	ft_push_low(a, b, &aux_a, big);
	ft_sort_small(a, b);
	ft_clone_list(*b, &aux_b);
	ft_sort_list_b(&aux_b);
	ft_push_higher(a, b, &aux_b);
	ft_clear_list(aux_a);
	ft_clear_list(aux_b);
}
