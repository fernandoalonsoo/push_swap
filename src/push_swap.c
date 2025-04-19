/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 13:59:11 by fernando          #+#    #+#             */
/*   Updated: 2025/04/06 13:59:12 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "./utils/utils.h"

void	initialise_stacks(t_stacks *st, t_aux *aux);
void	initialise_values(t_node *new_node, long val, t_node *prev_node);

/*void	print_stack(t_node *stack)
{
	t_node	*current;

	current = stack;
	while (current)
	{
		printf("%d ", current->n);
		current = current->next;
	}
	printf("\n");
}*/

int	main(int argc, char *argv[])
{
	t_aux		aux;
	t_stacks	st;

	if (argc == 1)
		return (0);
	if (argc == 2)
	{
		aux.array = ft_split(argv[1], ' ', &aux.n);
		aux.free_array_flag = 1;
	}
	else
	{
		aux.n = argc - 1;
		aux.array = argv + 1;
		aux.free_array_flag = 0;
	}
	initialise_stacks(&st, &aux);
	if (aux.n == 0)
		ft_error_exit(&st, &aux, "Error\n", 2);
	repeated(st.a, &st, &aux);
	if (!ordered(st.a))
		turk_algorithm(&st, aux.n);
	free_memory(&st, &aux);
	return (0);
}

void	initialise_stacks(t_stacks *st, t_aux *aux)
{
	int		i;
	long	val;
	t_node	*new_node;
	t_node	*prev_node;

	st->a = NULL;
	st->b = NULL;
	prev_node = NULL;
	i = 0;
	while (i < aux->n)
	{
		val = ft_atol(aux->array[i]);
		if (val == 2147483648)
			ft_error_exit(st, aux, "Error\n", 2);
		check_range(val, st, aux);
		new_node = malloc(sizeof(t_node));
		initialise_values(new_node, val, prev_node);
		if (!st->a)
			st->a = new_node;
		else
			prev_node->next = new_node;
		prev_node = new_node;
		i++;
	}
}

void	initialise_values(t_node *new_node, long val, t_node *prev_node)
{
	new_node->n = (int)val;
	new_node->index = 0;
	new_node->score = 0;
	new_node->top_median = 0;
	new_node->cheapest = 0;
	new_node->target = NULL;
	new_node->next = NULL;
	new_node->prev = prev_node;
}

void	free_memory(t_stacks *st, t_aux *aux)
{
	t_node	*tmp;
	int		i;

	if (aux->free_array_flag && aux->array)
	{
		i = 0;
		while (aux->array[i])
		{
			free(aux->array[i]);
			i++;
		}
		free(aux->array);
	}
	while (st->a)
	{
		tmp = st->a;
		st->a = st->a->next;
		free(tmp);
	}
	while (st->b)
	{
		tmp = st->b;
		st->b = st->b->next;
		free(tmp);
	}
}

void	ft_error_exit(t_stacks *st, t_aux *aux, char *msg, int fd)
{
	free_memory(st, aux);
	if (fd == 1)
		ft_print_string(msg);
	else
		ft_putstr_fd(msg, fd);
	exit(1);
}
