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

void	initialise_stacks(t_stacks *st, int n, char **array);
void	initialise_values(t_node *new_node, long aux, t_node *prev_node);
void	free_memory(t_stacks *st, char **array, int free_array_flag);

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
	char		**array;
	t_stacks	st;
	int			n;
	int			free_array_flag;

	if (argc == 1)
		exit(0);
	if (argc == 2)
	{
		array = ft_split(argv[1], ' ', &n);
		free_array_flag = 1;
	}
	else
	{
		n = argc - 1;
		array = argv + 1;
		free_array_flag = 0;
	}
	initialise_stacks(&st, n, array);
	repeated(st.a);
	if (!ordered(st.a))
		turk_algorithm(&st, stack_len(st.a));
	free_memory(&st, array, free_array_flag);
	return (0);
}

void	initialise_stacks(t_stacks *st, int n, char **array)
{
	int		i;
	long	aux;
	t_node	*new_node;
	t_node	*prev_node;

	st->a = NULL;
	st->b = NULL;
	prev_node = NULL;
	i = 0;
	while (i < n)
	{
		aux = ft_atol(array[i]);
		i++;
		check_range(aux);
		new_node = malloc(sizeof(t_node));
		initialise_values(new_node, aux, prev_node);
		if (!st->a)
			st->a = new_node;
		else
			prev_node->next = new_node;
		prev_node = new_node;
	}
}

void	initialise_values(t_node *new_node, long aux, t_node *prev_node)
{
	new_node->n = (int)aux;
	new_node->index = 0;
	new_node->score = 0;
	new_node->top_median = 0;
	new_node->cheapest = 0;
	new_node->target = NULL;
	new_node->next = NULL;
	new_node->prev = prev_node;
}

void	free_memory(t_stacks *st, char **array, int free_array_flag)
{
	int		i;
	t_node	*temp;

	if (free_array_flag && array)
	{
		i = 0;
		while (array[i])
		{
			free(array[i]);
			i++;
		}
		free(array);
	}
	while (st->a)
	{
		temp = st->a;
		st->a = st->a->next;
		free(temp);
	}
	while (st->b)
	{
		temp = st->b;
		st->b = st->b->next;
		free(temp);
	}
}
