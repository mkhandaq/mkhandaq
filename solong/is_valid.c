/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhandaq <mkhandaq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 18:06:44 by mkhandaq          #+#    #+#             */
/*   Updated: 2025/12/10 10:51:03 by mkhandaq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	hb(char **map)
{
	size_t	arglen;
	int		j;

	arglen = ft_arglen(map);
	j = 0;
	while (map[0][j])
	{
		if (map[0][j] != '1')
			return (0);
		j++;
	}
	j = 0;
	while (map[arglen - 1][j])
	{
		if (map[arglen - 1][j] != '1')
			return (0);
		j++;
	}
	return (1);
}

static int	charcount(int *p, int *e, int *c, char map)
{
	if (map == 'P')
		(*p)++;
	else if (map == 'E')
		(*e)++;
	else if (map == 'C')
		(*c)++;
	else if (map == '0' || map == '1')
		return (1);
	else
		return (0);
	return (1);
}

int	searchchar(char **map)
{
	int	i;
	int	j;
	int	p;
	int	e;
	int	c;

	i = 0;
	p = 0;
	e = 0;
	c = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!charcount(&p, &e, &c, map[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	if (p != 1 || e != 1 || c < 1)
		return (0);
	return (1);
}

static int	mapframe(char **map)
{
	int	i;
	int	len;

	i = 0;
	if (!hb(map))
		return (0);
	while (map[i])
	{
		len = ft_strlen(map[i]);
		if (map[i][0] != '1' || map[i][len - 1] != '1')
			return (0);
		i++;
	}
	i = 0;
	return (1);
}

int	isrectangle(char **map)
{
	int	i;
	int	len;
	int	nextlen;

	if (!mapframe(map))
		return (0);
	i = 0;
	while (map[i + 1])
	{
		len = ft_strlen(map[i]);
		nextlen = ft_strlen(map[i + 1]);
		if (len == nextlen)
			i++;
		else
			return (0);
	}
	return (1);
}
