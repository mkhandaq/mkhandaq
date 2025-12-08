/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhandaq <mkhandaq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 17:51:26 by mkhandaq          #+#    #+#             */
/*   Updated: 2025/12/08 19:34:08 by mkhandaq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	maplines(char *av)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	fd = open(av, O_RDONLY);
	line = get_next_line(fd);
	i++;
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		i++;
	}
	close(fd);
	return (i);
}

char	**set_map(char *av, int fd)
{
	char	**map;
	int		i;
	int		arglen;

	i = 0;
	arglen = maplines(av);
	map = malloc(sizeof(char *) * arglen);
	map[i] = get_next_line(fd);
	while (map[i])
	{
		i++;
		map[i] = get_next_line(fd);
	}
	return (map);
}

void	freemap(char **map)
{
	int i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}