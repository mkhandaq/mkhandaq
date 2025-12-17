/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhandaq <mkhandaq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 19:31:55 by mkhandaq          #+#    #+#             */
/*   Updated: 2025/12/12 18:04:59 by mkhandaq         ###   ########.fr       */
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

static void	initlong(t_game *g, char **map)
{
	g->map = map;
	g->moves = 0;
	g->map_h = ft_arglen(map);
	g->map_w = ft_strlen(map[0]);
	playerpos(g);
	g->mlx = mlx_init();
	if (!g->mlx)
		closewin(g);
	g->win = mlx_new_window(g->mlx, g->map_w * IMAGE_SIZE, g->map_h
			* IMAGE_SIZE, "so_long");
	if (!g->win)
	{
		closewin(g);
		exit(1);
	}
}

static int	print_map_error(char **map)
{
	if (!searchchar(map))
	{
		write(2, "The map has invalid character ", 30);
		write(2, "or invalid characters count\n", 28);
		return (0);
	}
	if (!isrectangle(map))
	{
		write(2, "Map is not coreectly a rectangle ", 33);
		write(2, "Or map's frame is not fully walls \n", 35);
		return (0);
	}
	if (!pathcheck(map))
	{
		write(2, "Not all elements are reachable\n", 31);
		return (0);
	}
	return (1);
}

static int	print_error(int argc, char *argv, int fd, char **map)
{
	if (argc != 2 || !checkarg(argv))
	{
		write(2, "Invalid Map Name\n", 17);
		freemap(map);
		return (0);
	}
	if (fd <= 0)
	{
		write(2, "Did not find a map\n", 19);
		freemap(map);
		return (0);
	}
	if (!print_map_error(map))
	{
		freemap(map);
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int		fd;
	char	**map;
	t_game	g;

	fd = open(argv[1], O_RDONLY);
	map = set_map(argv[1], fd);
	close(fd);
	if (!print_error(argc, argv[1], fd, map))
		return (1);
	initlong(&g, map);
	setimage(&g);
	draw(&g);
	mlx_hook(g.win, 17, 0, closewin, &g);
	mlx_key_hook(g.win, handlekey, &g);
	mlx_loop(g.mlx);
	closewin(&g);
	return (0);
}
