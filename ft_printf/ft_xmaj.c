/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xmaj.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 13:52:41 by chchour           #+#    #+#             */
/*   Updated: 2023/04/25 13:26:35 by chchour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_xmaj(unsigned long n)
{
	int			i;
	const char	*hexa;
	char		c;

	i = 0;
	hexa = "0123456789ABCDEF";
	if (n >= 16)
		i += ft_xmaj(n / 16);
	c = hexa[n % 16];
	i += ft_c(c);
	return (i);
}
