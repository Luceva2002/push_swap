/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luevange <luevange@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 18:57:34 by luevange          #+#    #+#             */
/*   Updated: 2025/07/06 23:15:20 by luevange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_stack
{
	int				*data;
	int				index;
	struct s_stack	*next;
}					t_stack;

t_stack				*create_node(int *data);
void				fill_stack(t_stack **stack, char **values);
void				index_stack(t_stack **stack);
void				free_stack(t_stack **stack);
void				free_all(t_stack **a, t_stack **b);
void				free_values(char **values);
int					ft_atoi(const char *str);
int					ft_isdigit(int i);
size_t				ft_strlcpy(char *dest, const char *src, size_t size);
size_t				ft_strlen(const char *s1);
char				**ft_split(char const *s, char c);
void				ft_putstr_fd(char *s, int fd);
void				push(t_stack **src, t_stack **dest);
void				push_a(t_stack **a, t_stack **b);
void				push_b(t_stack **a, t_stack **b);
void				swap(t_stack **stack);
void				swap_a(t_stack **a);
void				swap_b(t_stack **b);
void				swap_ab(t_stack **a, t_stack **b);
void				rotate(t_stack **stack);
void				rotate_a(t_stack **a);
void				rotate_b(t_stack **b);
void				rotate_ab(t_stack **a, t_stack **b);
void				reverse_rotate(t_stack **stack);
void				reverse_rotate_a(t_stack **a);
void				reverse_rotate_b(t_stack **b);
void				reverse_rotate_ab(t_stack **a, t_stack **b);
void				sort_two(t_stack **a);
void				sort_three(t_stack **a);
void				sort_four(t_stack **a, t_stack **b);
void				sort_five(t_stack **a, t_stack **b);
void				sort_small(t_stack **a, t_stack **b);
int					get_stack_size(t_stack *a);
void				radix_sort(t_stack **a, t_stack **b, int max_bits);
void				radix(t_stack **a, t_stack **b);
int					get_stack_size(t_stack *stack);
int					get_max_bits(t_stack *a);
int					is_sorted(t_stack *a);
int					has_duplicates(t_stack *stack);

#endif