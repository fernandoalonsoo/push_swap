/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 10:42:49 by fernando          #+#    #+#             */
/*   Updated: 2025/04/17 10:42:51 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	initialise_stacks(t_data *data);
void	free_memory(t_data *data);

int	main(int argc, char *argv[])
{
	t_data	data;

	data.a = NULL;
	data.b = NULL;
	data.array = NULL;
	data.free_array_flag = 0;
	data.size_a = 0;
	if (argc == 1)
		return (0);
	if (argc == 2)
	{
		data.array = ft_split(argv[1], ' ', &data.size_a);
		data.free_array_flag = 1;
	}
	else
	{
		data.size_a = argc - 1;
		data.array = argv + 1;
	}
	if (data.size_a == 0)
		exit_error(&data, 2);
	initialise_stacks(&data);
	checker(&data);
	free_memory(&data);
	return (0);
}

void	initialise_stacks(t_data *data)
{
	int		i;
	long	aux;

	i = 0;
	data -> a = malloc(sizeof(int) * data -> size_a);
	data -> b = malloc(sizeof(int) * data -> size_a);
	data -> size_b = 0;
	while (i < data->size_a)
	{
		aux = ft_atol(data->array[i]);
		if (aux == 2147483648)
			exit_error(data, 2);
		check_range(aux, data);
		data->a[i] = (int)aux;
		data->b[i] = 0;
		i++;
	}
	repeated(data);
}

void	free_memory(t_data *data)
{
	int	i;

	if (data->free_array_flag && data->array)
	{
		i = 0;
		while (data->array[i])
			free(data->array[i++]);
		free(data->array);
	}
	if (data->a)
		free(data->a);
	if (data->b)
		free(data->b);
}

void	exit_error(t_data *data, int fd)
{
	free_memory(data);
	ft_putstr_fd("Error\n", fd);
	exit(1);
}
