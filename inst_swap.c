/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongyle <jeongyle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 20:54:57 by jeongyle          #+#    #+#             */
/*   Updated: 2023/01/12 16:15:13 by jeongyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"
#include "ft_printf.h"
#include "inst_rules.h"

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
	second->prev = 0;
	second->next = first;
	if (third)
		third->prev = first;
	deque->head = second;
	while (second->next)
		second = second->next;
	deque->tail = second;
}

void	swapswap(t_deque *a, t_deque *b)
{
	ft_printf("ss\n");
	swap(a);
	swap(b);
}

void	sa(t_deque *a)
{
	ft_printf("sa\n");
	swap(a);
}

void	sb(t_deque *b)
{
	ft_printf("sb\n");
	swap(b);
}
