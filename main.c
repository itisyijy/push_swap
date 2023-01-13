/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongyle <jeongyle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:36:56 by jeongyle          #+#    #+#             */
/*   Updated: 2023/01/13 18:31:12 by jeongyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "args.h"
#include "bool.h"
#include "sort.h"
#include "ft_printf.h"
#include "inst_rules.h"

int	error(void)
{
	write(2, "Error\n", 6);
	return (0);
}

void	print_stack(t_deque *a, t_deque *b)
{
	t_node	*anode;
	t_node	*bnode;

	anode = a->head;
	bnode = b->head;
	ft_printf("--------------------\n");
	while (anode || bnode)
	{
		if (anode)
		{
			ft_printf("%d\t", anode->integer);
			anode = anode->next;
		}
		else
			ft_printf("\t");
		if (bnode)
		{
			ft_printf("%d\t", bnode->integer);
			bnode = bnode->next;
		}	
		else
			ft_printf("\t");
		ft_printf("\n");
	}
	ft_printf("--------------------\n");
}

int	main(int argc, char *argv[])
{
	t_deque	*a;
	t_deque	*b;

	if (argc > 1)
	{
		
	}
	return (0);
}
