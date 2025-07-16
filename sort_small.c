/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luevange <luevange@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 17:00:17 by luevange          #+#    #+#             */
/*   Updated: 2025/07/16 21:32:15 by luevange         ###   ########.fr       */
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
	int first = (*a)->index;
	int second = (*a)->next->index;
	int third = (*a)->next->next->index;

	if (first > second && second < third && first < third)
		swap_a(a);
	else if (first > second && second > third)
	{
		swap_a(a);
		reverse_rotate_a(a);
	}
	else if (first > third && second < third)
		rotate_a(a);
	else if (first < second && first > third)
		reverse_rotate_a(a);
	else if (first < third && second > third)
	{
		swap_a(a);
		rotate_a(a);
	}
}

void	sort_four(t_stack **a, t_stack **b)
{
	while ((*a)->index != 0)
		rotate_a(a);
	push_b(a, b);
	sort_three(a);
	push_a(a, b);
}

/* void	sort_five(t_stack **a, t_stack **b)
{
	while ((*a)->index != 0)
		rotate_a(a);
	push_b(a, b);
	while ((*a)->index != 1)
		rotate_a(a);
	push_b(a, b);
	sort_three(a);
	push_a(a, b);
	push_a(a, b);
} */

void	sort_five(t_stack **a, t_stack **b)
{
	move_min_top(a, 0);
	push_b(a, b);
	move_min_top(a, 1);
	push_b(a, b);
	if ((*b)->index < (*b)->next->index)
		swap_b(b);
	sort_three(a);
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
