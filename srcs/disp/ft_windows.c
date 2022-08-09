/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_windows.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 10:03:21 by guderram          #+#    #+#             */
/*   Updated: 2022/08/09 16:33:59 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_init_w(w_point *w, m_point *m)
{
	// int	size;
	int	nobbp;
	int	nosize_line;
	int	noendian;

	int	sobbp;
	int	sosize_line;
	int	soendian;

	int	eabbp;
	int	easize_line;
	int	eaendian;

	int	webbp;
	int	wesize_line;
	int	weendian;

	w->er = 0;
	printf("INIT win\n");
	w->mlx = mlx_init();
	if (!(w->mlx))
	{
		printf("Init mlx fail !\n");
		w->er = 1;
	}
	w->win1 = mlx_new_window(w->mlx, RES_X, RES_Y, "cub3d");
	if (!(w->win1))
	{
		printf("Init win fail !\n");
		w->er = 1;
	}
	mlx_clear_window(w->mlx, w->win1);
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
	w->c->no = mlx_get_data_addr(w->no, &nobbp, &nosize_line, &noendian);
	w->c->so = mlx_get_data_addr(w->so, &sobbp, &sosize_line, &soendian);
	w->c->ea = mlx_get_data_addr(w->ea, &eabbp, &easize_line, &eaendian);
	w->c->we = mlx_get_data_addr(w->we, &webbp, &wesize_line, &weendian);
	printf("INIT win ok\n");
	ft_found_worldspawn(w);
}

int	ft_is_worldspawn(char c)
{
	if (c == 'N')
		return (1);
	if (c == 'S')
		return (1);
	if (c == 'E')
		return (1);
	if (c == 'W')
		return (1);
	return (0);
}

void	ft_found_worldspawn(w_point *w)
{
	ft_map_disp_pos(w);
	while (w->map->map[w->y] != NULL
		&& ft_is_worldspawn(w->map->map[w->y][w->x]) == 0)
	{
		while (w->map->map[w->y][w->x] != '\0'
			&& ft_is_worldspawn(w->map->map[w->y][w->x]) == 0)
		{
			w->x = w->x + 1;
		}
		if (ft_is_worldspawn(w->map->map[w->y][w->x]) == 0)
		{
			w->x = 0;
			w->y = w->y + 1;
		}
	}
	if (w->map->map[w->y][w->x] == 'N')
		w->d = 90;
	if (w->map->map[w->y][w->x] == 'E')
		w->d = 0;
	if (w->map->map[w->y][w->x] == 'S')
		w->d = 270;
	if (w->map->map[w->y][w->x] == 'W')
		w->d = 180;
}

void	ft_exit_free_all(w_point *w, int ret)
{
	printf("All is begin freeing\n");
	mlx_clear_window(w->mlx, w->win1);
	mlx_destroy_window(w->mlx, w->win1);
	ret = ret;
}

void	ft_windows(m_point *m)
{
	w_point	w;
	v_point	*v;
	h_point	*h;
	c_point *c;

	h = malloc(sizeof(h_point));
	v = malloc(sizeof(v_point));
	c = malloc(sizeof(c_point));
	w.h = h;
	w.v = v;
	w.c = c;
	ft_init_w(&w, m);
	if (w.er > 0)
		ft_exit_free_all(&w, -1);
	printf("Pas d'erreur d'initialisation\n");
	ft_screen_init(&w);
	ft_screen(&w);
	// movement with key maintained
	mlx_hook(w.win1, 02, 1L<<0,  ft_entry_keyboard, &w);
	// movement at key press only
	// mlx_key_hook(w.win1, ft_entry_keyboard, &w);
	mlx_loop(w.mlx);
	ft_exit_free_all(&w, 0);
}
