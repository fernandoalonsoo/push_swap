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

#include "../../push_swap.h"

void	swap_a(t_stacks *st)
{
	t_node	*first;
	t_node	*second;

	first = st->a;
	second = first->next;
	if (!st->a || !st->a->next)
		return ;
	first->next = second->next;
	if (first->next)
		first->next->prev = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	st->a = second;
	ft_print_string("sa\n");
}

void	swap_b(t_stacks *st)
{
	t_node	*first;
	t_node	*second;

	first = st->a;
	second = first->next;
	if (!st->b || !st->b->next)
		return ;
	first->next = second->next;
	if (first->next)
		first->next->prev = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	st->b = second;
	ft_print_string("sb\n");
}

void	ss(t_stacks *st)
{
	if (stack_len(st->a) > 1)
		swap_a(st);
	if (stack_len(st->b) > 1)
		swap_b(st);
	ft_print_string("ss\n");
}
