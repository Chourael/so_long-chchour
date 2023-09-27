/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   takefullmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:55:37 by chchour           #+#    #+#             */
/*   Updated: 2023/09/05 19:55:38 by chchour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_makefullmap(t_da *da, int o)
{
	int	i;

	i = 0;
	if (o == 1)
	{
		while (da->tmp1[i] != '\0')
		{
			da->map[i] = da->tmp1[i];
			i++;
		}
	}
	else
	{
		while (da->tmp2[i] != '\0')
		{
			da->map[i] = da->tmp2[i];
			i++;
		}
	}
	da->map[i] = '\0';
}

int	ft_maphelper1(t_da *da)
{
	if (da->modulo % 2 != 0)
	{
		da->tmp1 = malloc(sizeof(char) * da->allsize + 1);
		if (da->tmp1 == NULL)
			return (1);
		if (da->allsize != da->readsize)
		{
			ft_cpytmp2intmp1(da);
			free(da->tmp2);
			da->tmp2 = NULL;
		}
		ft_cpybufferintmp1(da);
	}
	else
	{
		da->tmp2 = malloc(sizeof(char) * da->allsize + 1);
		if (da->tmp2 == NULL)
			return (1);
		ft_cpytmp1intmp2(da);
		free(da->tmp1);
		da->tmp1 = NULL;
		ft_cpybufferintmp2(da);
	}
	free(da->buffer);
	return (0);
}

void	ft_maphelper2(t_da *da)
{
	free(da->buffer);
	da->buffer = NULL;
	if (da->modulo % 2 != 0)
	{
		da->map = malloc(sizeof(char) * da->allsize + 1);
		ft_makefullmap(da, 2);
		free(da->tmp2);
		da->tmp2 = NULL;
	}
	else
	{
		da->map = malloc(sizeof(char) * da->allsize + 1);
		ft_makefullmap(da, 1);
		free(da->tmp1);
		da->tmp1 = NULL;
	}
}

int	ft_maphelper3(t_da *da)
{
	da->buffer = NULL;
	da->buffer = malloc(sizeof(char) * 1000);
	if (da->buffer == NULL)
		return (1);
	da->readsize = read(da->fd, da->buffer, 1000);
	da->allsize += da->readsize;
	da->remember = 0;
	da->modulo++;
	return (0);
}

int	ft_takefullmap(t_da *da)
{
	ft_init2(da);
	if (da->fd == -1)
	{
		ft_free1(da);
		ft_printf("Error\nprobleme with the map file\n");
		return (1);
	}
	if (ft_takemaphelper(da) == 1)
		return (1);
	if (da->readsize <= 1)
	{
		ft_free1(da);
		ft_printf("Error\nnothing inside map\n");
		return (1);
	}
	while (da->readsize > 0)
	{
		if (ft_maphelper1(da) == 1)
			return (1);
		if (ft_maphelper3(da) == 1)
			return (1);
	}
	ft_maphelper2(da);
	return (0);
}
