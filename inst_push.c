/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongyle <jeongyle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 17:29:26 by jeongyle          #+#    #+#             */
/*   Updated: 2023/01/11 21:44:31 by jeongyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"
#include "inst_rules.h"

void	push(t_deque *from, t_deque *to)
{
	t_node	*tmp;
	t_node	*from_head;
	t_node	*to_head;

	if (from->len == 0)
		return ;
	to_head = from->head;
	from_head = from->head->next;
	if (from_head)
		from_head->prev = 0;
	from->head = from_head;
	if (to->head)
		to->head->prev = to_head;
	to_head->next = to->head;
	to->head = to_head;
	tmp = to->head;
	while (tmp && tmp->next)
		tmp = tmp->next;
	to->tail = tmp;
	from->len--;
	to->len++;
}
