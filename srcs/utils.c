/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweber <nweber@student.42Heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 20:41:23 by nweber            #+#    #+#             */
/*   Updated: 2025/07/17 10:08:30 by nweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	get_min_i(t_stack *stack)
{
	t_node	*current;
	int		min_i;

	current = stack->head;
	min_i = current->s_index;
	while (current)
	{
		if (current->s_index < min_i)
			min_i = current->s_index;
		current = current->next;
	}
	return (min_i);
}

int	count_r(t_node *stack, int i)
{
	int count;

	count = 0;
	while (stack && stack->s_index != i)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}
