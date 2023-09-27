/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 13:52:01 by chchour           #+#    #+#             */
/*   Updated: 2023/04/25 13:27:46 by chchour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_format(char c, va_list n)
{
	if (c == 'c')
		return (ft_c(va_arg (n, int)));
	else if (c == 's')
		return (ft_s(va_arg(n, char *)));
	else if (c == 'd' || c == 'i')
		return (ft_di(va_arg(n, int)));
	else if (c == 'u')
		return (ft_u(va_arg(n, unsigned int)));
	else if (c == 'x')
		return (ft_x(va_arg(n, unsigned int)));
	else if (c == 'X')
		return (ft_xmaj(va_arg(n, unsigned int)));
	else if (c == '%')
		return (ft_c('%'));
	else if (c == 'p')
		return (ft_p(va_arg(n, unsigned long)));
	return (-1);
}

int	ft_printf(const char *format, ...)
{
	va_list	n;
	int		i;
	int		count;
	int		counter;

	va_start(n, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			counter = 0;
			counter = ft_format(format [++i], n);
			if (counter == -1)
				return (0);
			count += counter;
		}
		else
			count += write(1, &format[i], 1);
		i++;
	}
	va_end(n);
	return (count);
}
