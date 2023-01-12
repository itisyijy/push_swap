/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_rotate_print.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongyle <jeongyle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:16:44 by jeongyle          #+#    #+#             */
/*   Updated: 2023/01/12 16:18:32 by jeongyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"
#include "ft_printf.h"
#include "inst_rules.h"

void	ra(t_deque *a)
{
	ft_printf("ra\n");
	rotate(a);
}

void	rb(t_deque *b)
{
	ft_printf("rb\n");
	rotate(b);
}

void	rra(t_deque *a)
{
	ft_printf("rra\n");
	re_rotate(a);
}

void	rrb(t_deque *b)
{
	ft_printf("rrb\n");
	re_rotate(b);
}
