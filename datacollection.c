/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   datacollection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:54:34 by chchour           #+#    #+#             */
/*   Updated: 2023/09/05 19:54:35 by chchour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_datahelper1(t_da *da)
{
	int	i;

	i = 0;
	ft_init3(da);
	if (ft_takefullmap(da) == 1)
		return (1);
	if (ft_verifmap(da) == 1)
		return (1);
	while (da->map[i] != '\n')
	{
		i++;
		da->xmax++;
	}
	i = 0;
	while (da->map[i] != '\0')
	{
		if (da->map[i] == '\n')
			da->ymax++;
		i++;
	}
	da->ymax++;
	da->xmax *= 50;
	da->ymax *= 50;
	return (0);
}

int	ft_datahelper2(t_da *da)
{
	int	i;

	i = 0;
	while (da->map[i] != '\0')
	{
		if (da->map[i] == 'C')
			da->coinmax++;
		if (da->map[i] == '1')
			da->wallmax++;
		i++;
	}
	da->coinleft = da->coinmax;
	da->coinmax *= 2;
	da->coinmax++;
	da->coindata = malloc(sizeof(int) * da->coinmax);
	if (da->coindata == NULL)
		return (1);
	da->wallmax *= 2;
	da->wallmax++;
	da->walldata = malloc(sizeof(int) * da->wallmax);
	if (da->walldata == NULL)
		return (1);
	return (0);
}

void	ft_datahelper3(t_da *da)
{
	if (da->map[da->j] == 'C')
	{
		da->coindata[da->k] = da->x;
		da->coindata[da->k + 1] = da->y;
		da->k += 2;
	}
	if (da->map[da->j] == '1')
	{
		da->walldata[da->l] = da->x;
		da->walldata[da->l + 1] = da->y;
		da->l += 2;
	}
}

int	ft_datahelper4(t_da *da)
{
	if (da->map[da->j] == 'E')
	{
		da->exitdata = malloc(sizeof(int) * 2);
		if (da->exitdata == NULL)
			return (1);
		da->exitdata[0] = da->x;
		da->exitdata[1] = da->y;
	}
	if (da->map[da->j] == 'P')
	{
		da->playerdata = malloc(sizeof(int) * 2);
		if (da->playerdata == NULL)
			return (1);
		da->playerdata[0] = da->x;
		da->playerdata[1] = da->y;
	}
	return (0);
}

int	ft_datacollection(t_da *da)
{
	if (ft_datahelper1(da) == 1)
		return (1);
	if (ft_datahelper2(da) == 1)
		return (1);
	while (da->map[da->j] != '\0')
	{
		ft_datahelper3(da);
		if (ft_datahelper4(da) == 1)
			return (1);
		if (da->map[da->j] == '\n')
		{
			da->y += 50;
			da->x = 0;
		}
		else
			da->x += 50;
		da->j++;
	}
	ft_collectionhelper(da);
	return (0);
}
