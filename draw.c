/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umosse <umosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 16:51:40 by umosse            #+#    #+#             */
/*   Updated: 2024/04/25 10:25:35 by umosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static inline unsigned int	_get_pixel(t_img *sp, int x, int y, int flipped)
{
	if (!flipped)
		return (((unsigned int *) sp->data)[x + y * sp->width]);
	else
		return (((unsigned int *) sp->data)[(sp->width - x - 1) + y * sp->height]);
}

static inline void	_set_color(t_game *game, int x, int y,
		unsigned int color)
{
	((unsigned int *) game->screen->data)[x + y * game->screen->width] = color;
}

void	draw_sprite(t_game *game, t_img *sp, int x, int y, int flipped)
{
	int				xx;
	int				yy;
	unsigned int	color;

	if (!sp)
		return ;
	yy = -1;
	while (++yy < sp->height)
	{
		xx = -1;
		while (++xx < sp->width)
		{
			if (x + xx < 0 || x + xx >= game->screen->width
				|| y + yy < 0 || y + yy >= game->screen->height)
				continue ;
			color = _get_pixel(sp, xx, yy, flipped);
			if (color != 0xff000000)
				_set_color(game, xx + x, yy + y, color);
		}
	}
}

void	clear_screen(t_game *game, unsigned int color)
{
	const int	s = game->screen->width * game->screen->height;
	int			i;

	i = -1;
	while (++i < s)
		*(((unsigned int *)game->screen->data + i)) = color;
}