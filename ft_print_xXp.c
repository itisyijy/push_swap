/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_xXp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongyle <jeongyle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:11:07 by jeongyle          #+#    #+#             */
/*   Updated: 2022/12/30 17:07:21 by jeongyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printhexarr(char *arr, int size)
{
	int	i;
	int	j;

	i = 0;
	while (arr[i] == '0' && i < size - 1)
		i++;
	j = 0;
	while (i + j < size)
	{
		if (write(1, &arr[i + j], 1) < 0)
			return (-1);
		j++;
	}
	return (j);
}

void	ft_hexint(unsigned int arg, int index, char *arr, char x)
{
	const char	*hex;

	hex = "0123456789abcdef";
	if (x == 'X')
		hex = "0123456789ABCDEF";
	if (arg >= 16)
		ft_hexint(arg / 16, index - 1, arr, x);
	else
	{
		arr[index] = '0';
		if (index > 0)
			ft_hexint(0, index - 1, arr, x);
	}
	arr[index] = hex[arg % 16];
}

void	ft_hexlong(size_t arg, int index, char *arr)
{
	const char	*hex;

	hex = "0123456789abcdef";
	if (arg >= 16)
		ft_hexlong(arg / 16, index - 1, arr);
	else
	{
		arr[index] = '0';
		if (index > 0)
			ft_hexlong(0, index - 1, arr);
	}
	arr[index] = hex[arg % 16];
}

int	ft_printhexint(va_list ap, char x)
{
	int				len;
	unsigned int	arg;
	char			*arr;

	arg = (unsigned int)va_arg(ap, int);
	len = 0;
	arr = (char *)malloc(8);
	if (!arr)
		return (-1);
	ft_hexint(arg, 7, arr, x);
	len = ft_printhexarr(arr, 8);
	free(arr);
	return (len);
}

int	ft_printaddress(va_list ap)
{
	int		len;
	char	*arr;
	size_t	arg;

	arg = (size_t)va_arg(ap, void *);
	if (write(1, "0x", 2) < 0)
		return (-1);
	arr = (char *)malloc(16);
	if (!arr)
		return (-1);
	ft_hexlong(arg, 15, arr);
	len = ft_printhexarr(arr, 16);
	free(arr);
	if (len < 0)
		return (len);
	return (len + 2);
}
