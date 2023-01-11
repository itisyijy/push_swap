/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongyle <jeongyle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 20:54:57 by jeongyle          #+#    #+#             */
/*   Updated: 2023/01/06 20:55:24 by jeongyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"

// sa // sb
void	swap(t_deque *deque)
{
	t_node	*first;
	t_node	*second;
	t_node	*third;

	if (deque->len <= 1)
		return ;
	first = deque->head;
	second = first->next;
	third = second->next;
	first->prev = second;
	first->next = third;
	second->prev = NULL;
	second->next = first;
	if (third)
		third->prev = first;
	deque->head = findHead(first);
	deque->tail = findTail(first);
}

// ss
