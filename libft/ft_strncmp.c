/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 22:53:46 by guderram          #+#    #+#             */
/*   Updated: 2022/07/23 08:50:57 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int	i;
	int	u;

	i = 0;
	u = 0;
	if (!n)
		return (0);
	while (s1[i] == s2[u] && s1[i] && s2[u] && (n > 1))
	{
		i++;
		u++;
		n--;
	}
	i = s1[i];
	u = s2[u];
	return ((unsigned char)i - (unsigned char)u);
}
