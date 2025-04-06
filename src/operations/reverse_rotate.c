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

#include "../../push_swap.h"

void	reverse_rotate_a(t_stacks *st)
{
	t_node	*last;

	last = st->a;
	if (!st->a || !st->a->next)
		return ;
	while (last->next)
		last = last->next;
	last->prev->next = NULL;
	last->prev = NULL;
	last->next = st->a;
	st->a->prev = last;
	st->a = last;
	ft_print_string("rra\n");
}

void	reverse_rotate_b(t_stacks *st)
{
	t_node	*last;

	last = st->b;
	if (!st->b || !st->b->next)
		return ;
	while (last->next)
		last = last->next;
	last->prev->next = NULL;
	last->prev = NULL;
	last->next = st->b;
	st->b->prev = last;
	st->b = last;
	ft_print_string("rrb\n");
}

void	rrr(t_stacks *st)
{
	reverse_rotate_a(st);
	reverse_rotate_b(st);
	ft_print_string("rrr\n");
}
