/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongyle <jeongyle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 19:21:04 by jeongyle          #+#    #+#             */
/*   Updated: 2023/01/11 21:37:12 by jeongyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "deque.h"
#include "bool.h"

t_deque	*new_deque(void)
{
	t_deque	*deque;

	deque = (t_deque *)malloc(sizeof(t_deque));
	if (!deque)
		return (0);
	deque->len = 0;
	deque->head = 0;
	deque->tail = 0;
	return (deque);
}

t_node	*new_node(int integer)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (0);
	node->integer = integer;
	node->next = 0;
	node->prev = 0;
	return (node);
}

int	add_node(t_deque *deque, int integer)
{
	t_node	*node;

	node = new_node(integer);
	if (!deque || !node)
		return (FALSE);
	if (!(deque->head))
		deque->head = node;
	if (deque->tail)
	{
		deque->tail->next = node;
		node->prev = deque->tail;
	}
	deque->tail = node;
	deque->len++;
	return (TRUE);
}

void	clear_deque(t_deque *deque)
{
	t_node	*lst;
	t_node	*tmp;

	lst = deque->head;
	while (lst)
	{
		tmp = lst->next;
		free(lst);
		lst = tmp;
	}
	free(deque);
	deque = NULL;
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
