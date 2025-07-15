/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweber <nweber@student.42Heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 13:22:29 by nweber            #+#    #+#             */
/*   Updated: 2025/07/15 13:38:21 by nweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	*rra(t_stack *stack, char c, bool print)
{
	if (stack->head && stack->head->next)
	{
		t_node *last = stack->head;
		t_node *second_last = NULL;

		while (last->next)
		{
			second_last = last;
			last = last->next;
		}
		last->next = stack->head;
		stack->head = last;
		second_last->next = NULL;

		if (print)
			ft_printf("rr%c\n", c);
	}
	return (NULL);
}

void	*rrb(t_stack *stack, char c, bool print)
{
	if (stack->head && stack->head->next)
	{
		t_node *last = stack->head;
		t_node *second_last = NULL;

		while (last->next)
		{
			second_last = last;
			last = last->next;
		}
		last->next = stack->head;
		stack->head = last;
		second_last->next = NULL;

		if (print)
			ft_printf("rr%c\n", c);
	}
	return (NULL);
}

void	*rrr(t_stack *stack_a, t_stack *stack_b, bool print)
{
	rra(stack_a, 'a', false);
	rrb(stack_b, 'b', false);
	if (print)
		ft_printf("rrr\n");
	return (NULL);
}
