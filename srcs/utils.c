/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niklas-weber <niklas-weber@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 20:41:23 by nweber            #+#    #+#             */
/*   Updated: 2025/07/20 17:41:43 by niklas-webe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min_i(t_stack *stack)
{
	t_node	*current;
	int		min_i;

	current = stack->head;
	min_i = current->s_index;
	while (current)
	{
		current = current->next;
		if (current->s_index < min_i)
			min_i = current->s_index;
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
		free(numbers);
		free_stack(stack_a);
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
