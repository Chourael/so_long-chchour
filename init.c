/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:54:40 by chchour           #+#    #+#             */
/*   Updated: 2023/09/05 19:54:41 by chchour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void	ft_init(t_da *da)
{
	da->move = 0;
	da->xmax = 0;
	da->ymax = 0;
	da->x = 0;
	da->y = 0;
	da->coinmax = 0;
	da->wallmax = 0;
	da->coinleft = 0;
	da->cmaxforv = 0;
	da->cforv = 0;
	da->lforv = 0;
	da->iforv = 0;
}

void	ft_init2(t_da *da)
{
	da->tmp1 = NULL;
	da->tmp2 = NULL;
	da->buffer = NULL;
	da->map = NULL;
	da->modulo = 1;
	da->remember = 0;
	da->fd = open(da->mapfile, O_RDONLY);
}

void	ft_init3(t_da *da)
{
	da->coindata = NULL;
	da->walldata = NULL;
	da->playerdata = NULL;
	da->exitdata = NULL;
	da->j = 0;
	da->k = 0;
	da->l = 0;
}

void	ft_init4(t_da *da)
{
	int	i;

	i = 0;
	da->pa.exitleft = 1;
	da->pa.x = da->playerdata[0];
	da->pa.y = da->playerdata[1];
	da->pa.coinleft = da->coinleft;
	da->pa.coindata = NULL;
	da->pa.coindata = malloc (sizeof(int) * da->coinmax);
	while (da->coindata[i] != 1)
	{
		da->pa.coindata[i] = da->coindata[i];
		i++;
	}
	da->pa.coindata[i] = da->coindata[i];
	ft_init4helper(da);
}
