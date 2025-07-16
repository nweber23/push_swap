/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweber <nweber@student.42Heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 19:06:51 by nweber            #+#    #+#             */
/*   Updated: 2025/07/16 19:54:04 by nweber           ###   ########.fr       */
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

// Operations
void	*sa(t_stack *stack, char c, bool print);
void	*sb(t_stack *stack, char c, bool print);
void	*ss(t_stack *stack_a, t_stack *stack_b, bool print);
void	*pa(t_stack *stack_a, t_stack *stack_b, char c, bool print);
void	*pb(t_stack *stack_a, t_stack *stack_b, char c, bool print);
void	*ra(t_stack *stack, char c, bool print);
void	*rb(t_stack *stack, char c, bool print);
void	*rr(t_stack *stack_a, t_stack *stack_b, bool print);
void	*rra(t_stack *stack, char c, bool print);
void	*rrb(t_stack *stack, char c, bool print);
void	*rrr(t_stack *stack_a, t_stack *stack_b, bool print);

// Utils
int		check_sort(t_stack *stack);
int		get_min_i(t_stack *stack);

// Logic functions
void	sort1(t_stack *stack_a, t_stack *stack_b, int length);
void	sort2(t_stack *stack_a, t_stack *stack_b, int length);
void	small_sort(t_stack *stack, int len);
int		single_rotation(t_stack *stack, int i);

#endif