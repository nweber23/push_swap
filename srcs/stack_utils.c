/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweber <nweber@student.42Heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 19:09:05 by nweber            #+#    #+#             */
/*   Updated: 2025/07/18 15:10:34 by nweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_stack(t_stack *stack)
{
	if (!stack)
		return ;
	while (stack)
		pop_stack(stack);
}

void	push_stack(t_stack *stack, int value, int s_index)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return ;
	new_node->value = value;
	new_node->s_index = s_index;
	new_node->next = stack->head;
	stack->head = new_node;
	stack->size++;
}

int	pop_stack(t_stack *stack)
{
	t_node	*temp;
	int		value;

	if (!stack->head)
		exit(EXIT_FAILURE);
	temp = stack->head;
	value = temp->value;
	stack->head = temp->next;
	free(temp);
	stack->size--;
	return (value);
}

void	assign_stack_index(t_stack *stack)
{
	t_node	*current;
	int		index;

	if (!stack || stack->size == 0)
		return ;
	current = stack->head;
	index = 0;
	while (current)
	{
		current->s_index = index++;
		current = current->next;
	}
}
