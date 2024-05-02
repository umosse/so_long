/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umosse <umosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 13:25:15 by umosse            #+#    #+#             */
/*   Updated: 2024/05/02 13:40:29 by umosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_mapread2(int fd, char *line)
{
	while (line)
	{
		line = get_next_line(fd);
		free(line);
		close(fd);
	}
}

int	ft_mapread3(char *line, t_game *game, int fd)
{
	int	i;

	i = 0;
	while (line)
	{
		game->map[i] = line;
		game->maptest[i] = ft_strdup(line);
		game->maxmapx = ft_strlen(game->map[0]);
		if ((int)ft_strlen(game->map[i]) != game->maxmapx || game->maxmapx > 25)
		{
			ft_mapread2(fd, line);
			return (-1);
		}
		i++;
		line = get_next_line(fd);
	}
	return (i);
}

void	ft_destroyall2(t_game *game)
{
	if (game->enemy2)
		mlx_destroy_image(game->mlx, game->enemy2);
	if (game->death1)
		mlx_destroy_image(game->mlx, game->death1);
	if (game->death2)
		mlx_destroy_image(game->mlx, game->death2);
	if (game->death3)
		mlx_destroy_image(game->mlx, game->death3);
	if (game->death4)
		mlx_destroy_image(game->mlx, game->death4);
	if (game->screen)
		mlx_destroy_image(game->mlx, game->screen);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
		mlx_destroy_display(game->mlx);
}
