/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweber <nweber@student.42Heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 21:03:34 by nweber            #+#    #+#             */
/*   Updated: 2025/07/15 13:37:28 by nweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	*ra(t_stack *stack, char c, bool print)
{
	if (stack->head && stack->head->next)
	{
		t_node *first = stack->head;
		t_node *last = stack->head;

		while (last->next)
			last = last->next;
		stack->head = first->next;
		first->next = NULL;
		last->next = first;

		if (print)
			ft_printf("r%c\n", c);
	}
	return (NULL);
}

void	*rb(t_stack *stack, char c, bool print)
{
	if (stack->head && stack->head->next)
	{
		t_node *first = stack->head;
		t_node *last = stack->head;

		while (last->next)
			last = last->next;
		stack->head = first->next;
		first->next = NULL;
		last->next = first;

		if (print)
			ft_printf("r%c\n", c);
	}
	return (NULL);
}

void	*rr(t_stack *stack_a, t_stack *stack_b, bool print)
{
	ra(stack_a, 'a', false);
	rb(stack_b, 'b', false);
	if (print)
		ft_printf("rr\n");
	return (NULL);
}
