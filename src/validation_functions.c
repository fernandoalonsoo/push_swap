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

#include "../push_swap.h"

void	repeated(t_node *a, t_stacks *st, t_aux *aux)
{
	t_node	*current;
	t_node	*checker;

	current = a;
	while (current)
	{
		checker = current->next;
		while (checker)
		{
			if (current->n == checker->n)
				ft_error_exit(st, aux, "Error\n", 2);
			checker = checker->next;
		}
		current = current->next;
	}
}

void	check_range(long a, t_stacks *st, t_aux *aux)
{
	if ((a < -2147483648) || (2147483647 < a))
		ft_error_exit(st, aux, "Error\n", 2);
}

int	ordered(t_node *a)
{
	t_node	*p;

	p = a;
	while (p && p->next)
	{
		if (p->n > p->next->n)
			return (0);
		p = p->next;
	}
	return (1);
}

int	stack_len(t_node *stack)
{
	int	count;

	if (!stack)
		return (0);
	count = 0;
	while (stack)
	{
		stack = stack->next;
		count++;
	}
	return (count);
}
