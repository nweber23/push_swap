/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweber <nweber@student.42Heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 22:15:54 by nweber            #+#    #+#             */
/*   Updated: 2025/07/27 15:37:02 by nweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int index_of(int n, int *arr, int len)
{
	int i = 0;
	while (i < len)
	{
		if (arr[i] == n)
			return i;
		i++;
	}
	return -1;
}

static void	init_stack(t_stack *stack_a, t_stack *stack_b, int *nums, int c)
{
	int		i;
	t_node	*temp;

	stack_a->head = NULL;
	stack_b->head = NULL;
	stack_a->size = 0;
	stack_b->size = 0;
	i = c;
	while (--i >= 0)
		push_stack(stack_a, nums[i], 0);
	insertion_sort(nums, c);
	temp = stack_a->head;
	while (temp)
	{
		temp->s_index = index_of(temp->value, nums, c);
		temp = temp->next;
	}
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	int		count;
	int		*numbers;

	if (argc == 1)
		error_exit("");
	count = get_numbers(argc, argv);
	numbers = parse_args(argc, argv, count);
	if (count <= 1 || is_duplicate(numbers, count))
	{
		free(numbers);
		if (count == 1)
			error_exit("Error\n");
		error_exit("Error\n");
	}
	init_stack(&a, &b, numbers, count);
	sort(&a, &b, numbers, count);
	free(numbers);
	free_stack(&a);
	return (0);
}
