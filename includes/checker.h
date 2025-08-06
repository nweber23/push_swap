/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweber <nweber@student.42Heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 09:24:23 by nweber            #+#    #+#             */
/*   Updated: 2025/08/06 11:31:01 by nweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdint.h>

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

// Utils
void	error_exit(char *message);
void	free_stack(t_stack *stack);
void	push_stack(t_stack *stack, int value, int s_index);
int		pop_stack(t_stack *stack);
int		check_sort(t_stack *stack);
int		ft_fgets(char **line);

// Operations
void	swap(t_stack *stack);
void	push(t_stack *src, t_stack *dest);
void	rotate(t_stack *stack);
void	reverse_rotate(t_stack *stack);
void	ss(t_stack *stack_a, t_stack *stack_b);
void	rr(t_stack *stack_a, t_stack *stack_b);
void	rrr(t_stack *stack_a, t_stack *stack_b);

// Parsing
int		get_numbers(int argc, char **argv);
void	check_numbers(char **str, int *nums);
int		is_duplicate(int *nums, int len);
int		*parse_args(int argc, char **argv, int count);

#endif