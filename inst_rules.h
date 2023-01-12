/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_rules.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongyle <jeongyle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 19:21:30 by jeongyle          #+#    #+#             */
/*   Updated: 2023/01/12 16:19:04 by jeongyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INST_RULES_H
# define INST_RULES_H

# include "deque.h"

void	swap(t_deque *deque);
void	swapswap(t_deque *a, t_deque *b);
void	sa(t_deque *a);
void	sb(t_deque *b);

void	push(t_deque *from, t_deque *to);
void	pa(t_deque *a, t_deque *b);
void	pb(t_deque *a, t_deque *b);

void	rotate(t_deque *deque);
void	rotaterotate(t_deque *a, t_deque *b);
void	re_rotate(t_deque *deque);
void	re_rotaterotate(t_deque *a, t_deque *b);

void	ra(t_deque *a);
void	rb(t_deque *b);
void	rra(t_deque *a);
void	rrb(t_deque *b);

#endif