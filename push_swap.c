/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luevange <luevange@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 14:29:50 by luevange          #+#    #+#             */
/*   Updated: 2025/07/07 12:11:30 by luevange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_node(int *data)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->data = data;
	new_node->index = -1;
	new_node->next = NULL;
	return (new_node);
}

void	fill_stack(t_stack **stack, char **values)
{
	int		i;
	int		*val;
	t_stack	*node;
	t_stack	*last;

	i = 0;
	while (values[i])
	{
		val = malloc(sizeof(int));
		if (!val)
			return ;
		*val = ft_atoi(values[i]);
		node = create_node(val);
		if (!*stack)
			*stack = node;
		else
		{
			last = *stack;
			while (last->next)
				last = last->next;
			last->next = node;
		}
		i++;
	}
}

static int	init_and_parse(int argc, char **argv, t_stack **a, char ***values)
{
	if (argc < 2)
		return (0);
	*values = argv + 1;
	*a = NULL;
	fill_stack(a, *values);
	if (!*a)
		return (0);
	index_stack(a);
	return (1);
}

static void	run_sort(t_stack **a, t_stack **b)
{
	if (is_sorted(*a))
		return ;
	if (get_stack_size(*a) <= 5)
		sort_small(a, b);
	else
		radix(a, b);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	**values;

	a = NULL;
	b = NULL;
	if (!init_and_parse(argc, argv, &a, &values))
		return (1);
	if (has_duplicates(a))
	{
		ft_putstr_fd("Error\n", 2);
		free_all(&a, &b);
		return (1);
	}
	run_sort(&a, &b);
	free_all(&a, &b);
	return (0);
}
