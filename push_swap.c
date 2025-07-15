/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luevange <luevange@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 14:29:50 by luevange          #+#    #+#             */
/*   Updated: 2025/07/15 18:01:31 by luevange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	init_and_parse(int argc, char **argv, t_stack **a, char ***values)
{
	int	k;

	k = 0;
	if (argc < 2)
		return (1);
	if (argc == 2)
	{
		*values = ft_split(argv[1], ' ', k);
		*a = NULL;
		if (fill_stack(a, *values) != 0)
			return (free_values(*values), 1);
		if (!*a)
			return (free_values(*values), 1);
		free_values(*values);
		index_stack(a);
		k++;
		return (0);
	}
	*values = argv + 1;
	*a = NULL;
	if (fill_stack(a, *values))
		return (printf("Error fill stack 2\n"), (1));
	if (!*a)
		return (1);
	return (index_stack(a), 0);
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
	if (init_and_parse(argc, argv, &a, &values) == 1)
	{
		printf("exited init_parse\n");
		return (1);
	}
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

/* void	print_stack(t_stack *stack)
{
	int		i;
	t_stack	*a;
	t_stack	*b;
	char	**values;

	i = 0;
	while (stack)
	{
		if (stack->data)
			printf("Node %d: data = %d, index = %d\n", i, *(stack->data),
				stack->index);
		else
			printf("Node %d: data = (null), index = %d\n", i, stack->index);
		stack = stack->next;
		i++;
	}
} */

/* int	fill_stack(t_stack **stack, char **values)
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
		{
			printf("Error malloc\n");
			return (free(val), 1);
		}
		if (ft_isdigit(values[i]) == 0)
		{
			ft_putstr_fd("Error not number\n", 2);
			free_stack(stack);
			return (free(val), 1);
		}
		*val = ft_atoi(values[i], val);
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
	return (0);
} */