/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luevange <luevange@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 17:00:17 by luevange          #+#    #+#             */
/*   Updated: 2025/07/07 14:27:25 by luevange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack **a)
{
	if ((*a)->data[0] > (*a)->next->data[0])
		swap_a(a);
}

void	sort_three(t_stack **a)
{
	if ((*a)->data[0] > (*a)->next->data[0]
		&& (*a)->next->data[0] < (*a)->next->next->data[0]
		&& (*a)->data[0] < (*a)->next->next->data[0])
		swap_a(a);
	else if ((*a)->data[0] > (*a)->next->data[0]
		&& (*a)->next->data[0] > (*a)->next->next->data[0])
	{
		swap_a(a);
		reverse_rotate_a(a);
	}
	else if ((*a)->data[0] > (*a)->next->data[0]
		&& (*a)->next->data[0] < (*a)->next->next->data[0]
		&& (*a)->data[0] > (*a)->next->next->data[0])
		rotate_a(a);
	else if ((*a)->data[0] < (*a)->next->data[0]
		&& (*a)->next->data[0] > (*a)->next->next->data[0]
		&& (*a)->data[0] < (*a)->next->next->data[0])
	{
		swap_a(a);
		rotate_a(a);
	}
	else if ((*a)->data[0] < (*a)->next->data[0]
		&& (*a)->next->data[0] > (*a)->next->next->data[0]
		&& (*a)->data[0] > (*a)->next->next->data[0])
		reverse_rotate_a(a);
}

void	sort_four(t_stack **a, t_stack **b)
{
	while ((*a)->index != 0)
		rotate_a(a);
	push_b(a, b);
	sort_three(a);
	push_a(a, b);
}

void	sort_five(t_stack **a, t_stack **b)
{
	int	pushed;

	pushed = 0;
	while (pushed < 2)
	{
		if ((*a)->index == 0 || (*a)->index == 1)
		{
			push_b(a, b);
			pushed++;
		}
		else
			rotate_a(a);
	}
	sort_three(a);
	if ((*b)->index == (*b)->next->index)
		swap_b(b);
	push_a(a, b);
	push_a(a, b);
}

void	sort_small(t_stack **a, t_stack **b)
{
	int	size;

	if (!a || !*a)
		return ;
	size = get_stack_size(*a);
	if (size == 2)
		sort_two(a);
	else if (size == 3)
		sort_three(a);
	else if (size == 4)
		sort_four(a, b);
	else if (size == 5)
		sort_five(a, b);
}
