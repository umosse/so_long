/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umosse <umosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 13:52:09 by umosse            #+#    #+#             */
/*   Updated: 2024/04/24 14:31:32 by umosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_destroy(t_game *game)
{
	mlx_destroy_image(game->mlx, game->character);
	mlx_destroy_image(game->mlx, game->character2);
	mlx_destroy_image(game->mlx, game->wall);
	mlx_destroy_image(game->mlx, game->floor);
	mlx_destroy_image(game->mlx, game->opened);
	mlx_destroy_image(game->mlx, game->closed);
	mlx_destroy_image(game->mlx, game->collectible);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(0);
}

int	ft_update(t_game *game)
{
	ft_movement(game);
	clear_screen(game, 0);
	ft_mapgen(game);
	draw_sprite(game, game->character, game->x, game->y, game->flipped);
	mlx_put_image_to_window(game->mlx, game->win, game->screen, 0, 0);
	return (0);
}

int	ft_xpm_to_image(t_game *game)
{
	int		width;
	int		height;

	game->character = mlx_xpm_file_to_image(game->mlx, CHARACTER, &width, &height);
	game->character2 = mlx_xpm_file_to_image(game->mlx, CHARACTER2, &width, &height);
	game->wall = mlx_xpm_file_to_image(game->mlx, WALL, &width, &height);
	game->floor = mlx_xpm_file_to_image(game->mlx, FLOOR, &width, &height);
	game->opened = mlx_xpm_file_to_image(game->mlx, OPENED, &width, &height);
	game->closed = mlx_xpm_file_to_image(game->mlx, CLOSED, &width, &height);
	game->collectible = mlx_xpm_file_to_image(game->mlx, COLLECTIBLE, &width, &height);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	game = (t_game) {0};
	game.ccount = 4; //change this after first map parse to know how many C you have
	if (argc == 2)
	{
		game.map = ft_mapread(argv[1], &game);
		if (!game.map)
			return (1);
		game.mlx = mlx_init();
		if (!game.mlx)
			return (1);
		game.win = mlx_new_window(game.mlx, 1536, 768, "so_long");
		ft_xpm_to_image(&game);
		game.screen = mlx_new_image(game.mlx, 1536, 768);
		mlx_hook(game.win, KeyPress, KeyPressMask, &ft_key_pressed, &game);
		mlx_hook(game.win, KeyRelease, KeyReleaseMask, &ft_key_released, &game);
		mlx_hook(game.win, DestroyNotify, StructureNotifyMask, &ft_destroy, &game);
		mlx_loop_hook(game.mlx, ft_update, &game);
		mlx_loop(game.mlx);
	}
}
