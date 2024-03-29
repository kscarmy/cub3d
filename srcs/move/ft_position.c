/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_position.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 13:30:43 by guderram          #+#    #+#             */
/*   Updated: 2022/08/13 13:34:40 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_map_disp_pos(t_w_point *win)
{
	int	a;
	int	c;

	a = 0;
	c = 0;
	printf("pos : \n");
	while (win->map->map[a] != NULL)
	{
		while (win->map->map[a][c] != '\0')
		{
			printf("\033[0m%c", win->map->map[a][c]);
			c++;
		}
		printf("\n");
		c = 0;
		a++;
	}
}

void	ft_move_in_casa(t_w_point *win)
{
	if (win->pos_x >= 100)
	{
		win->pos_x = 0.01 + (win->pos_x - 100);
		win->x = win->x + 1;
	}
	else if (win->pos_x < 0)
	{
		win->pos_x = 100 + win->pos_x;
		win->x = win->x - 1;
	}
	if (win->pos_y >= 100)
	{
		win->pos_y = 0.01 + (win->pos_y - 100);
		win->y = win->y + 1;
	}
	else if (win->pos_y < 0)
	{
		win->pos_y = 100 + win->pos_y;
		win->y = win->y - 1;
	}
}

void	rotate(int key, t_w_point *win)
{
	if (key == KEY_ROTATE_LEFT)
		win->d = win->d + ANG_SIZE;
	else if (key == KEY_ROTATE_RIGHT)
		win->d = win->d - ANG_SIZE;
	if (win->d < 0)
		win->d = 360 - ANG_SIZE;
	else if (win->d >= 360)
		win->d = 0;
}

void	zqsd(int key, t_w_point *win, int dir)
{
	if (key == KEY_MOVE_FRONT)
	{
		win->pos_y -= find_y(win->d + 270, MOVE_SIZE);
		win->pos_x -= find_x(win->d + 270, MOVE_SIZE);
	}
	else if (key == KEY_MOVE_BACK)
	{
		win->pos_y += find_y(win->d + 270, MOVE_SIZE);
		win->pos_x += find_x(win->d + 270, MOVE_SIZE);
	}
	else if (key == KEY_MOVE_RIGHT)
	{
		win->pos_y -= find_x(win->d + 270, MOVE_SIZE * win->dirx * dir);
		win->pos_x -= find_y(win->d + 270, MOVE_SIZE * win->diry * dir);
	}
	else if (key == KEY_MOVE_LEFT)
	{
		win->pos_y += find_x(win->d + 270, MOVE_SIZE * win->dirx * dir);
		win->pos_x += find_y(win->d + 270, MOVE_SIZE * win->diry * dir);
	}
}

int	ft_move_zqsd(int key, t_w_point *win)
{
	rotate(key, win);
	if (win->d <= 180)
		win->diry = -1;
	else
		win->diry = 1;
	if (win->d >= 90 && win->d <= 270)
		win->dirx = -1;
	else
		win->dirx = 1;
	if (win->d >= 180 && win->d <= 270)
		zqsd(key, win, -1);
	else
		zqsd(key, win, 1);
	if (win->pos_y > 100
		|| win->pos_y < 0
		|| win->pos_x > 100
		|| win->pos_x < 0)
		ft_move_in_casa(win);
	return (0);
}
