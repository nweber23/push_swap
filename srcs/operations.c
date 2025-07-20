/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niklas-weber <niklas-weber@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 10:13:07 by nweber            #+#    #+#             */
/*   Updated: 2025/07/20 21:52:03 by niklas-webe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack, char c, bool print)
{
	t_node	*temp;

	if (!stack->head || !stack->head->next)
		return ;
	temp = stack->head;
	stack->head = temp->next;
	temp->next = stack->head->next;
	stack->head->next = temp;
	if (print)
	{
		write(1, "s", 1);
		write(1, &c, 1);
		write(1, "\n", 1);
	}
}

void	push(t_stack *src, t_stack *dest, char c, bool print)
{
	int	value;

	if (!src->head)
		return ;
	value = pop_stack(src);
	push_stack(dest, value, src->head ? src->head->s_index : 0);
	if (print)
	{
		write(1, "p", 1);
		write(1, &c, 1);
		write(1, "\n", 1);
	}
}

void	rotate(t_stack *stack, char c, bool print)
{
	t_node	*temp;
	t_node	*tail;

	if (!stack->head || !stack->head->next)
		return ;
	temp = stack->head;
	stack->head = temp->next;
	tail = stack->head;
	while (tail->next)
		tail = tail->next;
	tail->next = temp;
	temp->next = NULL;
	if (print)
	{
		write(1, "r", 1);
		write(1, &c, 1);
		write(1, "\n", 1);
	}
}

void	reverse_rotate(t_stack *stack, char c, bool print)
{
	t_node	*temp;
	t_node	*prev;

	if (!stack->head || !stack->head->next)
		return ;
	prev = stack->head;
	while (prev->next->next)
		prev = prev->next;
	temp = prev->next;
	prev->next = NULL;
	temp->next = stack->head;
	stack->head = temp;
	if (print)
	{
		write(1, "rr", 1);
		write(1, &c, 1);
		write(1, "\n", 1);
	}
}
