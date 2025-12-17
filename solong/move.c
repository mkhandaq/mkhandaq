/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhandaq <mkhandaq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 07:37:26 by mkhandaq          #+#    #+#             */
/*   Updated: 2025/12/09 20:54:37 by mkhandaq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	collctors_left(t_game *g)
{
	int	counter;
	int	i;
	int	j;

	counter = 0;
	i = 0;
	while (g->map[i])
	{
		j = 0;
		while (g->map[i][j])
		{
			if (g->map[i][j] == 'C')
				counter++;
			j++;
		}
		i++;
	}
	return (counter);
}

void	playerpos(t_game *g)
{
	int	i;
	int	j;

	i = 0;
	while (g->map[i])
	{
		j = 0;
		while (g->map[i][j])
		{
			if (g->map[i][j] == 'P')
			{
				g->playery = i;
				g->playerx = j;
			}
			else if (g->map[i][j] == 'E')
			{
				g->exit_y = i;
				g->exit_x = j;
			}
			j++;
		}
		i++;
	}
}

static void	moveplayer(t_game *g, int newposy, int newposx)
{
	char	new;

	new = g->map[newposy][newposx];
	if (new == '1')
		return ;
	if (new == 'E' && collctors_left(g) == 0)
	{
		write(1, "You Won!\n", 9);
		closewin(g);
	}
	if (g->playerx == g->exit_x && g->playery == g->exit_y)
		g->map[g->playery][g->playerx] = 'E';
	else
		g->map[g->playery][g->playerx] = '0';
	g->map[newposy][newposx] = 'P';
	g->playery = newposy;
	g->playerx = newposx;
	g->moves++;
	write(1, "Moves: ", 7);
	ft_putnbr(g->moves);
	write(1, "\n", 1);
	draw(g);
}

int	handlekey(int keycode, t_game *g)
{
	if (keycode == 53 || keycode == 65307)
		closewin(g);
	if (keycode == 13 || keycode == 119 || keycode == 65362)
		moveplayer(g, g->playery - 1, g->playerx);
	else if (keycode == 0 || keycode == 97 || keycode == 65361)
		moveplayer(g, g->playery, g->playerx - 1);
	else if (keycode == 1 || keycode == 115 || keycode == 65364)
		moveplayer(g, g->playery + 1, g->playerx);
	else if (keycode == 2 || keycode == 100 || keycode == 65363)
		moveplayer(g, g->playery, g->playerx + 1);
	return (0);
}

int	closewin(t_game *g)
{
	destroy_image(g);
	mlx_destroy_window(g->mlx, g->win);
	mlx_destroy_display(g->mlx);
	freemap(g->map);
	free(g->mlx);
	exit(0);
	return (0);
}
