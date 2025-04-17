/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 14:08:30 by fernando          #+#    #+#             */
/*   Updated: 2025/04/06 14:08:31 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	ra(int *a, int size_a)
{
	int	i;
	int	first;

	if (size_a < 2)
		return ;
	first = a[0];
	i = 0;
	while (i < size_a - 1)
	{
		a[i] = a[i + 1];
		i++;
	}
	a[size_a - 1] = first;
}

void	rb(int *b, int size_b)
{
	int	i;
	int	first;

	if (size_b < 2)
		return ;
	first = b[0];
	i = 0;
	while (i < size_b - 1)
	{
		b[i] = b[i + 1];
		i++;
	}
	b[size_b - 1] = first;
}

void	rr(int *a, int size_a, int *b, int size_b)
{
	ra(a, size_a);
	rb(b, size_b);
}
