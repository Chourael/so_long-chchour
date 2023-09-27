/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verifmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:55:45 by chchour           #+#    #+#             */
/*   Updated: 2023/09/05 19:55:46 by chchour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_verifhelper1(t_da *da)
{
	int	i;
	int	e;
	int	p;
	int	c;

	i = 0;
	e = 0;
	p = 0;
	c = 0;
	while (da->map[i++] != '\0')
	{
		if (da->map[i] == 'E')
			e++;
		if (da->map[i] == 'P')
			p++;
		if (da->map[i] == 'C')
			c++;
	}
	if (e != 1 || p != 1 || c < 1)
	{
		ft_free1(da);
		ft_printf("Error\nprobleme avec exit/player/item\n");
		return (1);
	}
	return (0);
}

int	ft_verifhelper2(t_da *da)
{
	int	i;

	i = 0;
	da->cmaxforv = 0;
	while (da->map[i] != '\n')
	{
		if (da->map[i] != '1')
		{
			ft_free1(da);
			ft_printf("Error\nmap not protected by walls\n");
			return (1);
		}
		da->cmaxforv++;
		i++;
	}
	da->cmaxforv++;
	return (0);
}

int	ft_verifhelper3(t_da *da)
{
	while (da->map[da->iforv] != '\0')
	{
		da->cforv++;
		if (da->map[da->iforv] == '\n')
		{
			da->lforv++;
			if (da->cmaxforv != da->cforv)
			{
				ft_free1(da);
				ft_printf("Error\nmap irregulier\n");
				return (1);
			}
			if (da->map[da->iforv - 1] != '1' || da->map[da->iforv + 1] != '1')
			{
				ft_free1(da);
				ft_printf("Error\nmap not protected by walls\n");
				return (1);
			}
			da->cforv = 0;
		}
		da->iforv++;
	}
	return (0);
}

int	ft_verifhelper4(t_da *da)
{
	int	i;

	i = 0;
	while (da->map[da->iforv] != '\n')
	{
		if (da->map[da->iforv] != '1')
		{
			ft_free1(da);
			ft_printf("Error\nmap not protected by walls\n");
			return (1);
		}
		da->iforv--;
	}
	while (da->map[i] != '\0')
	{
		if (da->map[i] != '1' && da->map[i] != '0' && da->map[i] != 'P'
			&& da->map[i] != 'E' && da->map[i] != 'C' && da->map[i] != '\n')
		{
			ft_free1(da);
			ft_printf("Error\nunknow organism inside map\n");
			return (1);
		}
		i++;
	}
	return (0);
}

int	ft_verifmap(t_da *da)
{
	if (ft_verifhelper2(da) == 1)
		return (1);
	if (ft_verifhelper3(da) == 1)
		return (1);
	da->cforv++;
	if (da->cforv != da->cmaxforv)
	{
		ft_free1(da);
		ft_printf("Error\nmap irregulier\n");
		return (1);
	}
	if (da->lforv < 2 || da->cmaxforv < 3)
	{
		ft_free1(da);
		ft_printf("Error\nmap too small\n");
		return (1);
	}
	da->iforv--;
	if (ft_verifhelper4(da) == 1)
		return (1);
	if (ft_verifhelper1(da) == 1)
		return (1);
	return (0);
}
