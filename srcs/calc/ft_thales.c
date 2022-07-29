/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_thales.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 13:25:15 by guderram          #+#    #+#             */
/*   Updated: 2022/07/17 14:00:36 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_set_ca(w_point *win)
{
	win->ca->hx = 0;
	win->ca->hy = 0;
	win->ca->fvcy = 0;
	win->ca->fvcx = 0;
	win->ca->fvcs = 0;
	win->ca->x = 0;
	win->ca->y = 0;
	win->ca->hray = 0;
	win->ca->ohray = 0;
	win->ca->vray = 0;
	win->ca->ovray = 0;
}

double	ft_converte_angle(double d, double a, int sig) // sig = addition 1 ou soustraction 0
{
	double deg;
	
	deg = d;
	if ((deg - a) < 0 && sig == 0)
		return (360 + (deg - a));
	if ((d + a) >= 360 && sig == 1)
		return (360 - (d + a));
	return (d + a);

}

double	ft_found_angle(w_point *w, double d)
{
	// double rh;
	// double rv;
	double x;
	double y;
	
	
	(void)y;
	(void)x;
	(void)w;
	(void)d;
	// vh = 0;
	// vr = 0;
	double	ft_while_vc(w_point *w, double d);
	double	ft_while_hc(w_point *w, double d);
//	while (ft_is_wall)


	// ft_set_ca(win);
	// d = d;
	// printf("ft_found_angle : d %f\n", d);
	// if (d == 0 || d == 90 || d == 180 || d == 270)
	// {
	// 	// printf("ANGLE DROIT\n");
	// 	// return (ft_right_angle(win, d));
	// 	rh = ft_right_angle(win, d);
	// 	// printf("ft_found_angle : r %f\n", rh);
	// 	return (rh);
	// }

	// printf("\n\nPAS ANGLE DROIT\n\n");
		// ft_first_vc(win, d);
		// ft_first_hc(win, d);
	// rh = ft_while_hc(win, d);
	// rh = rh * cos(ft_degrees_to_radian(d));
	
	// rv = ft_while_vc(win, d);
	// rv = rv * cos(ft_degrees_to_radian(d));
	// printf("ft_found_angle : rh %f rv %f \n", rh, rv);
	// printf("rh %f rv %f\n", rh, rv);
	// if (win->ca->hx < 0 || win->ca->hy < 0)
		// return (rv);
	// // printf("")
	// if (win->ca->vx < 0 || win->ca->vy < 0)
		// return (rh);



	// if (rh < rv)
	// 	return (rh);
	// return (rv);




	return (0);
		
		// if (win->ca->hs < win->ca->vs)
		// 	r = win->ca->hs;
		// else
		// 	r = win->ca->vs;

		// win->ca->deg = d;
		// win->ca->rad = ft_degrees_to_radian(win->ca->deg);
		// r = ft_not_angle_droit(win, d);
		// rv = rv;
}

void	ft_thales(w_point *win, double a, int c, int i)	
{
	double h; // hauteur à disp
	double r;

	r = 0;
	ft_reset_ca(win);
	r = ft_found_angle(win, ft_converte_angle(win->d, a, 1)); // droite de l ecran
	// r = ft_abs(r) * 2;  // A SUPP
	// ft_map_disp_pos(win);
	printf("ft_thales : r %f\n", r);
	// printf("screen range : %d\n", win->screen_range);
	// h = (64 / r) * win->screen_range;
	h = (win->screen_range * 64) / r;
	ft_red_pixel(win, h, c + i); // A SUPP LE '- 50'
}



