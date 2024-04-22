/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umosse <umosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 13:40:52 by umosse            #+#    #+#             */
/*   Updated: 2024/04/22 17:12:22 by umosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H

# include "Libft/libft.h"
# include "Printf/ft_printf.h"
# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"
# include <stddef.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdarg.h>
# include <limits.h>

typedef struct s_game
{
	void	*mlx;
	void	*win;
	int		steps;
	int		x;
	int		y;
	t_img	*screen;
	t_img	*character;
	t_img	*character2;
	int		w;
	int		a;
	int		s;
	int		d;
	int		moved;
}	t_game;

# define TILE_SIZE 64
# define CHARACTER "textures/AnimationSheet_Character.xpm"
# define CHARACTER2 "textures/AnimationSheet_Character2.xpm"

#endif