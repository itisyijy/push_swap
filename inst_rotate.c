/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongyle <jeongyle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 17:29:17 by jeongyle          #+#    #+#             */
/*   Updated: 2023/01/12 16:13:26 by jeongyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"
#include "ft_printf.h"
#include "inst_rules.h"

void	rotate(t_deque *deque)
{
	t_node	*tmp;

	if (deque->len <= 1)
		return ;
	tmp = deque->head;
	deque->head = tmp->next;
	deque->head->prev = 0;
	deque->tail->next = tmp;
	tmp->prev = deque->tail;
	tmp->next = 0;
	deque->tail = tmp;
}

void	rotaterotate(t_deque *a, t_deque *b)
{
	ft_printf("rr\n");
	rotate(a);
	rotate(b);
}

void	re_rotate(t_deque *deque)
{
	t_node	*tmp;

	if (deque->len <= 1)
		return ;
	tmp = deque->tail;
	deque->tail = tmp->prev;
	deque->tail->next = 0;
	deque->head->prev = tmp;
	tmp->next = deque->head;
	tmp->prev = 0;
	deque->head = tmp;
}

void	re_rotaterotate(t_deque *a, t_deque *b)
{
	ft_printf("rrr\n");
	re_rotate(a);
	re_rotate(b);
}
