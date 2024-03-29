/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 13:22:27 by guderram          #+#    #+#             */
/*   Updated: 2022/08/30 13:38:28 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int argc, char **argv)
{
	t_m_point	map;

	if (argc != 2)
		return (ft_exor_nfn(1));
	if (ft_check_file_name(argv[1], 1) != 0)
		return (-1);
	printf("\e[m");
	ft_init_map(&map);
	printf("\e[m");
	if (ft_parsing_map(&map, argv[1]) == -1)
		return (-1);
	printf("\e[m");
	ft_windows(&map);
	printf("\e[m");
	return (ft_exit_free_map(&map, 0));
}
