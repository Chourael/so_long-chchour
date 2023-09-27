/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 20:18:12 by chchour           #+#    #+#             */
/*   Updated: 2023/09/05 20:18:14 by chchour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_verifcoin(t_da *da, int col, int lig)
{
	int	i;

	i = 0;
	while (da->pa.coindata[i] != 1)
	{
		if ((da->pa.x + col) == da->pa.coindata[i]
			&& (da->pa.y + lig) == da->pa.coindata[i + 1])
		{
			da->pa.coinleft--;
			da->pa.coindata[i] = 0;
			da->pa.coindata[i + 1] = 0;
		}
		i += 2;
	}
	if ((da->pa.x + col) == da->pa.exitdata[0]
		&& (da->pa.y + lig) == da->pa.exitdata[1])
	{
		da->pa.exitleft--;
		da->pa.exitdata[0] = 0;
		da->pa.exitdata[1] = 0;
	}
}

int	ft_verifwall(t_da *da, int col, int lig)
{
	int	i;
	int	column;

	column = ((da->xmax) / 50) + 1;
	i = column * (da->pa.y + lig) / 50 + ((da->pa.x + col) / 50);
	if (da->pa.map[i] == '1')
		return (1);
	else
	{
		ft_verifcoin(da, col, lig);
		da->pa.map[i] = '1';
		return (0);
	}
}

int	ft_4path(t_da *da, int col, int lig)
{
	if (ft_verifwall(da, col + 50, lig) != 1)
	{
		ft_4path(da, col + 50, lig);
	}
	if (ft_verifwall(da, col - 50, lig) != 1)
	{
		ft_4path(da, col - 50, lig);
	}
	if (ft_verifwall(da, col, lig + 50) != 1)
	{
		ft_4path(da, col, lig + 50);
	}
	if (ft_verifwall(da, col, lig - 50) != 1)
	{
		ft_4path(da, col, lig - 50);
	}
	return (0);
}

int	ft_pathfinding(t_da *da)
{
	int	i;

	i = 0;
	ft_init4(da);
	ft_4path(da, 0, 0);
	if (da->pa.coinleft > 0 || da->pa.exitleft > 0)
	{
		ft_printf("Error\nmap non faisable\n");
		ft_free2(da);
		return (1);
	}
	return (0);
}
