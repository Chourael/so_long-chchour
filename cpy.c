/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpy.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:54:26 by chchour           #+#    #+#             */
/*   Updated: 2023/09/05 19:54:29 by chchour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_cpytmp2intmp1(t_da *da)
{
	while (da->tmp2[da->remember] != '\0')
	{
		da->tmp1[da->remember] = da->tmp2[da->remember];
		da->remember++;
	}
}

void	ft_cpybufferintmp1(t_da *da)
{
	int	i;

	i = 0;
	while (da->buffer[i] != '\0')
	{
		da->tmp1[da->remember] = da->buffer[i];
		i++;
		da->remember++;
	}
	da->tmp1[da->remember] = '\0';
}

void	ft_cpytmp1intmp2(t_da *da)
{
	while (da->tmp1[da->remember] != '\0')
	{
		da->tmp2[da->remember] = da->tmp1[da->remember];
		da->remember++;
	}
}

void	ft_cpybufferintmp2(t_da *da)
{
	int	i;

	i = 0;
	while (da->buffer[i] != '\0')
	{
		da->tmp2[da->remember] = da->buffer[i];
		i++;
		da->remember++;
	}
	da->tmp2[da->remember] = '\0';
}
