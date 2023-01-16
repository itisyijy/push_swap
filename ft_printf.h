/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongyle <jeongyle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 13:28:54 by jeongyle          #+#    #+#             */
/*   Updated: 2023/01/16 16:44:23 by jeongyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
int		ft_format(const char *format, va_list ap);

int		ft_printchar(va_list ap);
int		ft_printstr(va_list ap);

int		ft_printdecarr(char *arr, int size, int sign);
void	ft_decint(long arg, int index, char *arr);
int		ft_printdec(va_list ap);
int		ft_printunint(va_list ap);

int		ft_printhexarr(char *arr, int size);
void	ft_hexint(unsigned int num, int index, char *arr, char x);
void	ft_hexlong(int address, int index, char *arr);
int		ft_printhexint(va_list ap, char x);
int		ft_printaddress(va_list ap);

#endif