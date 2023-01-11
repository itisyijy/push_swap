/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_cs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongyle <jeongyle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 16:27:49 by jeongyle          #+#    #+#             */
/*   Updated: 2022/12/30 17:04:28 by jeongyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printchar(va_list ap)
{
	int				len;
	unsigned char	arg;

	arg = va_arg(ap, int);
	len = write(1, &arg, 1);
	return (len);
}

int	ft_printstr(va_list ap)
{
	int		len;
	int		tmp;
	char	*arg;

	len = 0;
	arg = (char *)va_arg(ap, const char *);
	if (!arg)
	{
		len = write(1, "(null)", 6);
		return (len);
	}
	while (arg[len] != '\0')
	{
		tmp = write(1, &arg[len], 1);
		if (tmp < 0)
			return (tmp);
		len += tmp;
	}
	return (len);
}
