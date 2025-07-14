/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luevange <luevange@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 22:39:54 by luevange          #+#    #+#             */
/*   Updated: 2025/07/10 15:20:12 by luevange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	index_stack(t_stack **stack)
{
	t_stack	*current;
	t_stack	*cmp;
	int		index;

	current = *stack;
	while (current)
	{
		index = 0;
		cmp = *stack;
		
		while (cmp)
		{
			if (cmp->data[0] < current->data[0])
				index++;
			cmp = cmp->next;
		}
		current->index = index;
		current = current->next;
	}
}
