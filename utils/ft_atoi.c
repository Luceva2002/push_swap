/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luevange <luevange@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:39:09 by luevange          #+#    #+#             */
/*   Updated: 2025/07/11 17:24:29 by luevange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <limits.h>

void	free_atoi(int *val)
{
	free(val);
	write(2, "Error\n", 6);
	exit(1);
}

int	ft_atoi(const char *str, int *val)
{
	int				i;
	long long int	sign;
	long long int	res;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		if ((sign == 1 && res > INT_MAX) || ((sign == -1) && (-res < INT_MIN)))
			free_atoi(val);
		i++;
	}
	return (sign * res);
}
