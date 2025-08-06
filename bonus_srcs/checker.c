/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweber <nweber@student.42Heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 10:36:09 by nweber            #+#    #+#             */
/*   Updated: 2025/08/06 13:10:42 by nweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	execution(t_stack *stack_a, t_stack *stack_b, char *command)
{
	if (!ft_strcmp(command, "ra\n"))
		rotate(stack_a);
	else if (!ft_strcmp(command, "rb\n"))
		rotate(stack_b);
	else if (!ft_strcmp(command, "rr\n"))
		rr(stack_a, stack_b);
	else if (!ft_strcmp(command, "rra\n"))
		reverse_rotate(stack_a);
	else if (!ft_strcmp(command, "rrb\n"))
		reverse_rotate(stack_b);
	else if (!ft_strcmp(command, "rrr\n"))
		rrr(stack_a, stack_b);
	else if (!ft_strcmp(command, "pa\n"))
		push(stack_a, stack_b);
	else if (!ft_strcmp(command, "pb\n"))
		push(stack_b, stack_a);
	else if (!ft_strcmp(command, "sa\n"))
		swap(stack_a);
	else if (!ft_strcmp(command, "sb\n"))
		swap(stack_b);
	else if (!ft_strcmp(command, "ss\n"))
		ss(stack_a, stack_b);
	else
		return (0);
	return (1);
}

static void	init_stack(t_stack *stack_a, t_stack *stack_b, int *nums, int count)
{
	int	i;

	stack_a->head = NULL;
	stack_a->size = 0;
	stack_b->head = NULL;
	stack_b->size = 0;
	i = 0;
	while (i < count)
	{
		push_stack(stack_a, nums[i], i);
		i++;
	}
}

static void	get_instructions(t_stack *stack_a, t_stack *stack_b)
{
	char	*line;

	while (ft_fgets(&line))
	{
		if (ft_strncmp(line, "\n", 1) == 0)
			break ;
		execution(stack_a, stack_b, line);
		free(line);
		line = NULL;
	}
	free(line);
	if (check_sort(stack_a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;
	int		count;
	int		*numbers;

	if (argc == 1)
		error_exit("Error\n");
	count = get_numbers(argc, argv);
	numbers = parse_args(argc, argv, count);
	if (count <= 1 || is_duplicate(numbers, count))
	{
		free(numbers);
		if (count == 1)
			error_exit("Error\n");
		error_exit("Error\n");
	}
	init_stack(&stack_a, &stack_b, numbers, count);
	get_instructions(&stack_a, &stack_b);
	free(numbers);
	free_stack(&stack_a);
}
