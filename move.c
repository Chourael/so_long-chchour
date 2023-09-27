/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:55:13 by chchour           #+#    #+#             */
/*   Updated: 2023/09/05 19:55:15 by chchour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_up(t_da *da)
{
	int	i;

	i = 0;
	if (da->x == da->exitdata[0] && (da->y - 50) == da->exitdata[1])
	{
		if (da->coinleft == 0)
		{
			ft_freeall(da);
			exit(0);
		}
	}
	while (da->walldata[i] != 1)
	{
		if (da->x == da->walldata[i] && (da->y - 50) == da->walldata[i + 1])
		{
			return (0);
		}
		i += 2;
	}
	mlx_put_image_to_window(da->mlx, da->window, da->whiteimage, da->x, da->y);
	da->y -= 50;
	mlx_put_image_to_window(da->mlx, da->window, da->stickimage, da->x, da->y);
	da->move++;
	ft_printf("%d\n", da->move);
	return (0);
}

int	ft_left(t_da *da)
{
	int	i;

	i = 0;
	if ((da->x - 50) == da->exitdata[0] && da->y == da->exitdata[1])
	{
		if (da->coinleft == 0)
		{
			ft_freeall(da);
			exit(0);
		}
	}
	while (da->walldata[i] != 1)
	{
		if ((da->x - 50) == da->walldata[i] && da->y == da->walldata[i + 1])
		{
			return (0);
		}
		i += 2;
	}
	mlx_put_image_to_window(da->mlx, da->window, da->whiteimage, da->x, da->y);
	da->x -= 50;
	mlx_put_image_to_window(da->mlx, da->window, da->stickimage, da->x, da->y);
	da->move++;
	ft_printf("%d\n", da->move);
	return (0);
}

int	ft_down(t_da *da)
{
	int	i;

	i = 0;
	if (da->x == da->exitdata[0] && (da->y + 50) == da->exitdata[1])
	{
		if (da->coinleft == 0)
		{
			ft_freeall(da);
			exit(0);
		}
	}
	while (da->walldata[i] != 1)
	{
		if (da->x == da->walldata[i] && (da->y + 50) == da->walldata[i + 1])
		{
			return (0);
		}
		i += 2;
	}
	mlx_put_image_to_window(da->mlx, da->window, da->whiteimage, da->x, da->y);
	da->y += 50;
	mlx_put_image_to_window(da->mlx, da->window, da->stickimage, da->x, da->y);
	da->move++;
	ft_printf("%d\n", da->move);
	return (0);
}

int	ft_right(t_da *da)
{
	int	i;

	i = 0;
	if ((da->x + 50) == da->exitdata[0] && da->y == da->exitdata[1])
	{
		if (da->coinleft == 0)
		{
			ft_freeall(da);
			exit(0);
		}
	}
	while (da->walldata[i] != 1)
	{
		if ((da->x + 50) == da->walldata[i] && da->y == da->walldata[i + 1])
		{
			return (0);
		}
		i += 2;
	}
	mlx_put_image_to_window(da->mlx, da->window, da->whiteimage, da->x, da->y);
	da->x += 50;
	mlx_put_image_to_window(da->mlx, da->window, da->stickimage, da->x, da->y);
	da->move++;
	ft_printf("%d\n", da->move);
	return (0);
}
