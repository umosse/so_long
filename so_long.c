/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umosse <umosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 13:52:09 by umosse            #+#    #+#             */
/*   Updated: 2024/04/22 17:13:03 by umosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_destroy(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(0);
}

int	ft_key_pressed(int keysym, t_game *game)
{
	if (keysym == 'w')
		game->w = 1;
	if (keysym == 's')
		game->s = 1;
	if (keysym == 'a')
		game->a = 1;
	if (keysym == 'd')
		game->d = 1;
	if (keysym == 65307)
		ft_destroy(game);
	return (0);
}

int	ft_key_released(int keysym, t_game *game)
{
	if (keysym == 'w')
		game->w = 0;
	if (keysym == 's')
		game->s = 0;
	if (keysym == 'a')
		game->a = 0;
	if (keysym == 'd')
		game->d = 0;
	if (keysym == 'w' || keysym == 's' || keysym == 'a' || keysym == 'd')
	{
		game->steps++;
		ft_printf("Steps : %d\n", game->steps);
	}
	return (0);
}

void	ft_movement(t_game *game)
{
	if (game->w && !game->moved)
		game->y -= 64;
	if (game->s && !game->moved)
		game->y += 64;
	if (game->a && !game->moved)
		game->x -= 64;
	if (game->d && !game->moved)
		game->x += 64;
	if (game->w || game->s || game->a || game->d)
		game->moved = 1;
	else
		game->moved = 0;
}

int	ft_update(t_game *game)
{
	ft_movement(game);
	mlx_clear_window(game->mlx, game->win);
	mlx_put_image_to_window(game->mlx, game->win, game->character, game->x, game->y);
	return (0);
}

int	main(void)
{
	t_game	game;
	int		width;
	int		height;

	game = (t_game) {0};
	game.mlx = mlx_init();
	if (!game.mlx)
		return (1);
	game.win = mlx_new_window(game.mlx, 1280, 720, "so_long");
	game.character = mlx_xpm_file_to_image(game.mlx, CHARACTER, &width, &height);
	game.character2 = mlx_xpm_file_to_image(game.mlx, CHARACTER2, &width, &height);
	mlx_hook(game.win, KeyPress, KeyPressMask, &ft_key_pressed, &game);
	mlx_hook(game.win, KeyRelease, KeyReleaseMask, &ft_key_released, &game);
	mlx_hook(game.win, DestroyNotify, StructureNotifyMask, &ft_destroy, &game);
	mlx_loop_hook(game.mlx, ft_update, &game);
	mlx_loop(game.mlx);
}
