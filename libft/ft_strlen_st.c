/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
<<<<<<< HEAD:libft/ft_strlen_st.c
/*   ft_strlen_st.c                                     :+:      :+:    :+:   */
=======
/*   mlx_destroy_display.c                              :+:      :+:    :+:   */
>>>>>>> moves:mlx/mlx_destroy_display.c
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD:libft/ft_strlen_st.c
/*   Created: 2022/07/23 09:09:34 by guderram          #+#    #+#             */
/*   Updated: 2022/07/23 09:09:47 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen_st(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
=======
/*   Created: 2020/10/03 18:56:35 by mg                #+#    #+#             */
/*   Updated: 2020/10/04 01:55:35 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_int.h"

int	mlx_destroy_display(t_xvar *xvar)
{
	XCloseDisplay(xvar->display);
>>>>>>> moves:mlx/mlx_destroy_display.c
}
