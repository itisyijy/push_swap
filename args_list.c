/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongyle <jeongyle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 19:30:14 by jeongyle          #+#    #+#             */
/*   Updated: 2023/01/13 19:30:59 by jeongyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "bool.h"
#include "args.h"

int	check_args(int argc, char *argv[])
{
	int		i;
	long	tmp;

	i = 1;
	if (check_overlap(argc, argv) == TRUE)
		return (FALSE);
	while (i < argc)
	{
		if (check_digit(argv[i]) == FALSE)
			return (FALSE);
		tmp = ps_atoi(argv[i]);
		if (tmp > INTMAX || tmp < INTMIN)
			return (FALSE);
		i++;
	}
	return (TRUE);
}