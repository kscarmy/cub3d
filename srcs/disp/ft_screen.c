/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_screen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 12:52:57 by guderram          #+#    #+#             */
/*   Updated: 2022/08/07 17:46:49 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_screen_init(w_point *w)
{
	w->sr = 0;
	w->sr = (RES_X / 2) / tan(ft_degrees_to_radian(FOV_SIZE / 2));

	w->map->floor = (w->map->fr << 16) | (w->map->fg << 8) | w->map->fb;
	w->map->ceiling = (w->map->cr << 16) | (w->map->cg << 8) | w->map->cb;
	printf("ft_screen_init : screen range : %f floor %d ceilling %d\n", w->sr, w->map->floor, w->map->ceiling);
}

void	ft_swap_pos(w_point *w)
{
	int	a;
	int	b;

	a = w->x;
	b = w->pos_x;
	w->x = w->y;
	w->y = a;
	w->pos_x = w->pos_y;
	w->pos_y = b;
}

void	ft_screen(w_point *w)
{
	double	i;
	int	max = 0;
	double	r;
	double	d;

	i = 0;
	r = 100000.;
	d = (double)FOV_SIZE / (double)RES_X;
	while (i <= (RES_X / 2) && max < 4)
	{
			/*	ZONE DROITE DE L	ECRAN	*/
		r = ft_thales_range(w, ft_thales_angle_conv(w, d * i * -1));
			/*	FONCTION DAFFICHAGE DE LA COLONNE	*/
		ft_red_pixel(w, (w->sr * (double)WALL_SIZE) / r, (RES_X / 2) + i); // PROVISOIRE

			/*	ZONE GAUCHE DE LECRAN	*/
		r = ft_thales_range(w, ft_thales_angle_conv(w, d * i));
			/*	FONCTION DAFFICHAGE DE LA COLONNE	*/
		ft_red_pixel(w, (w->sr * (double)WALL_SIZE) / r, (RES_X / 2) - i); // PROVISOIRE
		i++;
		max++;
	}
	mlx_put_image_to_window(w->mlx, w->win1, w->screen, 0, 0);
	
	d = d;
	r = r;
	w = w;
}
