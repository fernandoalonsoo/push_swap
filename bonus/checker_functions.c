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

void	do_operation(char *line, int *a, int *b, t_sizes *sizes);
int		ft_strncmp(const char *s1, const char *s2);

void	checker(int *a, int *b, int n)
{
	char	*line;
	t_sizes	sizes;

	sizes.size_a = n;
	sizes.size_b = 0;
	line = get_next_line(0);
	while (line)
	{
		do_operation(line, a, b, &sizes);
		free(line);
		line = get_next_line(0);
	}
	if (ordered(a, sizes.size_a) && sizes.size_b == 0)
		ft_print_string("OK\n");
	else
		ft_print_string("KO\n");
}

void	do_operation(char *line, int *a, int *b, t_sizes *sizes)
{
	if (ft_strncmp(line, "pa\n", 3) == 0)
		pa(a, &sizes->size_a, b, &sizes->size_b);
	else if (ft_strncmp(line, "pb\n", 3) == 0)
		pb(a, &sizes->size_a, b, &sizes->size_b);
	else if (ft_strncmp(line, "ra\n", 3) == 0)
		ra(a, sizes->size_a);
	else if (ft_strncmp(line, "rb\n", 3) == 0)
		rb(b, sizes->size_b);
	else if (ft_strncmp(line, "rr\n", 3) == 0)
		rr(a, sizes->size_a, b, sizes->size_b);
	else if (ft_strncmp(line, "rra\n", 4) == 0)
		rra(a, sizes->size_a);
	else if (ft_strncmp(line, "rrb\n", 4) == 0)
		rrb(b, sizes->size_b);
	else if (ft_strncmp(line, "rrr\n", 4) == 0)
		rrr(a, sizes->size_a, b, sizes->size_b);
	else if (ft_strncmp(line, "sa\n", 3) == 0)
		sa(a, sizes->size_a);
	else if (ft_strncmp(line, "sb\n", 3) == 0)
		sb(b, sizes->size_b);
	else
	{
		free(line);
		ft_error_exit("Error\n", 1);
	}
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
