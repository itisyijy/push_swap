/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongyle <jeongyle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 19:30:14 by jeongyle          #+#    #+#             */
/*   Updated: 2023/01/16 20:34:07 by jeongyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "bool.h"
#include "args.h"


#include <stdio.h>
int	count_total_word(int argc, char *argv[])
{
	int	i;
	int	total_count;

	i = 1;
	total_count = 0;
	while (i < argc)
		total_count += count_word(argv[i++]);
	return (total_count);
}

int	assign_values(char **values, int j, char **tmp)
{
	int	i;

	i = 0;
	while (tmp[i])
	{
		values[j] = tmp[i];
		j++;
		i++;
	}
	return (j);
}

char	**make_values(int argc, char *argv[])
{
	int		i;
	int		j;
	int		total_count;
	char	**tmp;
	char	**values;

	i = 0;
	j = 0;
	total_count = count_total_word(argc, argv);
	values = (char **)allocation(total_count + 1, sizeof(char *));
	if (!values)
		return (0);
	while (++i < argc)
	{
		tmp = split_word(argv[i]);
		if (!tmp)
			return (0);
		j = assign_values(values, j, tmp);
		free(tmp);
	}
	return (values);
}

int	count_values(char **values)
{
	int	count;

	count = 0;
	while (values[count])
		count++;
	return (count);
}

char	**check_values(int argc, char *argv[])
{
	int		i;
	char	**values;

	i = 0;
	values = make_values(argc, argv);
	if (!values)
		return (0);
	if (check_overlap(count_values(values), values))
		return (0);
	while (check_digit(values[i]))
		i++;
	if (values[i])
	{
		i = 0;
		while (values[i])
			free(values[i++]);
		free(values);
		values = 0;
	}
	return (values);
}
