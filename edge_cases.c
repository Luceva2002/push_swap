/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edge_cases.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luevange <luevange@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 19:15:13 by luevange          #+#    #+#             */
/*   Updated: 2025/07/07 16:51:48 by luevange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	has_duplicates(t_stack *stack)
{
	t_stack	*cur;
	t_stack	*cmp;

	cur = stack;
	while (cur)
	{
		cmp = cur->next;
		while (cmp)
		{
			if (*(cur->data) == *(cmp->data))
				return (1);
			cmp = cmp->next;
		}
		cur = cur->next;
	}
	return (0);
}

int	is_sorted(t_stack *a)
{
	if (!a)
		return (1);
	while (a->next)
	{
		if (*(a->data) > *(a->next->data))
			return (0);
		a = a->next;
	}
	return (1);
}
