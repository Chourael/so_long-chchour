/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_image-lib.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:55:03 by chchour           #+#    #+#             */
/*   Updated: 2023/09/05 19:55:04 by chchour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_make_image(t_da *da)
{
	da->whiteimage = mlx_xpm_file_to_image(da->mlx,
			PATHWHITE, &da->image_h, &da->image_w);
	da->blockimage = mlx_xpm_file_to_image(da->mlx,
			PATHBLOCK, &da->image_h, &da->image_w);
	da->stickimage = mlx_xpm_file_to_image(da->mlx,
			PATHSTICK, &da->image_h, &da->image_w);
	da->coinimage = mlx_xpm_file_to_image(da->mlx,
			PATHCOIN, &da->image_h, &da->image_w);
	da->exitimage = mlx_xpm_file_to_image(da->mlx,
			PATHEXIT, &da->image_h, &da->image_w);
}

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (s[count])
		count++;
	while (s[i])
	{
		if (s[count] == (char) c)
			return ((char *)s + count);
		count--;
		i++;
	}
	if (s[count] == (char) c)
		return ((char *)s + count);
	if (c == 0)
		return ((char *)s + i);
	return (0);
}
