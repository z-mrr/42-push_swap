/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdias-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 18:22:10 by jdias-mo          #+#    #+#             */
/*   Updated: 2022/01/25 12:24:15 by jdias-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_error(int ac, char **av)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (++i < ac)
	{
		j = -1;
		while (av[i][++j])
		{
			if (av[i][j] == '-' && j == 0)
				j++;
			if (av[i][j] < '0' || av[i][j] > '9')
				return (1);
		}
		k = 0;
		while (++k < ac)
		{
			if (ft_atoi(av[i]) == ft_atoi(av[k]) && i != k)
				return (1);
		}
		if (ft_atoi(av[i]) > 2147483647 || ft_atoi(av[i]) < -2147483648)
			return (1);
	}
	return (0);
}

long int	ft_atoi(const char *nptr)
{
	int			i;
	int			sig;
	long int	res;

	i = 0;
	sig = 1;
	res = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sig = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * 10 + (nptr[i] - '0');
		i++;
	}
	return (res * sig);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	int		i;
	int		nbr[11];

	if (n == -2147483648 || n == 0)
	{
		if (n == -2147483648)
			write(1, "-2147483648", 11);
		else if (n == 0)
			ft_putchar('0');
		return ;
	}
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	i = 0;
	while (n > 0)
	{
		nbr[i] = n % 10;
		n = n / 10;
		i++;
	}
	while (--i >= 0)
		ft_putchar(nbr[i] + '0');
}
