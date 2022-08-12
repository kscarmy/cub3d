/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 14:46:41 by guderram          #+#    #+#             */
/*   Updated: 2022/08/12 14:48:51 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_xpm_file_to_image(w_point *w, m_point *m)
{
	w->pos_x = 50;
	w->pos_y = 50;
	w->x = 0;
	w->y = 0;
	w->map = m;
	w->dirx = 0;
	w->diry = 0;
	w->str = NULL;
	w->no = mlx_xpm_file_to_image(w->mlx, w->map->no, &w->c->s, &w->c->s);
	w->so = mlx_xpm_file_to_image(w->mlx, w->map->so, &w->c->s, &w->c->s);
	w->ea = mlx_xpm_file_to_image(w->mlx, w->map->ea, &w->c->s, &w->c->s);
	w->we = mlx_xpm_file_to_image(w->mlx, w->map->we, &w->c->s, &w->c->s);
	w->screen = mlx_new_image(w->mlx, RES_X, RES_Y);
	w->str = mlx_get_data_addr(w->screen, &w->c->bbp, &w->c->sl, &w->c->end);
	ft_init_no(w);
	ft_init_so(w);
	ft_init_ea(w);
	ft_init_we(w);
}

void	ft_init_no(w_point *w)
{
	int	nobbp;
	int	nosize_line;
	int	noendian;

	w->c->no = mlx_get_data_addr(w->no, &nobbp, &nosize_line, &noendian);
}

void	ft_init_so(w_point *w)
{
	int	sobbp;
	int	sosize_line;
	int	soendian;

	w->c->so = mlx_get_data_addr(w->so, &sobbp, &sosize_line, &soendian);
}

void	ft_init_ea(w_point *w)
{
	int	eabbp;
	int	easize_line;
	int	eaendian;

	w->c->ea = mlx_get_data_addr(w->ea, &eabbp, &easize_line, &eaendian);
}

void	ft_init_we(w_point *w)
{
	int	webbp;
	int	wesize_line;
	int	weendian;

	w->c->we = mlx_get_data_addr(w->we, &webbp, &wesize_line, &weendian);
}
