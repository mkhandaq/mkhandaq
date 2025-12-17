/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhandaq <mkhandaq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 17:45:04 by mkhandaq          #+#    #+#             */
/*   Updated: 2025/12/12 17:52:47 by mkhandaq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	**alc(char **map)
{
	char	**copy;
	int		argc;

	argc = ft_arglen(map) + 1;
	copy = malloc((argc) * (sizeof(char *)));
	if (!copy)
		return (NULL);
	return (copy);
}

static char	**hardcopy(char **map)
{
	char	**copy;
	int		i;

	i = 0;
	copy = alc(map);
	if (!copy)
		return (NULL);
	while (map[i])
	{
		copy[i] = ft_strdup(map[i]);
		if (!copy)
			return (NULL);
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

static void	findp(char **map, int *i, int *j)
{
	(*i) = 0;
	while (map[*i])
	{
		(*j) = 0;
		while (map[*i][*j])
		{
			if (map[*i][*j] == 'P')
				return ;
			(*j)++;
		}
		(*i)++;
	}
}

static void	flood_fill(char **copy, int i, int j)
{
	int	str;
	int	arg;

	str = ft_strlen(copy[i]);
	arg = ft_arglen(copy);
	if (i < 0 || j < 0 || j >= str || i >= arg)
		return ;
	if (copy[i][j] == '1' || copy[i][j] == 'V')
		return ;
	copy[i][j] = 'V';
	flood_fill(copy, i + 1, j);
	flood_fill(copy, i - 1, j);
	flood_fill(copy, i, j + 1);
	flood_fill(copy, i, j - 1);
}

int	pathcheck(char **map)
{
	char	**copy;
	int		i;
	int		j;

	copy = hardcopy(map);
	if (!copy)
		return (0);
	findp(copy, &i, &j);
	flood_fill(copy, i, j);
	i = -1;
	while (copy[++i])
	{
		j = 0;
		while (copy[i][j])
		{
			if (copy[i][j] == 'C' || copy[i][j] == 'E')
			{
				freemap(copy);
				return (0);
			}
			j++;
		}
	}
	freemap(copy);
	return (1);
}
