/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdias-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 09:35:36 by jdias-mo          #+#    #+#             */
/*   Updated: 2022/01/24 15:01:49 by jdias-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_checker_swap(t_list **a, t_list **b, char op)
{
	if (op == 's')
	{
		ft_swap(a);
		ft_swap(b);
	}
	else if (op == 'a')
		ft_swap(a);
	else if (op == 'b')
		ft_swap(b);
}

void	ft_checker_rotate(t_list **a, t_list **b, char op)
{
	if (op == 'r')
	{
		ft_rotate(a);
		ft_rotate(b);
	}
	else if (op == 'a')
		ft_rotate(a);
	else if (op == 'b')
		ft_rotate(b);
}

void	ft_checker_reverse_rotate(t_list **a, t_list **b, char op)
{
	if (op == 'r')
	{
		ft_reverse_rotate(a);
		ft_reverse_rotate(b);
	}
	else if (op == 'a')
		ft_reverse_rotate(a);
	else if (op == 'b')
		ft_reverse_rotate(b);
}

void	ft_checker_push(t_list **a, t_list **b, char op)
{
	if (op == 'a')
		ft_push(b, a);
	else if (op == 'b')
		ft_push(a, b);
}
