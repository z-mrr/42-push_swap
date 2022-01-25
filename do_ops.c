/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_ops.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdias-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 18:24:21 by jdias-mo          #+#    #+#             */
/*   Updated: 2022/01/13 01:18:43 by jdias-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_do_swap(t_list **a, t_list **b, char stack)
{
	if (stack == 'x')
	{
		ft_swap(a);
		ft_swap(b);
		write (1, "ss\n", 3);
	}
	else if (stack == 'a')
	{
		ft_swap(a);
		write (1, "sa\n", 3);
	}
	else if (stack == 'b')
	{
		ft_swap(b);
		write (1, "sb\n", 3);
	}
}

void	ft_do_rotate(t_list **a, t_list **b, char stack)
{
	if (stack == 'x')
	{
		ft_rotate(a);
		ft_rotate(b);
		write(1, "rr\n", 3);
	}
	else if (stack == 'a')
	{
		ft_rotate(a);
		write (1, "ra\n", 3);
	}
	else if (stack == 'b')
	{
		ft_rotate(b);
		write (1, "rb\n", 3);
	}
}

void	ft_do_reverse_rotate(t_list **a, t_list **b, char stack)
{
	if (stack == 'x')
	{
		ft_reverse_rotate(a);
		ft_reverse_rotate(b);
		write (1, "rrr\n", 4);
	}
	else if (stack == 'a')
	{
		ft_reverse_rotate(a);
		write (1, "rra\n", 4);
	}
	else if (stack == 'b')
	{
		ft_reverse_rotate(b);
		write (1, "rrb\n", 4);
	}
}

void	ft_do_push(t_list **a, t_list **b, char stack)
{
	if (stack == 'a')
	{
		ft_push(b, a);
		write (1, "pa\n", 3);
	}
	else if (stack == 'b')
	{
		ft_push(a, b);
		write (1, "pb\n", 3);
	}
}
