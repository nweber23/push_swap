/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweber <nweber@student.42Heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 20:41:23 by nweber            #+#    #+#             */
/*   Updated: 2025/08/11 15:47:32 by nweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min_i(t_stack *stack)
{
	t_node	*current;
	int		min_i;

	if (!stack->head)
		return (-1);
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

void	rotate_to_min(t_stack *stack, int size)
{
	int	min_i;
	int	r;

	min_i = get_min_i(stack);
	r = count_r(stack->head, min_i);
	while (stack->head->s_index != min_i)
	{
		if (r <= size - r)
			rotate(stack, 'a', true);
		else
			reverse_rotate(stack, 'a', true);
	}
}

void	insertion_sort(int *nums, int n)
{
	int	element;
	int	i;
	int	j;

	i = 1;
	while (i < n)
	{
		element = nums[i];
		j = i - 1;
		while (j >= 0 && nums[j] > element)
		{
			nums[j + 1] = nums[j];
			j = j - 1;
		}
		nums[j + 1] = element;
		i++;
	}
}
