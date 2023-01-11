/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongyle <jeongyle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:36:56 by jeongyle          #+#    #+#             */
/*   Updated: 2023/01/11 19:15:23 by jeongyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "bool.h"
#include "args.h"
#include "deque.h"
#include "ft_printf.h"

int	error(void)
{
	write(2, "Error\n", 6);
	return (0);
}

int	check_args(int argc, char *argv[])
{
	int	i;

	i = 1;
	if (check_overlap(argc, argv) == TRUE)
		return (FALSE);
	while (i < argc)
	{
		if (check_digit(argv[i]) == FALSE)
			return (FALSE);
		if (check_range(ps_atoi(argv[i])) == FALSE)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int	init_deque(t_deque *deque, int argc, char *argv[])
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (add_node(deque, ps_atoi(argv[i])) == FALSE)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int	main(int argc, char *argv[])
{
	t_deque	*a;
	t_deque	*b;

	if (argc > 1)
	{
		if (check_args(argc, argv) == FALSE)
			return (error());
		a = new_deque();
		b = new_deque();
		if (!a || !b)
			return (error());
		if (init_deque(a, argc, argv) == TRUE)
		{
		}
		else
			return (error());
		clear_deque(a);
		clear_deque(b);
	}
	return (0);
}
