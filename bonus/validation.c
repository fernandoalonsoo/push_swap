/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 14:03:17 by fernando          #+#    #+#             */
/*   Updated: 2025/04/06 14:03:18 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	repeated(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->size_a)
	{
		j = i + 1;
		while (j < data->size_a)
		{
			if (data->a[i] == data->a[j])
				exit_error(data);
			j++;
		}
		i++;
	}
}

void	check_range(long a, t_data *data)
{
	if ((a < -2147483648) || (a > 2147483647))
		exit_error(data);
}

int	ordered(t_data *data)
{
	int	i;

	i = 0;
	while (i < data-> size_a - 1)
	{
		if (data->a[i] > data->a[i + 1])
			return (0);
		i++;
	}
	return (1);
}
