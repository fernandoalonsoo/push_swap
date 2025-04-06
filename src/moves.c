/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 13:47:03 by fernando          #+#    #+#             */
/*   Updated: 2025/04/06 13:47:05 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate_both(t_stacks *st, t_node *cheapest_node)
{
	while (st->b != cheapest_node->target && st->a != cheapest_node)
		rr(st);
	get_index(st->a);
	get_index(st->b);
}

void	rev_rotate_both(t_stacks *st, t_node *cheapest_node)
{
	while (st->b != cheapest_node->target && st->a != cheapest_node)
		rrr(st);
	get_index(st->a);
	get_index(st->b);
}

void	prep_for_push(t_stacks *st, t_node *top_node, char stack_name)
{
	if (stack_name == 'a')
	{
		while (st->a != top_node)
		{
			if (top_node->top_median)
				rotate_a(st, 1);
			else
				reverse_rotate_a(st, 1);
		}
	}
	else if (stack_name == 'b')
	{
		while (st->b != top_node)
		{
			if (top_node->top_median)
				rotate_b(st, 1);
			else
				reverse_rotate_b(st, 1);
		}
	}
}
