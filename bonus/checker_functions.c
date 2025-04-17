/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 10:41:31 by fernando          #+#    #+#             */
/*   Updated: 2025/04/17 10:41:34 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	do_operation(char *line, int *a, int *b,
			int *size_a, int *size_b);
int		ft_strncmp(const char *s1, const char *s2);

void	checker(int *a, int *b, int n)
{
	char	*line;
	int		size_a;
	int		size_b;

	size_a = n;
	size_b = 0;
	line = get_next_line(1);
	while (line)
	{
		do_operation(line, a, b, &size_a, &size_b);
		line = get_next_line(1);
	}
	if (ordered(a, size_a) && size_b == 0)
		ft_print_string("OK\n");
	else
		ft_print_string("KO\n");
}

void	do_operation(char *line, int *a, int *b, int *size_a, int *size_b)
{
	if (ft_strncmp(line, "pa\n"))
		pa(a, size_a, b, size_b);
	else if (ft_strncmp(line, "pb\n"))
		pb(a, size_a, b, size_b);
	else if (ft_strncmp(line, "ra\n"))
		ra(a, *size_a);
	else if (ft_strncmp(line, "rb\n"))
		rb(b, *size_b);
	else if (ft_strncmp(line, "rr\n"))
		rr(a, *size_a, b, *size_b);
	else if (ft_strncmp(line, "rra\n"))
		rra(a, *size_a);
	else if (ft_strncmp(line, "rrb\n"))
		rrb(b, *size_b);
	else if (ft_strncmp(line, "rrr\n"))
		rrr(a, *size_a, b, *size_b);
	else if (ft_strncmp(line, "sa\n"))
		sa(a, *size_a);
	else if (ft_strncmp(line, "sb\n"))
		sb(b, *size_b);
}

int	ft_strncmp(const char *s1, const char *s2)
{
	unsigned char	*p;
	unsigned char	*q;
	size_t			i;

	p = (unsigned char *) s1;
	q = (unsigned char *) s2;
	i = 0;
	while (p[i] != '\0' || q[i] != '\0')
	{
		if (p[i] != q[i])
			return (p[i] - q[i]);
		i++;
	}
	return (0);
}
