/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umosse <umosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 14:23:56 by umosse            #+#    #+#             */
/*   Updated: 2024/04/24 15:20:55 by umosse           ###   ########.fr       */
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
		game->mapy++;
		free (line);
		line = get_next_line(fd);
	}
	map = ft_calloc(game->mapy, sizeof(char *));
	i = 0;
	close(fd);
	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		map[i] = line;
		if (ft_strlen(map[i]) != ft_strlen(map[0]))
			return (NULL);
		i++;
		line = get_next_line(fd);
	}
	return (map);
}

void	ft_mapgen(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->mapy)
	{
		x = 0;
		while (x < (int)ft_strlen(game->map[0]))
		{
			if (game->map[y][x] == '1')
			{
				draw_sprite(game, game->wall, x * 64, y * 64, 0);
			}
			if (game->map[y][x] == '0')
				draw_sprite(game, game->floor, x * 64, y * 64, 0);
			if (game->map[y][x] == 'P')
			{
				game->x = x * 64;
				game->y = y * 64;
				game->map[y][x] = '0';
			}
			if (game->map[y][x] == 'C')
			{
				draw_sprite(game, game->floor, x * 64, y * 64, 0);
				if (game->x == (x * 64) && game->y == (y * 64))
				{
					game->map[y][x] = '0';
					game->ccount -= 1;
				}
				else
					draw_sprite(game, game->collectible, x * 64, y * 64, 0);
			}
			if (game->map[y][x] == 'E')
			{
				draw_sprite(game, game->floor, x * 64, y * 64, 0);
				if (game->ccount >= 1)
					draw_sprite(game, game->closed, x * 64, y * 64, 0);
				else
				{
					draw_sprite(game, game->opened, x * 64, y * 64, 0);
					if (game->x == (x * 64) && game->y == (y * 64))
						ft_destroy(game);
				}
			}
			x++;
		}
		y++;
	}
}
