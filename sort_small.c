/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luevange <luevange@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 17:00:17 by luevange          #+#    #+#             */
/*   Updated: 2025/07/07 13:40:36 by luevange         ###   ########.fr       */
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
	if ((*a)->data > (*a)->next->data && (*a)->next->data < (*a)->next->next->data && (*a)->data < (*a)->next->next->data)
	{
		write(1, "cojone", 6);
		swap_a(a);
	}
	else if ((*a)->data > (*a)->next->data && (*a)->next->data > (*a)->next->next->data)
	{
		swap_a(a);
		reverse_rotate_a(a);
	}
	else if ((*a)->data > (*a)->next->data && (*a)->next->data < (*a)->next->next->data && (*a)->data > (*a)->next->next->data)
		rotate_a(a);
	else if ((*a)->data < (*a)->next->data && (*a)->next->data > (*a)->next->next->data && (*a)->data < (*a)->next->next->data)
	{
		swap_a(a);
		rotate_a(a);
	}
	else if ((*a)->data < (*a)->next->data && (*a)->next->data > (*a)->next->next->data && (*a)->data > (*a)->next->next->data)
		reverse_rotate_a(a);
}

void	sort_four(t_stack **a, t_stack **b)
{
	push_b(a, b);
	if ((*a)->data[0] > (*a)->next->data[0])
		swap_a(a);
	sort_three(a);
	push_a(a, b);
}

void	sort_five(t_stack **a, t_stack **b)
{
	push_b(a, b);
	if ((*a)->data[0] > (*a)->next->data[0])
		swap_a(a);
	sort_four(a, b);
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
