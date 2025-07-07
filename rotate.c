/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luevange <luevange@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 15:50:01 by luevange          #+#    #+#             */
/*   Updated: 2025/07/02 15:28:14 by luevange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	temp = *stack;
	last = *stack;
	while (last->next)
		last = last->next;
	*stack = (*stack)->next;
	temp->next = NULL;
	last->next = temp;
}

void	rotate_a(t_stack **a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

void	rotate_b(t_stack **b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

void	rotate_ab(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}
