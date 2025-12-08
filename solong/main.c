/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhandaq <mkhandaq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 19:31:55 by mkhandaq          #+#    #+#             */
/*   Updated: 2025/12/08 19:55:58 by mkhandaq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

static int	checkarg(char *arg)
{
	int	len;

	len = ft_strlen(arg);
	if (len < 5)
		return (0);
	if (arg[len - 1] != 'r' || arg[len - 2] != 'e' || arg[len - 3] != 'b'
		|| arg[len - 4] != '.')
		return (0);
	return (1);
}

static	void initlong(t_game *g, char **map)
{
	g->map = map;
	g->moves = 0;
	g->map_h = ft_arglen(map);
	g->map_w = ft_strlen(map[0]);
	playerpos(g);
	g->mlx = mlx_init();
	if(!g->mlx)
	{
		freemap(map);
		exit(1);
	}
	g->win = mlx_new_window(g->mlx, g->map_w * IMAGE_SIZE,
		 g->map_h * IMAGE_SIZE, "so_long");
	if(!g->win)
	{
		freemap(map);
		exit(1);
	}
}

int	main(int argc, char **argv)
{
	int	fd;
	char	**map;
	t_game	g;
	if(argc != 2 || !checkarg(argv[1]))
	{
		write(1, "Error\n", 6);
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	if(!fd)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	map = set_map(argv[1], fd);
	close(fd);
	if (!isrectangle(map) || !pathcheck(map))
	{
		write(1, "Error\n", 6);
		freemap(map);
		return (1);
	}
	initlong(&g, map);
	setimage(&g);
	draw(&g);
	mlx_hook(g.win, 17, 0, closewin, &g);
	mlx_key_hook(g.win, handlekey, &g);
	mlx_loop(g.mlx);
	mlx_destroy_window(g.mlx, g.win);
	freemap(map);
	return (0);
}
