/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 13:47:52 by fernando          #+#    #+#             */
/*   Updated: 2025/04/06 13:47:59 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void		sort_3(t_stacks *st);
static void		sort_4_or_5(t_stacks *st);
static t_node	*find_min_node(t_stacks *st);
static void		move_min_to_top(t_stacks *st, t_node *min_node);

void	optimize(t_stacks *st)
{
	if (st->size_a == 2)
	{
		if (st->a->n > st->a->next->n)
			swap_a(st);
	}
	else if (st->size_a == 3)
		sort_3(st);
	else if (st->size_a <= 5)
		sort_4_or_5(st);
}

/* Ordenar 3 elementos */
static void	sort_3(t_stacks *st)
{
	t_node	*first;
	t_node	*second;
	t_node	*third;

	first = st->a;
	second = first->next;
	third = second->next;
	if (first->n > second->n && first->n > third->n)
	{
		rotate_a(st);
		if (st->a->n > st->a->next->n)
			swap_a(st);
	}
	else if (second->n > first->n && second->n > third->n)
	{
		reverse_rotate_a(st);
		if (st->a->n > st->a->next->n)
			swap_a(st);
	}
	else if (first->n > second->n)
		swap_a(st);
}

/* Encontrar el nodo con el menor valor */
static t_node	*find_min_node(t_stacks *st)
{
	t_node	*current;
	t_node	*min_node;

	current = st->a;
	min_node = current;
	while (current)
	{
		if (current->n < min_node->n)
			min_node = current;
		current = current->next;
	}
	return (min_node);
}

/* Mover el nodo mínimo a la cima de A */
static void	move_min_to_top(t_stacks *st, t_node *min_node)
{
	int		pos;
	int		half_size;
	t_node	*current;

	pos = 0;
	half_size = st->size_a / 2;
	current = st->a;
	while (current && current != min_node)
	{
		current = current->next;
		pos++;
	}
	if (pos <= half_size)
	{
		while (st->a != min_node)
			rotate_a(st);
	}
	else
	{
		while (st->a != min_node)
			reverse_rotate_a(st);
	}
}

/* Ordenar 4 o 5 elementos */
static void	sort_4_or_5(t_stacks *st)
{
	t_node	*min_node;

	while (st->size_a > 3)
	{
		min_node = find_min_node(st);
		move_min_to_top(st, min_node);
		push_b(st);
	}
	sort_3(st);
	while (st->size_b > 0)
		push_a(st);
}
