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

#include "../../push_swap.h"

void	rotate_a(t_stacks *st)
{
	t_node	*first;
	t_node	*last;

	first = st->a;
	last = st->a;
	if (!st->a || !st->a->next)
		return ;
	while (last->next)
		last = last->next;
	st->a = first->next;
	st->a->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
	ft_print_string("ra\n");
}

void	rotate_b(t_stacks *st)
{
	t_node	*first;
	t_node	*last;

	first = st->b;
	last = st->b;
	if (!st->b || !st->b->next)
		return ;
	while (last->next)
		last = last->next;
	st->b = first->next;
	st->b->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
	ft_print_string("rb\n");
}

void	rr(t_stacks *st)
{
	rotate_a(st);
	rotate_b(st);
	ft_print_string("rr\n");
}
