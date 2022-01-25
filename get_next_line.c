/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdias-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 12:12:12 by jdias-mo          #+#    #+#             */
/*   Updated: 2022/01/18 17:29:16 by jdias-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_pos(char const *s, char c)
{
	size_t	i;

	i = 1;
	while (*s)
	{
		if (*s == c)
			return (i);
		i++;
		s++;
	}
	return (0);
}

void	ft_read(char *buffer, char **str)
{
	char	*temp;
	int		r;

	if (!*str || !ft_pos(*str, '\n'))
	{
		r = read(0, buffer, BUFFER_SIZE);
		while (r > 0)
		{
			buffer[r] = '\0';
			if (!*str)
				*str = ft_strdup(buffer);
			else
			{
				temp = *str;
				*str = ft_strjoin(*str, buffer);
				free (temp);
			}
			if (ft_pos(buffer, '\n'))
				break ;
			r = read(0, buffer, BUFFER_SIZE);
		}
	}
	free (buffer);
}

char	*ft_line(char **str)
{
	char			*res;
	char			*temp;
	unsigned int	pos;
	unsigned int	len;

	if (!*str)
		return (0);
	pos = ft_pos(*str, '\n');
	if (!pos)
	{
		res = ft_strdup(*str);
		free (*str);
		*str = 0;
		return (res);
	}
	len = ft_strlen(*str);
	res = ft_substr(*str, 0, pos);
	temp = *str;
	if (len == pos)
		*str = 0;
	else
		*str = ft_substr(*str, pos, len - (pos - 1));
	free(temp);
	return (res);
}

char	*get_next_line(char **str)
{
	char		*buffer;

	buffer = malloc (sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (0);
	ft_read(buffer, str);
	return (ft_line(str));
}
