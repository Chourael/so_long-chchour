/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putstuff.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:55:18 by chchour           #+#    #+#             */
/*   Updated: 2023/09/05 19:55:19 by chchour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putcoin(t_da *da)
{
	int	i;

	i = 0;
	while (da->coindata[i] != 1)
	{
		mlx_put_image_to_window(da->mlx, da->window, da->coinimage,
			da->coindata[i], da->coindata[i + 1]);
		i += 2;
	}
}

void	ft_putexit(t_da *da)
{
	mlx_put_image_to_window(da->mlx, da->window, da->exitimage,
		da->exitdata[0], da->exitdata[1]);
}

void	ft_putwall(t_da *da)
{
	int	i;

	i = 0;
	while (da->walldata[i] != 1)
	{
		mlx_put_image_to_window(da->mlx, da->window, da->blockimage,
			da->walldata[i], da->walldata[i + 1]);
		i += 2;
	}
	mlx_put_image_to_window(da->mlx, da->window, da->blockimage,
		da->xmax - 50, 0);
}

void	ft_allwhite(t_da *da)
{
	int		i;
	int		o;

	i = 0;
	o = 0;
	while (i < da->xmax && o < da->ymax)
	{
		while (i < da->xmax)
		{
			mlx_put_image_to_window(da->mlx, da->window, da->whiteimage, i, o);
			i += 50;
		}
		o += 50;
		i = 0;
	}
	ft_putwall(da);
	ft_putcoin(da);
	ft_putexit(da);
}
