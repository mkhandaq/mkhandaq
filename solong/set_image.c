/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhandaq <mkhandaq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 05:01:54 by mkhandaq          #+#    #+#             */
/*   Updated: 2025/12/06 20:15:52 by mkhandaq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	setimage(t_game *g)
{
	int	h;
	int	w;

	g->image.wall = mlx_xpm_file_to_image(g->mlx, "xpm/wall.xpm", &w, &h);
	g->image.player = mlx_xpm_file_to_image(g->mlx, "xpm/player.xpm", &w, &h);
	g->image.collector = mlx_xpm_file_to_image(g->mlx, "xpm/collector.xpm", &w, &h);
	g->image.floor = mlx_xpm_file_to_image(g->mlx, "xpm/floor.xpm", &w, &h);
	g->image.exit = mlx_xpm_file_to_image(g->mlx, "xpm/exit.xpm", &w, &h);
	if (!g->image.wall || !g->image.player || !g->image.collector ||
		!g->image.floor || !g->image.exit)
	{
		write(2, "image load faild\n", 17);
		exit(1);
	}
}

void	draw(t_game *g)
{
	int	i;
	int	j;

	i = 0;
	while (g->map[i])
	{
		j = 0;
		while (g->map[i][j])
		{
			if (g->map[i][j] == '1')
				mlx_put_image_to_window(g->mlx, g->win, g->image.wall, j
						* IMAGE_SIZE, i * IMAGE_SIZE);
			if (g->map[i][j] == '0')
				mlx_put_image_to_window(g->mlx, g->win, g->image.floor, j
						* IMAGE_SIZE, i * IMAGE_SIZE);
			if (g->map[i][j] == 'P')
				mlx_put_image_to_window(g->mlx, g->win, g->image.player, j
						* IMAGE_SIZE, i * IMAGE_SIZE);
			if (g->map[i][j] == 'C')
				mlx_put_image_to_window(g->mlx, g->win, g->image.collector, j
						* IMAGE_SIZE, i * IMAGE_SIZE);
			if (g->map[i][j] == 'E')
				mlx_put_image_to_window(g->mlx, g->win, g->image.exit, j
						* IMAGE_SIZE, i * IMAGE_SIZE);
			j++;
		}
		i++;
	}
}
