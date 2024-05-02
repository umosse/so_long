/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umosse <umosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 23:13:46 by umosse            #+#    #+#             */
/*   Updated: 2024/05/02 13:25:41 by umosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_frames(t_game *game)
{
	game->framecount++;
	if (game->dead == 1)
		game->deathcount++;
	if (game->framecount > 60)
		game->framecount = 0;
}

int	ft_isdead(t_game *game)
{
	if (game->deathcount < 121)
	{
		if (game->deathcount < 21)
			draw_spritec(game, game->death1, game->flipped);
		else if (game->deathcount < 41)
			draw_spritec(game, game->death2, game->flipped);
		else if (game->deathcount < 61)
			draw_spritec(game, game->death3, game->flipped);
		else
			draw_spritec(game, game->death4, game->flipped);
		return (0);
	}
	else
		return (1);
}

void	ft_destroyall(t_game *game)
{
	if (game->character)
		mlx_destroy_image(game->mlx, game->character);
	if (game->character2)
		mlx_destroy_image(game->mlx, game->character2);
	if (game->wall)
		mlx_destroy_image(game->mlx, game->wall);
	if (game->floor)
		mlx_destroy_image(game->mlx, game->floor);
	if (game->opened)
		mlx_destroy_image(game->mlx, game->opened);
	if (game->closed)
		mlx_destroy_image(game->mlx, game->closed);
	if (game->collectible)
		mlx_destroy_image(game->mlx, game->collectible);
	if (game->enemy)
		mlx_destroy_image(game->mlx, game->enemy);
	ft_destroyall2(game);
}

void	ft_hooks(t_game *game)
{
	mlx_hook(game->win, KeyPress, KeyPressMask, &ft_key_pressed, game);
	mlx_hook(game->win, DestroyNotify, StructureNotifyMask, &ft_destroy, game);
	mlx_loop_hook(game->mlx, ft_update, game);
	mlx_hook(game->win, KeyRelease, KeyReleaseMask, &ft_key_released, game);
	mlx_loop(game->mlx);
	ft_end(game, 0);
}

char	**ft_mapalloc(char *file, t_game *game)
{
	int		fd;
	char	*line;
	char	**map;

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
	close(fd);
	return (map);
}
