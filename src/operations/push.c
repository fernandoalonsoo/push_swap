/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 14:04:57 by fernando          #+#    #+#             */
/*   Updated: 2025/04/06 14:04:58 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	push_a(t_stacks *st)
{
	t_node	*temp;

	if (!st->b)
		return ;
	temp = st->b;
	st->b = st->b->next;
	if (st->b)
		st->b->prev = NULL;
	temp->next = st->a;
	if (st->a)
		st->a->prev = temp;
	st->a = temp;
	ft_print_string("pa\n");
}

void	push_b(t_stacks *st)
{
	t_node	*temp;

	if (!st->a)
		return ;
	temp = st->a;
	st->a = st->a->next;
	if (st->a)
		st->a->prev = NULL;
	temp->next = st->b;
	if (st->b)
		st->b->prev = temp;
	st->b = temp;
	ft_print_string("pb\n");
}
