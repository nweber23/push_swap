/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweber <nweber@student.42Heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 20:34:15 by nweber            #+#    #+#             */
/*   Updated: 2025/07/18 10:21:58 by nweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	is_valid_arg(const char *arg)
{
	int		i;
	long	num;

	i = 0;
	if (arg[i] == '-' || arg[i] == '+')
		i++;
	if (arg[i] == '\0')
		return (0);
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			return (0);
		i++;
	}
	num = ft_atol(arg);
	if (num < INT_MIN || num > INT_MAX)
		return (0);
	return (1);
}

static int	is_duplicate(t_stack *stack, long num)
{
	t_node	*current;

	current = stack->head;
	while (current)
	{
		if (current->value == num)
			return (1);
		current = current->next;
	}
	return (0);
}

static int	add_number(t_stack *stack, char *arg)
{
	long num;

	if (!is_valid_arg(arg))
		return (0);
	num = ft_atol(arg);
	if (is_duplicate(stack, num))
		return (0);
	push_stack(stack, num, 0);
	return (1);
}

static int	split_args(char *str, char *args)
{
	char	**split_args;
	int		i;

	split_args = ft_split(str, ' ');
	if (!split_args)
		return (0);
	i = 0;
	while (split_args[i])
	{
		if (!add_number(args, split_args[i]))
		{
			while (split_args[i])
			{
				free(split_args[i]);
				i++;
			}
			free(split_args);
			return (0);
		}
		free(split_args[i]);
		i++;
	}
	free(split_args);
	return (1);
}

int	parse_args(int argc, char **argv, t_stack *stack)
{
	int		i;
	long	num;

	if (argc < 2)
		return (0);
	if (argc == 2)
		return (split_args(argv[1], stack));
	i = 1;
	while (i < argc)
	{
		if (!add_number(stack, argv[i]))
		{
			ft_putstr_fd("Error\n", STDERR_FILENO);
			return (0);
		}
		i++;
	}
	return (1);
}
