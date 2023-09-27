/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 13:52:07 by chchour           #+#    #+#             */
/*   Updated: 2023/04/25 13:35:22 by chchour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int				ft_printf(const char *format, ...);
int				ft_c(char c);
int				ft_s(char *s);
int				ft_di(int n);
unsigned int	ft_x(unsigned long n);
unsigned int	ft_xmaj(unsigned long n);
unsigned int	ft_u(unsigned int n);
unsigned long	ft_p(unsigned long n);

#endif
