/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_pivot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongyle <jeongyle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 12:45:44 by jeongyle          #+#    #+#             */
/*   Updated: 2023/01/12 16:35:58 by jeongyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"
#include "deque.h"

t_node	*find_min(t_deque *deque)
{
	t_node	*tmp;
	t_node	*min;

	tmp = deque->head;
	min = deque->head;
	while (tmp && tmp->next)
	{
		if (tmp->integer < min->integer)
			min = tmp;
		tmp = tmp->next;
	}
	return (min);
}

t_node	*find_max(t_deque *deque)
{
	t_node	*tmp;
	t_node	*max;

	tmp = deque->head;
	max = deque->head;
	while (tmp && tmp->next)
	{
		if (tmp->integer > max->integer)
			max = tmp;
		tmp = tmp->next;
	}
	return (max);
}

int	find_onethird(t_deque *deque)
{
	int	min;
	int	max;

	min = find_min(deque)->integer;
	max = find_max(deque)->integer;
	return (min + ((max - min) / 3));
}

int	find_twothird(t_deque *deque)
{
	int	min;
	int	max;

	min = find_min(deque)->integer;
	max = find_max(deque)->integer;
	return (max - ((max - min) / 3));
}
