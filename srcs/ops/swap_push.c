/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweber <nweber@student.42Heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 21:04:03 by nweber            #+#    #+#             */
/*   Updated: 2025/07/15 13:24:54 by nweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	*sa(t_stack *stack, char c, bool print)
{
	if (stack->head && stack->head->next)
	{
		t_node *first = stack->head;
		t_node *second = first->next;

		first->next = second->next;
		second->next = first;
		stack->head = second;

		if (print)
			ft_printf("s%c\n", c);
	}
	return (NULL);
}

void	*sb(t_stack *stack, char c, bool print)
{
	if (stack->head && stack->head->next)
	{
		t_node *first = stack->head;
		t_node *second = first->next;

		first->next = second->next;
		second->next = first;
		stack->head = second;

		if (print)
			ft_printf("s%c\n", c);
	}
	return (NULL);
}

void	*ss(t_stack *stack_a, t_stack *stack_b, bool print)
{
	sa(stack_a, 'a', false);
	sb(stack_b, 'b', false);
	if (print)
		ft_printf("ss\n");
	return (NULL);
}

void	*pa(t_stack *stack_a, t_stack *stack_b, char c, bool print)
{
	if (stack_b->head)
	{
		t_node *node_to_move = stack_b->head;
		stack_b->head = node_to_move->next;

		node_to_move->next = stack_a->head;
		stack_a->head = node_to_move;
		stack_a->size++;
		stack_b->size--;

		if (print)
			ft_printf("p%c\n", c);
	}
	return (NULL);
}

void	*pb(t_stack *stack_a, t_stack *stack_b, char c, bool print)
{
	if (stack_a->head)
	{
		t_node *node_to_move = stack_a->head;
		stack_a->head = node_to_move->next;

		node_to_move->next = stack_b->head;
		stack_b->head = node_to_move;
		stack_b->size++;
		stack_a->size--;

		if (print)
			ft_printf("p%c\n", c);
	}
	return (NULL);
}
