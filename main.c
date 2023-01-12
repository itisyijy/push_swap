/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongyle <jeongyle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:36:56 by jeongyle          #+#    #+#             */
/*   Updated: 2023/01/11 21:45:43 by jeongyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "args.h"
#include "bool.h"
#include "ft_printf.h"
#include "inst_rules.h"

int	error(void)
{
	write(2, "Error\n", 6);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_node	*tmp;
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
