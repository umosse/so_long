/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umosse <umosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 23:13:46 by umosse            #+#    #+#             */
/*   Updated: 2024/04/29 23:32:39 by umosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_destroyall(t_game *game)
{
	mlx_destroy_image(game->mlx, game->character);
	mlx_destroy_image(game->mlx, game->character2);
	mlx_destroy_image(game->mlx, game->wall);
	mlx_destroy_image(game->mlx, game->floor);
	mlx_destroy_image(game->mlx, game->opened);
	mlx_destroy_image(game->mlx, game->closed);
	mlx_destroy_image(game->mlx, game->collectible);
	mlx_destroy_image(game->mlx, game->enemy);
	mlx_destroy_image(game->mlx, game->enemy2);
	mlx_destroy_image(game->mlx, game->screen);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
}

void	ft_hooks(t_game *game)
{
	mlx_hook(game->win, KeyPress, KeyPressMask, &ft_key_pressed, game);
	mlx_hook(game->win, DestroyNotify, StructureNotifyMask, &ft_destroy, game);
	mlx_loop_hook(game->mlx, ft_update, game);
	mlx_hook(game->win, KeyRelease, KeyReleaseMask, &ft_key_released, game);
	mlx_loop(game->mlx);
	ft_end(game);
}
