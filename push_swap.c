/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdias-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 18:22:38 by jdias-mo          #+#    #+#             */
/*   Updated: 2022/01/25 12:24:25 by jdias-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
void	ft_print_list(t_list *list_a, t_list *list_b, t_list *list_aux)
{
	write(1, "[A]\t", 4);
	write(1, "[B]\t", 4);
	write(1, "[X]\n", 4);
	while (list_a || list_b || list_aux)
	{
		if (list_a)
		{
			ft_putnbr(list_a->content);
			list_a = list_a->next;
		}
		ft_putchar('\t');
		if (list_b)
		{
			ft_putnbr(list_b->content);
			list_b = list_b->next;
		}
		ft_putchar('\t');
		if (list_aux)
		{
			ft_putnbr(list_aux->content);
			list_aux = list_aux->next;
		}
		ft_putchar('\n');
	}
}*/

void	ft_push_swap(int ac, char **av)
{
	t_list	*a;
	t_list	*b;
	int		size;

	a = NULL;
	b = NULL;
	size = ac - 1;
	while (--ac)
		a = ft_add_link(&a, (int)ft_atoi(av[ac]));
	if (ft_check_sort(a))
		return ;
	if (size <= 10)
		ft_sort_small(&a, &b);
	else if (size <= 100)
		ft_sort_100(&a, &b);
	else
		ft_sort_500(&a, &b);
	ft_clear_list(a);
}

int	main(int ac, char **av)
{
	if (ac <= 1)
		return (0);
	else if (ft_check_error(ac, av))
		write(2, "Error\n", 6);
	else
		ft_push_swap(ac, av);
	return (0);
}
