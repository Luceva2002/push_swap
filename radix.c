/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luevange <luevange@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 16:14:41 by luevange          #+#    #+#             */
/*   Updated: 2025/07/07 00:13:43 by luevange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max_bits(t_stack *a)
{
    int	max;
    int	bits;

    max = 0;
    while (a)
    {
        if (a->index > max)
            max = a->index;
        a = a->next;
    }
    bits = 0;
    while ((max >> bits) != 0)
        bits++;
    return (bits);
}

int	get_stack_size(t_stack *a)
{
    int		size = 0;
    while (a)
    {
        size++;
        a = a->next;
    }
    return (size);
}

void	radix_sort(t_stack **a, t_stack **b, int max_bits)
{
    int	i;
    int	j;
    int	size;

    i = 0;
    size = get_stack_size(*a);
    while (i < max_bits)
    {
        j = 0;
        while (j < size)
        {
            if (((*a)->index >> i) & 1)
                rotate_a(a);
            else
                push_b(a, b);
            j++;
        }
        while (*b)
            push_a(a, b);
        i++;
    }
}

void	radix(t_stack **a, t_stack **b)
{
    int	max_bits;

    if (!a || !*a)
        return ;
    max_bits = get_max_bits(*a);
    radix_sort(a, b, max_bits);
}