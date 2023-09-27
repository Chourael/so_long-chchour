/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:32:03 by chchour           #+#    #+#             */
/*   Updated: 2023/09/07 13:32:05 by chchour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_freemlx(t_da *da)
{
	mlx_destroy_image(da->mlx, da->whiteimage);
	mlx_destroy_image(da->mlx, da->blockimage);
	mlx_destroy_image(da->mlx, da->stickimage);
	mlx_destroy_image(da->mlx, da->exitimage);
	mlx_destroy_image(da->mlx, da->coinimage);
	mlx_destroy_window(da->mlx, da->window);
	mlx_destroy_display(da->mlx);
	free(da->mlx);
}

void	ft_free1(t_da *da)
{
	if (da->tmp1 != NULL)
		free (da->tmp1);
	if (da->tmp2 != NULL)
		free (da->tmp2);
	if (da->buffer != NULL)
		free (da->buffer);
	if (da->map != NULL)
		free (da->map);
	mlx_destroy_display(da->mlx);
	free(da->mlx);
}

void	ft_free2(t_da *da)
{
	if (da->pa.coindata != NULL)
		free (da->pa.coindata);
	if (da->pa.map != NULL)
		free (da->pa.map);
	if (da->pa.exitdata != NULL)
		free (da->pa.exitdata);
	if (da->coindata != NULL)
		free (da->coindata);
	if (da->walldata != NULL)
		free (da->walldata);
	if (da->exitdata != NULL)
		free (da->exitdata);
	if (da->playerdata != NULL)
		free (da->playerdata);
	if (da->tmp1 != NULL)
		free (da->tmp1);
	if (da->tmp2 != NULL)
		free (da->tmp2);
	if (da->buffer != NULL)
		free (da->buffer);
	if (da->map != NULL)
		free (da->map);
	mlx_destroy_display(da->mlx);
	free(da->mlx);
}

void	ft_freeall(t_da *da)
{
	if (da->coindata != NULL)
		free (da->coindata);
	if (da->walldata != NULL)
		free (da->walldata);
	if (da->exitdata != NULL)
		free (da->exitdata);
	if (da->playerdata != NULL)
		free (da->playerdata);
	if (da->tmp1 != NULL)
		free (da->tmp1);
	if (da->tmp2 != NULL)
		free (da->tmp2);
	if (da->buffer != NULL)
		free (da->buffer);
	if (da->map != NULL)
		free (da->map);
	if (da->pa.coindata != NULL)
		free (da->pa.coindata);
	if (da->pa.map != NULL)
		free (da->pa.map);
	if (da->pa.exitdata != NULL)
		free (da->pa.exitdata);
	ft_freemlx(da);
}
