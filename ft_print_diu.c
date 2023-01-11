/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_diu.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongyle <jeongyle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 18:28:24 by jeongyle          #+#    #+#             */
/*   Updated: 2022/12/30 17:06:34 by jeongyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printdecarr(char *arr, int size, int sign)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (sign)
	{
		if (write(1, "-", 1) < 0)
			return (-1);
	}
	while (arr[i] == '0' && i < size - 1)
		i++;
	while (i + j < size)
	{
		if (write(1, &arr[i + j], 1) < 0)
			return (-1);
		j++;
	}
	return (j + sign);
}

void	ft_decint(long arg, int index, char *arr)
{
	const char	*dec;

	dec = "0123456789";
	if (arg >= 10)
		ft_decint(arg / 10, index - 1, arr);
	else
	{
		arr[index] = '0';
		if (index > 0)
			ft_decint(0, index - 1, arr);
	}
	arr[index] = dec[arg % 10];
}

int	ft_printdec(va_list ap)
{
	int		len;
	int		sign;
	long	arg;
	char	*arr;

	len = 0;
	arg = va_arg(ap, int);
	sign = 0;
	if (arg < 0)
	{
		sign = 1;
		arg *= -1;
	}
	arr = (char *)malloc(10);
	if (!arr)
		return (-1);
	ft_decint(arg, 9, arr);
	len = ft_printdecarr(arr, 10, sign);
	free(arr);
	return (len);
}

int	ft_printunint(va_list ap)
{
	int				len;
	char			*arr;
	unsigned int	arg;

	len = 0;
	arg = va_arg(ap, unsigned int);
	arr = (char *)malloc(10);
	if (!arr)
		return (-1);
	ft_decint(arg, 9, arr);
	len = ft_printdecarr(arr, 10, 0);
	free(arr);
	return (len);
}
