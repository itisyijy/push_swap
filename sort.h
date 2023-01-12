/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongyle <jeongyle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 12:36:56 by jeongyle          #+#    #+#             */
/*   Updated: 2023/01/12 13:01:13 by jeongyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H

t_node	*find_min(t_deque *deque);
t_node	*find_max(t_deque *deque);
t_node	*find_onethird(t_deque *deque);
t_node	*find_twothird(t_deque *deque);

#endif