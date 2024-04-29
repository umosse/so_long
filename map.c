/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umosse <umosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 14:23:56 by umosse            #+#    #+#             */
/*   Updated: 2024/04/29 23:39:24 by umosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_mapread(char *file, t_game *game)
{
	int		fd;
	char	*line;
	char	**map;
	int		i;

	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		game->maxmapy++;
		free (line);
		line = get_next_line(fd);
	}
	free (line);
	map = ft_calloc(game->maxmapy, sizeof(char *));
	game->maptest = ft_calloc(game->maxmapy, sizeof(char *));
	i = 0;
	close(fd);
	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		map[i] = line;
		game->maptest[i] = ft_strdup(line);
		game->maxmapx = ft_strlen(map[0]);
		if ((int)ft_strlen(map[i]) != game->maxmapx || game->maxmapx > 25)
			return (NULL);
		i++;
		line = get_next_line(fd);
	}
	if (i > 12)
		return (NULL);
	return (map);
}

void	ft_isc(t_game *game, int x, int y)
{
	if (game->map[y][x] == 'C')
	{
		draw_sprite(game, game->floor, x * 64, y * 64);
		if (game->x == (x * 64) && game->y == (y * 64))
		{
			game->map[y][x] = '0';
			game->ccount -= 1;
		}
		else
			draw_sprite(game, game->collectible, x * 64, y * 64);
	}
}

void	ft_is1(t_game *game, int x, int y)
{
	if (game->map[y][x] == '1')
	{
		draw_sprite(game, game->wall, x * 64, y * 64);
		if (game->x == (x * 64) && game->y == (y * 64))
		{
			if (game->w == 1 || game->s == 1 || game->a == 1 || game->d == 1)
				game->steps--;
			if (game->w == 1)
				game->y += 64;
			else if (game->s == 1)
				game->y -= 64;
			else if (game->a == 1)
				game->x += 64;
			else if (game->d == 1)
				game->x -= 64;
		}
	}
}

void	ft_iseb(t_game *game, int x, int y)
{
	if (game->map[y][x] == 'E')
	{
		draw_sprite(game, game->floor, x * 64, y * 64);
		if (game->ccount >= 1)
			draw_sprite(game, game->closed, x * 64, y * 64);
		else
		{
			draw_sprite(game, game->opened, x * 64, y * 64);
			if (game->x == (x * 64) && game->y == (y * 64))
				ft_destroy(game);
		}
	}
	if (game->map[y][x] == 'B')
	{
		draw_sprite(game, game->floor, x * 64, y * 64);
		if (game->framecount < 31)
			draw_sprite(game, game->enemy, x * 64, y * 64);
		else
			draw_sprite(game, game->enemy2, x * 64, y * 64);
		if (game->x == (x * 64) && game->y == (y * 64))
			ft_destroy(game);
	}
}

void	ft_mapgen(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->maxmapy)
	{
		x = 0;
		while (x < game->maxmapx)
		{
			ft_is1(game, x, y);
			if (game->map[y][x] == '0')
				draw_sprite(game, game->floor, x * 64, y * 64);
			if (game->map[y][x] == 'P')
			{
				game->x = x * 64;
				game->y = y * 64;
				game->map[y][x] = '0';
			}
			ft_isc(game, x, y);
			ft_iseb(game, x, y);
			x++;
		}
		y++;
	}
}
