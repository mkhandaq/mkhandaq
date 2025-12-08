/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhandaq <mkhandaq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 17:51:26 by mkhandaq          #+#    #+#             */
/*   Updated: 2025/11/29 05:09:47 by mkhandaq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	maplines(void)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	fd = open("map.ber", O_RDONLY);
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

char	**set_map(int fd)
{
	char	**map;
	int		i;
	int		arglen;

	i = 0;
	arglen = maplines();
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