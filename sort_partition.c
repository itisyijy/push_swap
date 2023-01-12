/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_partition.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongyle <jeongyle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:00:49 by jeongyle          #+#    #+#             */
/*   Updated: 2023/01/12 17:00:48 by jeongyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bool.h"
#include "sort.h"
#include "inst_rules.h"

// onethird보다 작으면 b의 tail로
// twothird보다 크면 a의 tail로
// 그 외에는 b의 head로

int	check_partition(t_deque *a, int twothird)
{
	t_node	*node;

	node = a->head;
	while (node)
	{
		if (node->integer < twothird)
			return (FALSE);
		node = node->next;
	}
	return (TRUE);
}

void	partition(t_deque *a, t_deque *b)
{
	int		onethird;
	int		twothird;
	t_node	*node;

	onethird = find_onethird(a);
	twothird = find_twothird(a);
	node = a->head;
	while (node && check_partition(a, twothird) == FALSE)
	{
		if (node->integer <= onethird)
		{
			pb(a, b);
			rb(b);
		}
		else if (node->integer >= twothird)
			ra(a);
		else
			pb(a, b);
		node = a->head;
	}
	while (a->len)
		pb(a, b);
}
