/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongyle <jeongyle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 20:54:58 by jeongyle          #+#    #+#             */
/*   Updated: 2023/01/16 18:48:03 by jeongyle         ###   ########.fr       */
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
void	*allocation(int count, int size);

int		count_word(char *str);
int		word_len(char *str);
char	*find_word(char *str);
char	*assign_word(char *dst, char *src, int len);
char	**split_word(char *str);

int		count_total_word(int argc, char *argv[]);
char	**make_values(int argc, char *argv[]);
int		count_values(char **values);
char	**check_values(int argc, char *argv[]);

#endif