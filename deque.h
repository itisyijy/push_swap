/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongyle <jeongyle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 19:21:02 by jeongyle          #+#    #+#             */
/*   Updated: 2023/01/11 17:13:54 by jeongyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEQUE_H
# define DEQUE_H

typedef struct s_node
{
	int				integer;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_deque
{
	long	len;
	t_node	*head;
	t_node	*tail;
}	t_deque;

t_deque	*new_deque(void);
t_node	*new_node(int integer);
int		add_node(t_deque *deque, int integer);
void	clear_deque(t_deque *deque);

#endif