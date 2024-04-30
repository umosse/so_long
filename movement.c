/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umosse <umosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 13:27:21 by umosse            #+#    #+#             */
/*   Updated: 2024/04/30 14:40:22 by umosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_key_pressed(int keysym, t_game *game)
{
	if (keysym == 'w')
		game->w = 1;
	else if (keysym == 's')
		game->s = 1;
	else if (keysym == 'a')
		game->a = 1;
	else if (keysym == 'd')
		game->d = 1;
	else if (keysym == 65307)
		ft_destroy(game);
	return (0);
}

int	ft_key_released(int keysym, t_game *game)
{
	if (keysym == 'w')
		game->w = 0;
	else if (keysym == 's')
		game->s = 0;
	else if (keysym == 'a')
		game->a = 0;
	else if (keysym == 'd')
		game->d = 0;
	ft_printf("Steps : %d\n", game->steps);
	return (0);
}

void	ft_movement(t_game *game)
{
	if (!game->moved && (game->w || game->s || game->a || game->d))
		game->steps++;
	if (game->w && !game->moved)
		game->y -= 64;
	else if (game->s && !game->moved)
		game->y += 64;
	else if (game->a && !game->moved)
	{
		game->flipped = 1;
		game->x -= 64;
	}
	else if (game->d && !game->moved)
	{
		game->flipped = 0;
		game->x += 64;
	}
	if (game->w || game->s || game->a || game->d)
		game->moved = 1;
	else
		game->moved = 0;
}
