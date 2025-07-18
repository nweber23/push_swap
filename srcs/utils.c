/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweber <nweber@student.42Heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 20:41:23 by nweber            #+#    #+#             */
/*   Updated: 2025/07/18 15:21:53 by nweber           ###   ########.fr       */
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
	int	count;

	count = 0;
	while (stack && stack->s_index != i)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}

void	error_exit(char *message)
{
	write(2, message, ft_strlen(message));
	exit(EXIT_FAILURE);
}

void	sort(t_stack *stack_a, t_stack *stack_b, int *numbers, int length)
{
	if (check_sort(stack_a))
	{
		free_stack(stack_a);
		free(numbers);
		error_exit("");
	}
	else if (length == 2)
		swap(stack_a, 'a', true);
	else if (length == 3)
		small_sort(stack_a, length);
	else if (length <= 7)
		minimal_sort(stack_a, stack_b, length);
	else if (length > 7)
	{
		sort1(stack_a, stack_b, length);
		sort2(stack_a, stack_b, length);
	}
	else
		error_exit("");
}