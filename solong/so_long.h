/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhandaq <mkhandaq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 19:42:32 by mkhandaq          #+#    #+#             */
/*   Updated: 2025/12/10 10:51:08 by mkhandaq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef IMAGE_SIZE
#  define IMAGE_SIZE 35
# endif

# include "mlx.h"
# include <fcntl.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_image
{
	void	*wall;
	void	*player;
	void	*collector;
	void	*floor;
	void	*exit;
}			t_image;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	int		playerx;
	int		playery;
	int		map_w;
	int		map_h;
	int		moves;
	int		exit_x;
	int		exit_y;
	t_image	image;
}			t_game;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char		*ft_strchr(const char *s, int c);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strdup(const char *s);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*get_next_line(int fd);
void		*ft_memcpy(void *dest, const void *src, size_t n);
size_t		ft_strlen(const char *s);
int			isrectangle(char **map);
int			main(int argc, char **argv);
int			ft_arglen(char **s);
char		**set_map(char *av, int fd);
int			main(int argc, char **argv);
void		freemap(char **map);
void		draw(t_game *g);
void		setimage(t_game *g);
int			pathcheck(char **map);
int			closewin(t_game *g);
int			handlekey(int keycode, t_game *g);
int			searchchar(char **map);
void		playerpos(t_game *g);
void		ft_putnbr(int n);
void		destroy_image(t_game *g);

#endif