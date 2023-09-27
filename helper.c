/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 20:03:14 by chchour           #+#    #+#             */
/*   Updated: 2023/09/05 20:03:15 by chchour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_coinhelper(t_da *da)
{
	int	i;

	i = 0;
	while (da->coindata[i] != 1)
	{
		if (da->x == da->coindata[i] && da->y == da->coindata[i + 1])
		{
			da->coinleft--;
			da->coindata[i] = 0;
			da->coindata[i + 1] = 0;
		}
		i += 2;
	}
}

int	ft_mainhelper(t_da *da)
{
	ft_init(da);
	da->mlx = mlx_init();
	if (ft_datacollection(da) == 1)
		return (1);
	if (ft_pathfinding(da) == 1)
		return (1);
	da->window = mlx_new_window(da->mlx, da->xmax, da->ymax, "so_long");
	ft_make_image(da);
	ft_allwhite(da);
	mlx_put_image_to_window(da->mlx, da->window, da->stickimage, da->x, da->y);
	ft_putwall(da);
	ft_putcoin(da);
	return (0);
}

void	ft_collectionhelper(t_da *da)
{
	da->coindata[da->k] = 1;
	da->walldata[da->l] = 1;
	da->j = 0;
	while (da->j < da->coinmax)
		da->j++;
	da->x = da->playerdata[0];
	da->y = da->playerdata[1];
}

void	ft_init4helper(t_da *da)
{
	int	i;

	i = 0;
	da->pa.map = NULL;
	da->pa.map = malloc (sizeof(char) * da->allsize + 1);
	while (da->map[i] != '\0')
	{
		da->pa.map[i] = da->map[i];
		i++;
	}
	da->pa.map[i] = '\0';
	da->pa.exitdata = NULL;
	da->pa.exitdata = malloc (sizeof(int) * 2);
	da->pa.exitdata[0] = da->exitdata[0];
	da->pa.exitdata[1] = da->exitdata[1];
}

int	ft_takemaphelper(t_da *da)
{
	da->buffer = malloc(sizeof(char) * 10000);
	if (da->buffer == NULL)
		return (1);
	da->readsize = read(da->fd, da->buffer, 10000);
	da->buffer[da->readsize] = '\0';
	da->allsize = da->readsize;
	return (0);
}
