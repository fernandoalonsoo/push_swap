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

void	do_operation(char *line, t_data *data);
void	do_operation2(char *line, t_data *data);
int		ft_strcmp(const char *s1, const char *s2);

void	checker(t_data *data)
{
	char	*line;
	char	*remainder;

	remainder = NULL;
	line = get_next_line(0, &remainder);
	while (line)
	{
		do_operation(line, data);
		free(line);
		line = get_next_line(0, &remainder);
	}
	free(remainder);
	if (ordered(data) && data->size_b == 0)
		ft_print_string("OK\n");
	else
		ft_print_string("KO\n");
}

void	do_operation(char *line, t_data *data)
{
	if (ft_strcmp(line, "pa\n") == 0)
		pa(data->a, &data->size_a, data->b, &data->size_b);
	else if (ft_strcmp(line, "pb\n") == 0)
		pb(data->a, &data->size_a, data->b, &data->size_b);
	else if (ft_strcmp(line, "ra\n") == 0)
		ra(data->a, data->size_a);
	else if (ft_strcmp(line, "rb\n") == 0)
		rb(data->b, data->size_b);
	else if (ft_strcmp(line, "rr\n") == 0)
		rr(data->a, data->size_a, data->b, data->size_b);
	else
		do_operation2(line, data);
}

void	do_operation2(char *line, t_data *data)
{
	if (ft_strcmp(line, "rra\n") == 0)
		rra(data->a, data->size_a);
	else if (ft_strcmp(line, "rrb\n") == 0)
		rrb(data->b, data->size_b);
	else if (ft_strcmp(line, "rrr\n") == 0)
		rrr(data->a, data->size_a, data->b, data->size_b);
	else if (ft_strcmp(line, "sa\n") == 0)
		sa(data->a, data->size_a);
	else if (ft_strcmp(line, "sb\n") == 0)
		sb(data->b, data->size_b);
	else if (ft_strcmp(line, "ss\n") == 0)
		ss(data->a, data->size_a, data->b, data->size_b);
	else
	{
		free(line);
		exit_error(data, 2);
	}
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
