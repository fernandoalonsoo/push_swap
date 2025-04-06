/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 14:16:43 by fernando          #+#    #+#             */
/*   Updated: 2025/04/06 14:16:44 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "src/utils/utils.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_node
{
	int				n;
	int				index;
	int				score;
	int				top_median;
	int				cheapest;
	struct s_node	*target;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stacks
{
	t_node	*a;
	t_node	*b;
}	t_stacks;

void	print_stack(t_node *stack);

/* Funciones de validación */
void	repeated(t_node *a);
void	check_range(long a);
int		ordered(t_node *a);
int		stack_len(t_node *stack);

/* Algoritmo */
void	optimize(t_stacks *st);
void	turk_algorithm(t_stacks *st, int len_a);
void	calculate_scores(t_stacks *st);

/* Funciones para la gestión de los stacks */
void	initialise_stacks(t_stacks *st, int n, char **array);
void	free_memory(t_stacks *st, char **array, int free_array_flag);
void	get_index(t_node *st);
void	rotate_both(t_stacks *st, t_node *cheapest_node);
void	rev_rotate_both(t_stacks *st, t_node *cheapest_node);
void	prep_for_push(t_stacks *st, t_node *top_node, char stack_name);
void	get_nodes_b(t_stacks *st);
t_node	*find_min(t_node *st);
t_node	*find_max(t_node *stack);
void		sort_3(t_stacks *st);

/* Operaciones de PUSH */
void	push_a(t_stacks *st);
void	push_b(t_stacks *st);

/* Operaciones de SWAP */
void	swap_a(t_stacks *st);
void	swap_b(t_stacks *st);
void	ss(t_stacks *st);
/* Operaciones de ROTATE */
void	rotate_a(t_stacks *st, int print);
void	rotate_b(t_stacks *st, int print);
void	rr(t_stacks *st);

/* Operaciones de REVERSE ROTATE */
void	reverse_rotate_a(t_stacks *st, int print);
void	reverse_rotate_b(t_stacks *st, int print);
void	rrr(t_stacks *st);

#endif
