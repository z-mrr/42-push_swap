/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdias-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 09:09:21 by jdias-mo          #+#    #+#             */
/*   Updated: 2022/01/25 12:26:40 by jdias-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_checker_parse(char *op, t_list **a, t_list **b)
{
	if ((op[0] == 's' && op[1] == 'a' && op[2] == '\n')
		|| (op[0] == 's' && op[1] == 'b' && op[2] == '\n')
		|| (op[0] == 's' && op[1] == 's' && op[2] == '\n'))
		ft_checker_swap(a, b, op[1]);
	else if ((op[0] == 'r' && op[1] == 'a' && op[2] == '\n')
		|| (op[0] == 'r' && op[1] == 'b' && op[2] == '\n')
		|| (op[0] == 'r' && op[1] == 'r' && op[2] == '\n'))
		ft_checker_rotate(a, b, op[1]);
	else if ((op[0] == 'r' && op[1] == 'r' && op[2] == 'a' && op[3] == '\n')
		|| (op[0] == 'r' && op[1] == 'r' && op[2] == 'b' && op[3] == '\n')
		|| (op[0] == 'r' && op[1] == 'r' && op[2] == 'r' && op[3] == '\n'))
		ft_checker_reverse_rotate(a, b, op[2]);
	else if ((op[0] == 'p' && op[1] == 'a' && op[2] == '\n')
		|| (op[0] == 'p' && op[1] == 'b' && op[2] == '\n'))
		ft_checker_push(a, b, op[1]);
	else
	{
		write (1, "Error\n", 6);
		return (1);
	}
	return (0);
}

void	ft_checker(t_list **a, t_list **b)
{
	static char	*str;
	char		*op;

	while (1)
	{
		op = get_next_line(&str);
		if (!op || !ft_strlen(op))
		{
			free(op);
			break ;
		}
		if (ft_checker_parse(op, a, b))
		{
			free(str);
			free(op);
			return ;
		}
		free(op);
	}
	if (ft_check_sort(*a) && !*b)
		write (1, "OK\n", 3);
	else
		write (1, "KO\n", 3);
	ft_clear_list(*a);
	ft_clear_list(*b);
}

int	main(int ac, char **av)
{
	t_list		*a;
	t_list		*b;

	if (ac <= 1)
		return (0);
	else if (ft_check_error(ac, av))
		write(2, "Error\n", 6);
	else
	{
		a = NULL;
		b = NULL;
		while (--ac)
			a = ft_add_link(&a, (int)ft_atoi(av[ac]));
		ft_checker(&a, &b);
	}
	return (0);
}
