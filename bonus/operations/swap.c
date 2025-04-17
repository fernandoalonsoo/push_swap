/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 14:12:34 by fernando          #+#    #+#             */
/*   Updated: 2025/04/06 14:12:35 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	sa(int *a, int size_a)
{
	int	temp;

	if (size_a < 2)
		return ;
	temp = a[0];
	a[0] = a[1];
	a[1] = temp;
}

void	sb(int *b, int size_b)
{
	int	temp;

	if (size_b < 2)
		return ;
	temp = b[0];
	b[0] = b[1];
	b[1] = temp;
}

void	ss(int *a, int size_a, int *b, int size_b)
{
	sa(a, size_a);
	sb(b, size_b);
}
