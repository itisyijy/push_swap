/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongyle <jeongyle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 15:25:31 by jeongyle          #+#    #+#             */
/*   Updated: 2023/01/16 20:17:52 by jeongyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "args.h"
#include "bool.h"

int	count_word(char *str)
{
	int	i;
	int	flag;
	int	count;

	i = 0;
	flag = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9' && flag == 0)
		{
			count++;
			flag = 1;
		}
		else if (str[i] < '0' || str[i] > '9')
			flag = 0;
		i++;
	}
	return (count);
}

int	word_len(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0' && str[len] >= '0' && str[len] <= '9')
		len++;
	return (len);
}

char	*find_word(char *str)
{
	while (*str != '\0' && (*str < '0' || *str > '9'))
		str++;
	return (str);
}

char	*assign_word(char *dst, char *src, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src + i);
}

char	**split_word(char *str)
{
	int		i;
	int		count;
	char	**array;

	i = -1;
	count = count_word(str);
	array = allocation(count + 1, sizeof(char *));
	if (!array)
		return (0);
	while (++i < count)
	{
		str = find_word(str);
		array[i] = allocation(word_len(str), sizeof(char));
		if (!array[i])
		{
			while (--i >= 0)
				free(array[i]);
			free(array);
			return (0);
		}
		str = assign_word(array[i], str, word_len(str));
	}
	return (array);
}
