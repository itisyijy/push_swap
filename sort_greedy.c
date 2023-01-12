/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_greedy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongyle <jeongyle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 12:36:02 by jeongyle          #+#    #+#             */
/*   Updated: 2023/01/12 17:12:54 by jeongyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bool.h"
#include "sort.h"
#include "inst_rules.h"

int	already_sorted(t_deque *deque)
{
	t_node	*tmp;

	tmp = deque->head;
	while (tmp && tmp->next)
	{
		if (tmp->integer > tmp->next->integer)
			return (FALSE);
		tmp = tmp->next;
	}
	return (TRUE);
}

