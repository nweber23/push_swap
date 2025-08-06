/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweber <nweber@student.42Heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 10:33:21 by nweber            #+#    #+#             */
/*   Updated: 2025/08/06 10:41:19 by nweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	swap(t_stack *stack)
{
	t_node	*temp;

	if (!stack->head || !stack->head->next)
		return ;
	temp = stack->head;
	stack->head = temp->next;
	temp->next = stack->head->next;
	stack->head->next = temp;
}

void	push(t_stack *dest, t_stack *src)
{
	int	value;
	int	s_index;

	if (!src->head)
		return ;
	value = src->head->value;
	s_index = src->head->s_index;
	push_stack(dest, value, s_index);
	pop_stack(src);
}

void	rotate(t_stack *stack)
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
}

void	reverse_rotate(t_stack *stack)
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
}
