/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongyle <jeongyle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 19:03:19 by jeongyle          #+#    #+#             */
/*   Updated: 2023/01/16 20:39:42 by jeongyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "bool.h"
#include "args.h"

int	check_digit(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	if (str[i] == '\0')
		return (FALSE);
	if (str[i] == '0' && str[i + 1] != '\0')
		return (FALSE);
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i] != '\0')
		return (FALSE);
	return (TRUE);
}

int	ps_strncmp(const char *s1, const char *s2, unsigned long n)
{
	unsigned long	i;
	unsigned char	*u1;
	unsigned char	*u2;

	u1 = (unsigned char *)s1;
	u2 = (unsigned char *)s2;
	i = 1;
	if (n == 0)
		return (0);
	while (*u1 != '\0' && *u2 != '\0' && *u1 == *u2 && i < n)
	{
		u1++;
		u2++;
		i++;
	}
	return (*u1 - *u2);
}

int	check_overlap(int count, char **values)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (i + 1 < count)
	{
		tmp = values[i];
		j = i + 1;
		while (j < count)
		{
			if (ps_strncmp(tmp, values[j], 11) == 0)
				return (TRUE);
			j++;
		}
		i++;
	}
	return (FALSE);
}

long	ps_atoi(char *str)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] != '\0')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

void	*allocation(int count, int size)
{
	int		i;
	void	*mem;

	i = -1;
	mem = malloc(count * size);
	if (!mem)
		return (0);
	while (++i < count * size)
		((unsigned char *)mem)[i] = 0;
	return (mem);
}
