/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luevange <luevange@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 16:59:40 by luevange          #+#    #+#             */
/*   Updated: 2025/07/11 17:34:27 by luevange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	while (*stack)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		free(tmp->data);
		free(tmp);
	}
}

void	free_all(t_stack **a, t_stack **b)
{
	
	free_stack(a);
	free_stack(b);
}

void	free_values(char **values)
{
	int	i;

	if (!values)
		return ;
	i = 0;
	while (values[i])
	{
		free(values[i]);
		i++;
	}
	free(values);
}
