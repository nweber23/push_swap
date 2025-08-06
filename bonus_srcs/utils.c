/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweber <nweber@student.42Heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 11:00:31 by nweber            #+#    #+#             */
/*   Updated: 2025/08/06 11:02:44 by nweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	error_exit(char *message)
{
	write(2, message, ft_strlen(message));
	exit(EXIT_FAILURE);
}

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
