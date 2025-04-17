/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 14:05:57 by fernando          #+#    #+#             */
/*   Updated: 2025/04/06 14:05:58 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	rra(int *a, int size_a)
{
	int	i;
	int	last;

	if (size_a < 2)
		return ;
	last = a[size_a - 1];
	i = size_a - 1;
	while (i > 0)
	{
		a[i] = a[i - 1];
		i--;
	}
	a[0] = last;
}

void	rrb(int *b, int size_b)
{
	int	i;
	int	last;

	if (size_b < 2)
		return ;
	last = b[size_b - 1];
	i = size_b - 1;
	while (i > 0)
	{
		b[i] = b[i - 1];
		i--;
	}
	b[0] = last;
}

void	rrr(int *a, int size_a, int *b, int size_b)
{
	rra(a, size_a);
	rrb(b, size_b);
}
