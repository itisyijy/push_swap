/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongyle <jeongyle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 13:12:11 by jeongyle          #+#    #+#             */
/*   Updated: 2022/12/30 17:03:43 by jeongyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(const char *format, va_list ap)
{
	int	len;

	len = 0;
	format++;
	if (*format == 'c')
		len = ft_printchar(ap);
	else if (*format == '%')
		len = write(1, "%", 1);
	else if (*format == 's')
		len = ft_printstr(ap);
	else if (*format == 'p')
		len = ft_printaddress(ap);
	else if (*format == 'X' || *format == 'x')
		len = ft_printhexint(ap, *format);
	else if (*format == 'd' || *format == 'i')
		len = ft_printdec(ap);
	else if (*format == 'u')
		len = ft_printunint(ap);
	return (len);
}

int	ft_printf(const char *format, ...)
{
	int		len;
	int		tmp;
	va_list	ap;

	len = 0;
	tmp = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
			tmp = ft_format(format++, ap);
		else
			tmp = write(1, format, 1);
		if (tmp < 0)
			return (tmp);
		len += tmp;
		format++;
	}
	va_end(ap);
	if (len < tmp)
		return (tmp);
	return (len);
}
