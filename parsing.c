/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umosse <umosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 14:02:41 by umosse            #+#    #+#             */
/*   Updated: 2024/05/02 13:32:55 by umosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_flood(t_game *game, int posx, int posy)
{
	if (game->maptest[posy][posx] == '1' || game->maptest[posy][posx] == 'B' ||
			game->maptest[posy][posx] == 'X')
		return (1);
	if (game->maptest[posy][posx] == 'P')
		game->pcount++;
	if (game->maptest[posy][posx] == 'E')
		game->ecount++;
	if (game->maptest[posy][posx] == 'C')
		game->ccount++;
	if (game->maptest[posy][posx] != 'P' && game->maptest[posy][posx] != 'E' &&
		game->maptest[posy][posx] != 'C' && game->maptest[posy][posx] != 'B' &&
		game->maptest[posy][posx] != '1' && game->maptest[posy][posx] != '0')
		game->badnum = 1;
	game->maptest[posy][posx] = 'X';
	ft_flood(game, posx, posy + 1);
	ft_flood(game, posx, posy - 1);
	ft_flood(game, posx - 1, posy);
	ft_flood(game, posx + 1, posy);
	return (0);
}

int	ft_ppos2(t_game *game, int x, int y)
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
			if (ft_ppos2(game, x, y) == 1)
				return (1);
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
	if (game->pcount != 1 || game->ecount != 1 || game->ccount < 1)
		return (1);
	if (game->badnum == 1)
		return (1);
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
