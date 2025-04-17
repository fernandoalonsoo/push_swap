/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fealonso <fealonso@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 10:58:29 by fealonso          #+#    #+#             */
/*   Updated: 2024/12/29 11:10:56 by fealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

int	ft_print_char(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_print_string(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (ft_print_string("(null)"));
	while (str[i] != '\0')
		ft_print_char(str[i++]);
	return (i);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		write (fd, &s[i], 1);
		i++;
	}
}

void	ft_error_exit(char *msg, int fd)
{
	if (fd == 1)
		ft_print_string(msg);
	else
		ft_putstr_fd(msg, 2);
	exit(0);
}
