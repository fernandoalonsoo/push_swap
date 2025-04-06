/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_finder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 13:54:43 by fernando          #+#    #+#             */
/*   Updated: 2025/04/06 13:54:46 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	set_target_b(t_node *a, t_node *b);
t_node		*find_min(t_node *st);

void	get_nodes_b(t_stacks *st)
{
	get_index(st->a, st->size_a);
	get_index(st->b, st->size_b);
	set_target_b(st->a, st->b);
}

static void	set_target_b(t_node *a, t_node *b)
{
	t_node	*current_a;
	t_node	*target;
	long	best_match;

	while (b)
	{
		best_match = 2147483648;
		current_a = a;
		while (current_a)
		{
			if (current_a->n > b->n && current_a->n < best_match)
			{
				best_match = current_a->n;
				target = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match == 2147483648)
			b->target = find_min(a);
		else
			b->target = target;
		b = b->next;
	}
}

t_node	*find_min(t_node *st)
{
	long	min;
	t_node	*min_node;

	if (!st)
		return (NULL);
	min = 2147483648;
	while (st)
	{
		if (st-> n < min)
		{
			min = st-> n;
			min_node = st;
		}
		st = st->next;
	}
	return (min_node);
}

t_node	*find_max(t_node *stack)
{
	long	max;
	t_node	*max_node;

	if (!stack)
		return (NULL);
	max = -2147483649;
	while (stack)
	{
		if (stack->n > max)
		{
			max = stack->n;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}
