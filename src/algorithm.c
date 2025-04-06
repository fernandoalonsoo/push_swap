/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 13:37:50 by fernando          #+#    #+#             */
/*   Updated: 2025/04/06 13:37:51 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static t_node	*get_cheapest(t_node *st);
static void		push_to(t_stacks *st, char stack_name);
static void		last_order(t_stacks *st);

void	turk_algorithm(t_stacks *st)
{
	if (st->size_a <= 5)
	{
		optimize(st);
		return ;
	}
	if (st -> size_a > 3 && !ordered(st ->a))
		push_b(st);
	if (st -> size_a > 3 && !ordered(st ->a))
		push_b(st);
	while (st -> size_a > 3 && !ordered(st ->a))
	{
		calculate_scores(st);
		push_to(st, 'b');
	}
	optimize(st);
	while (st -> size_b != 0)
	{
		get_nodes_b(st);
		push_to(st, 'a');
	}
	get_index(st->a, st->size_a);
	last_order(st);
}

static void	push_to(t_stacks *st, char stack_name)
{
	t_node	*cheapest_node;

	if (stack_name == 'b')
	{
		cheapest_node = get_cheapest(st->a);
		if (cheapest_node->top_median && cheapest_node->target->top_median)
			rotate_both(st, cheapest_node);
		else if (!cheapest_node->top_median
			&& !cheapest_node->target->top_median)
			rev_rotate_both(st, cheapest_node);
		prep_for_push(st, cheapest_node, 'a');
		prep_for_push(st, cheapest_node->target, 'b');
		push_b(st);
	}
	else if (stack_name == 'a')
	{
		prep_for_push(st, st->b->target, 'a');
		push_a(st);
	}
}

static t_node	*get_cheapest(t_node *st)
{
	if (!st)
		return (NULL);
	while (st)
	{
		if (st->cheapest)
			return (st);
		st = st->next;
	}
	return (NULL);
}

static void	last_order(t_stacks *st)
{
	t_node	*min;

	while (st->a && (st->a->n != find_min(st->a)->n))
	{
		min = find_min(st->a);
		if (min->top_median)
			rotate_a(st);
		else
			reverse_rotate_a(st);
	}
}
