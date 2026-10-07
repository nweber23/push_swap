/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweber <nweber@student.42Heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 20:34:15 by nweber            #+#    #+#             */
/*   Updated: 2025/08/06 11:07:43 by nweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	parse_int(const char *s, int *out)
{
	long	n;
	int		sign;

	sign = 1;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	if (!ft_isdigit(*s))
		return (0);
	n = 0;
	while (ft_isdigit(*s))
	{
		n = n * 10 + (*s++ - '0');
		if (n > (long)INT_MAX + 1)
			return (0);
	}
	n *= sign;
	if (*s || n > INT_MAX || n < INT_MIN)
		return (0);
	*out = (int)n;
	return (1);
}

static int	count_tokens(int argc, char **argv)
{
	char	**words;
	int		i;
	int		w;
	int		count;

	count = 0;
	i = 0;
	while (++i < argc)
	{
		words = ft_split(argv[i], ' ');
		if (!words)
			return (-1);
		w = 0;
		while (words[w])
			w++;
		ft_array_free(words);
		if (w == 0)
			return (-1);
		count += w;
	}
	return (count);
}

static int	is_duplicate(int *nums, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (nums[i] == nums[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	fill_numbers(int argc, char **argv, int *nums)
{
	char	**words;
	int		i;
	int		w;
	int		j;

	i = 0;
	j = 0;
	while (++i < argc)
	{
		words = ft_split(argv[i], ' ');
		if (!words)
			return (0);
		w = 0;
		while (words[w] && parse_int(words[w], &nums[j]))
		{
			w++;
			j++;
		}
		w = (words[w] == NULL);
		ft_array_free(words);
		if (!w)
			return (0);
	}
	return (1);
}

int	*parse_args(int argc, char **argv, int *count)
{
	int	*nums;

	*count = count_tokens(argc, argv);
	if (*count < 0)
		error_exit("Error\n");
	nums = (int *)malloc(sizeof(int) * *count);
	if (!nums)
		error_exit("Error\n");
	if (!fill_numbers(argc, argv, nums) || is_duplicate(nums, *count))
	{
		free(nums);
		error_exit("Error\n");
	}
	return (nums);
}
