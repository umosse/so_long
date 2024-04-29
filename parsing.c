/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umosse <umosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 14:02:41 by umosse            #+#    #+#             */
/*   Updated: 2024/04/29 16:08:23 by umosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_flood(t_game *game, int posx, int posy)
{
	if (game->maptest[posy][posx] == '1' || game->maptest[posy][posx] == 'B' || game->maptest[posy][posx] == 'X')
		return (1);
	if (game->maptest[posy][posx] == 'C')
		game->ccount++;
	game->maptest[posy][posx] = 'X';
	ft_flood(game, posx, posy + 1);
	ft_flood(game, posx, posy - 1);
	ft_flood(game, posx - 1, posy);
	ft_flood(game, posx + 1, posy);
	return (0);
}

int	ft_ppos(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->maxmapy)
	{
		x = 0;
		while (x < game->maxmapx - 1)
		{
			if (game->maptest[y][x] == 'P')
			{
				game->xtest = x;
				game->ytest = y;
			}
			if (x == 0 || y == 0)
			{
				if (game->maptest[y][x] != '1')
					return (1);
			}
			if (x == game->maxmapx - 2 || y == game->maxmapy - 1)
			{
				if (game->maptest[y][x] != '1')
					return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	ft_flood_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	if (ft_ppos(game) == 1)
		return (1);
	ft_flood(game, game->xtest, game->ytest);
	while (y < game->maxmapy)
	{
		x = 0;
		while (x < game->maxmapx)
		{
			if (game->maptest[y][x] == 'C' || game->maptest[y][x] == 'E')
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}
