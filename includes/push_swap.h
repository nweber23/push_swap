/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niklas-weber <niklas-weber@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 19:06:51 by nweber            #+#    #+#             */
/*   Updated: 2025/07/20 18:15:55 by niklas-webe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdbool.h>
# include <limits.h>
# include <stdint.h>
# include <stdlib.h>

typedef struct s_node
{
	int				value;
	int				s_index;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node			*head;
	int				size;
}	t_stack;

// Main

int	main(int argc, char **argv);

// Operations
void	swap(t_stack *stack, char c, bool print);
void	push(t_stack *src, t_stack *dest, char c, bool print);
void	rotate(t_stack *stack, char c, bool print);
void	reverse_rotate(t_stack *stack, char c, bool print);

// Utils
int		check_sort(t_stack *stack);
int		count_r(t_node *stack, int i);
int		get_min_i(t_stack *stack);
void	push_stack(t_stack *stack, int value, int s_index);
int		pop_stack(t_stack *stack);
void	free_stack(t_stack *stack);

// Logic functions
void	sort1(t_stack *stack_a, t_stack *stack_b, int length);
void	sort2(t_stack *stack_a, t_stack *stack_b, int length);
void	small_sort(t_stack *stack, int len);
int		single_rotation(t_stack *stack, int i);
void	minimal_sort(t_stack *stack_a, t_stack *stack_b, int len);
void	sort(t_stack *stack_a, t_stack *stack_b, int *numbers, int length);
void	insertion_sort(int *nums, int n);

// Error handling
void	error_exit(char *message);

// Parsing
int		*parse_args(int argc, char **argv, int len);
int		get_numbers(int argc, char **argv);
int		is_duplicate(int *numbers, int len);

#endif