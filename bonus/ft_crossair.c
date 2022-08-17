/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_crossair.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 12:49:19 by guderram          #+#    #+#             */
/*   Updated: 2022/08/17 13:17:22 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_put_pixel_cross(t_w_point *w, int x, int y)
{
	int	xx;
	int	yy;
	char *cr;

	cr = w->cr;
	xx = (RES_X / 2) - 32 + x;
	yy = (RES_Y / 2) - 32 + y;
	if (cr[x * 4 + 4 * WALL_SIZE * y] == 0 && cr[x * 4 + 4 * WALL_SIZE * y + 1] == 0 && cr[x * 4 + 4 * WALL_SIZE * y + 2] == 0)
	{
		return ;
	}
	w->str[xx * 4 + 4 * RES_X * yy] = cr[x * 4 + 4 * WALL_SIZE * y];
	w->str[xx * 4 + 4 * RES_X * yy + 1]
		= cr[x * 4 + 4 * WALL_SIZE * y + 1];
	w->str[xx * 4 + 4 * RES_X * yy + 2]
		= cr[x * 4 + 4 * WALL_SIZE * y + 2];
}

void	ft_put_crossair(t_w_point *w)
{
	int	x;
	int y;

	x = 0;
	y = 0;
	while (y < 64)
	{
		while (x < 64)
		{
			ft_put_pixel_cross(w, x, y);
			x++;
		}
		x = 0;
		y++;
	}
}
