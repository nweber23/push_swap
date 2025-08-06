/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweber <nweber@student.42Heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 10:36:09 by nweber            #+#    #+#             */
/*   Updated: 2025/08/06 10:56:48 by nweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	execution(t_stack *stack_a, t_stack *stack_b, char *command)
{
	if (!ft_strcmp(command, "ra\n"))
		rotate(stack_a);
	else if (!ft_strcmp(command, "rb\n"))
		rotate(stack_b);
	else if (!ft_strcmp(command, "rr\n"))
		rr(stack_a, stack_b);
	else if (!ft_strcmp(command, "rra\n"))
		reverse_rotate(stack_a);
	else if (!ft_strcmp(command, "rrb\n"))
		reverse_rotate(stack_b);
	else if (!ft_strcmp(command, "rrr\n"))
		rrr(stack_a, stack_b);
	else if (!ft_strcmp(command, "pa\n"))
		push(stack_a, stack_b);
	else if (!ft_strcmp(command, "pb\n"))
		push(stack_b, stack_a);
	else if (!ft_strcmp(command, "sa\n"))
		swap(stack_a);
	else if (!ft_strcmp(command, "sb\n"))
		swap(stack_b);
	else if (!ft_strchr(command, "ss\n"))
		ss(stack_a, stack_b);
	else
		return (0);
	return (1);
}
