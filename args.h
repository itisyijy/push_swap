/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongyle <jeongyle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 20:54:58 by jeongyle          #+#    #+#             */
/*   Updated: 2023/01/11 14:32:45 by jeongyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARGS_H
# define ARGS_H

# define INTMAX 2147483647
# define INTMIN -2147483648

int		check_digit(char *str);
int		ps_strncmp(const char *s1, const char *s2, unsigned long n);
int		check_overlap(int argc, char *argv[]);
long	ps_atoi(char *str);
int		check_range(long integer);

#endif