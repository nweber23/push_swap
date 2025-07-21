/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweber <nweber@student.42Heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 10:13:07 by nweber            #+#    #+#             */
/*   Updated: 2025/07/21 12:35:02 by nweber           ###   ########.fr       */
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

void	push(t_stack *dest, t_stack *src, char c, bool print)
{
	int	value;
	int	s_index;

	if (!src->head)
		return ;
	value = src->head->value;
	s_index = src->head->s_index;
	push_stack(dest, value, s_index);
	pop_stack(src);
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
	t_node	*current;
	t_node	*temp;

	if (!stack->head || !stack->head->next || !stack)
		return ;
	current = stack->head;
	while (current->next->next != NULL)
		current = current->next;
	temp = current->next;
	current->next = NULL;
	temp->next = stack->head;
	stack->head = temp;
	if (print)
	{
		write(1, "rr", 2);
		write(1, &c, 1);
		write(1, "\n", 1);
	}
}
