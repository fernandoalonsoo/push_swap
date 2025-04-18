/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 14:16:43 by fernando          #+#    #+#             */
/*   Updated: 2025/04/06 14:16:44 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "./get_next_line/get_next_line.h"

typedef struct s_data
{
	int		*a;
	int		*b;
	char	**array;
	int		free_array_flag;
	int		size_a;
	int		size_b;
}	t_data;

void	checker(t_data *data);

/* Validation */
void	repeated(t_data *data);
void	check_range(long a, t_data *data);
int		ordered(t_data *data);

/* Utils */
char	**ft_split(char const *s, char c, int *n);
long	ft_atol(const char *str);
int		ft_print_string(const char *str);
void	ft_error_exit(char *msg, int fd);
void	exit_error(t_data *data, int fd);
void	ft_putstr_fd(char *s, int fd);

/* Operations */
void	pa(int *a, int *size_a, int *b, int *size_b);
void	pb(int *a, int *size_a, int *b, int *size_b);
void	sa(int *a, int size_a);
void	sb(int *b, int size_b);
void	ss(int *a, int size_a, int *b, int size_b);
void	ra(int *a, int size_a);
void	rb(int *b, int size_b);
void	rr(int *a, int size_a, int *b, int size_b);
void	rra(int *a, int size_a);
void	rrb(int *b, int size_b);
void	rrr(int *a, int size_a, int *b, int size_b);

#endif
