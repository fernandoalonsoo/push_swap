/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fealonso <fealonso@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 19:52:12 by fealonso          #+#    #+#             */
/*   Updated: 2024/12/28 19:54:08 by fealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "../../push_swap.h"
# include <stddef.h>

long	ft_atol(const char *str);
int		ft_print_char(char c);
int		ft_print_number(int n);
int		ft_print_string(const char *str);
char	**ft_split(char const *s, char c, int *n);
size_t	ft_strlen(const char *s);

#endif