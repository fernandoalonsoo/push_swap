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

void	initialise_stacks(int n, char **array, int *a, int *b);
void	free_memory(int **a, int **b, char **array, int free_array_flag);

int	main(int argc, char *argv[])
{
	int		*a;
	int		*b;
	char	**array;
	int		free_array_flag;
	int		n;

	if (argc == 1)
		exit(0);
	if (argc == 2)
	{
		array = ft_split(argv[1], ' ', &n);
		free_array_flag = 1;
	}
	else
	{
		n = argc - 1;
		array = argv + 1;
		free_array_flag = 0;
	}
	a = malloc(sizeof(int) * n);
	b = malloc(sizeof(int) * n);
	initialise_stacks(n, array, a, b);
	checker(a, b, n);
	free_memory(&a, &b, array, free_array_flag);
	return (0);
}

void	initialise_stacks(int n, char **array, int *a, int *b)
{
	int		i;
	long	aux;

	i = 0;
	while (i < n)
	{
		aux = ft_atol(array[i]);
		check_range(aux);
		a[i] = (int)aux;
		b[i] = 0;
		i++;
	}
	repeated(a, n);
}

void	free_memory(int **a, int **b, char **array, int free_array_flag)
{
	int	i;

	if (free_array_flag && array)
	{
		i = 0;
		while (array[i])
		{
			free(array[i]);
			i++;
		}
		free(array);
	}
	if (a && *a)
	{
		free(*a);
		*a = NULL;
	}
	if (b && *b)
	{
		free(*b);
		*b = NULL;
	}
}
