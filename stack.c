/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luevange <luevange@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 17:59:12 by luevange          #+#    #+#             */
/*   Updated: 2025/07/16 21:30:25 by luevange         ###   ########.fr       */
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

int	process_value(t_stack **stack, char *value)
{
	int		*val;
	t_stack	*node;
	t_stack	*last;

	val = malloc(sizeof(int));
	if (!val)
		return (ft_putstr_fd("Error\n", 2), 1);
	if (ft_isdigit(value) == 0)
		return (ft_putstr_fd("Error\n", 2),
			free_stack(stack), free(val), 1);
	*val = ft_atoi(value, val);
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
	return (0);
}

int	fill_stack(t_stack **stack, char **values)
{
	int		i;

	i = 0;
	while (values[i])
	{
		if (process_value(stack, values[i]) != 0)
			return (1);
		i++;
	}
	return (0);
}

int		get_min_pos(t_stack *a, int min_index)
{
	int pos = 0;

	while (a)
	{
		if (a->index == min_index)
			break ;
		pos++;
		a = a->next;
	}
	return pos;
}

void	move_min_top(t_stack **a, int min_index)
{
	int pos = get_min_pos(*a, min_index);
	int size = get_stack_size(*a);

	if (pos <= size / 2)
		while (pos--)
			rotate_a(a);
	else
		while (pos++ < size)
			reverse_rotate_a(a);
}
