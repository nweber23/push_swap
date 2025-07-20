/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niklas-weber <niklas-weber@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 19:09:05 by nweber            #+#    #+#             */
/*   Updated: 2025/07/20 18:15:35 by niklas-webe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_stack(t_stack *stack)
{
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

int	check_sort(t_stack *stack)
{
	t_node	*temp;

	temp = stack->head;
	while (temp->next)
	{
		if (temp->value > temp->next->value)
			return (0);
		temp = temp->next;
	}
	return (1);
}
