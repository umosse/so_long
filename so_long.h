/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umosse <umosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 13:40:52 by umosse            #+#    #+#             */
/*   Updated: 2024/04/29 23:38:50 by umosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H

# include "Libft/libft.h"
# include "Printf/ft_printf.h"
# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"
# include <stddef.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdarg.h>
# include <limits.h>

typedef struct s_game
{
	void			*mlx;
	void			*win;
	int				steps;
	int				x;
	int				y;
	char			**map;
	char			**maptest;
	int				xtest;
	int				ytest;
	t_img			*screen;
	t_img			*character;
	t_img			*character2;
	t_img			*wall;
	t_img			*floor;
	t_img			*opened;
	t_img			*closed;
	t_img			*collectible;
	t_img			*enemy;
	t_img			*enemy2;
	int				w;
	int				a;
	int				s;
	int				d;
	int				moved;
	int				maxmapx;
	int				maxmapy;
	int				flipped;
	int				ccount;
	unsigned long	framecount;
}	t_game;

# define TILE_SIZE 64
# define CHARACTER "textures/AnimationSheet_Character.xpm"
# define CHARACTER2 "textures/AnimationSheet_Character2.xpm"
# define WALL "textures/tiles1.xpm"
# define FLOOR "textures/floor.xpm"
# define OPENED "textures/open.xpm"
# define CLOSED "textures/closed.xpm"
# define COLLECTIBLE "textures/collectible.xpm"
# define ENEMY "textures/Enemy.xpm"
# define ENEMY2 "textures/Enemy2.xpm"

int		ft_key_pressed(int keysym, t_game *game);
int		ft_key_released(int keysym, t_game *game);
void	ft_movement(t_game *game);
int		ft_destroy(t_game *game);
char	**ft_mapread(char *file, t_game *game);
void	ft_mapgen(t_game *game);
int		ft_flood(t_game *game, int posx, int posy);
int		ft_flood_map(t_game *game);
void	draw_sprite(t_game *game, t_img *sp, int x, int y);
void	draw_spritec(t_game *game, t_img *sp, int flipped);
void	clear_screen(t_game *game, unsigned int color);
void	ft_destroyall(t_game *game);
int		ft_update(t_game *game);
void	ft_hooks(t_game *game);
void	ft_end(t_game *game);

#endif