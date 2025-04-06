/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score_calculator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 13:56:53 by fernando          #+#    #+#             */
/*   Updated: 2025/04/06 13:56:54 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void		get_index(t_node *st);
static void	set_target_a(t_node *a, t_node *b);
static void	score_calculator(t_stacks *st);
static void	set_cheapest(t_node *st);

void	calculate_scores(t_stacks *st)
{
	get_index(st -> a);
	get_index(st -> b);
	set_target_a(st -> a, st -> b);
	score_calculator(st);
	set_cheapest(st->a);
}

void	get_index(t_node *st)
{
	int	i;
	int	median;

	i = 0;
	if (!st)
		return ;
	median = stack_len(st) / 2;
	while (st)
	{
		st->index = i;
		if (i <= median)
			st->top_median = 1;
		else
			st->top_median = 0;
		st = st->next;
		i++;
	}
}

static void	set_target_a(t_node *a, t_node *b)
{
	t_node	*ptr_b;
	t_node	*target_node;
	long	best_match;

	while (a)
	{
		best_match = -2147483649;
		ptr_b = b;
		while (ptr_b)
		{
			if (ptr_b->n < a->n && ptr_b->n > best_match)
			{
				best_match = ptr_b->n;
				target_node = ptr_b;
			}
			ptr_b = ptr_b->next;
		}
		if (best_match == -2147483649)
			a->target = find_max(b);
		else
			a->target = target_node;
		a = a->next;
	}
}

static void	score_calculator(t_stacks *st)
{
	int		len_a;
	int		len_b;
	t_node	*ptr;

	len_a = stack_len(st->a);
	len_b = stack_len(st->b);
	ptr = st->a;
	while (ptr)
	{
		ptr->score = ptr->index;
		if (!ptr->top_median)
			ptr->score = len_a - ptr->index;
		if (ptr->target->top_median)
			ptr->score += ptr->target->index;
		else
			ptr->score += len_b - ptr->target->index;
		ptr = ptr->next;
	}
}

void	set_cheapest(t_node *st)
{
	long	cheapest_value;
	t_node	*cheapest_node;

	if (!st)
		return ;
	cheapest_value = 2147483648;
	while (st)
	{
		if (st-> score < cheapest_value)
		{
			cheapest_value = st-> score;
			cheapest_node = st;
		}
		st = st->next;
	}
	cheapest_node->cheapest = 1;
}
