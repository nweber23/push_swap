/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niklas-weber <niklas-weber@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 20:34:15 by nweber            #+#    #+#             */
/*   Updated: 2025/07/20 17:35:51 by niklas-webe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_numbers(int argc, char **argv)
{
	int	i;
	int	j;
	int	count;

	i = 1;
	count = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]) && argv[i][j] != ' '
					&& argv[i][j] != '-')
				return (-1);
			if (ft_isdigit(argv[i][j]) && (argv[i][j + 1] == ' '
					|| argv[i][j + 1] == '\0'))
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

void	check_numbers(char **str, int *nums)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_atol(str[i]) > INT_MAX \
			|| ft_atol(str[i]) < INT_MIN \
			|| ft_strlen(str[i]) > 11)
		{
			ft_free_array(str);
			free(nums);
			error_exit("ERROR");
		}
		i++;
	}
}

int	is_duplicate(int *nums, int len)
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

int	*parse_args(int argc, char **argv, int len)
{
	char	**str;
	int		*nums;
	int		i;
	int		j;
	int		temp;

	nums = (int *)malloc(sizeof(int) * len);
	if (!nums)
		return (NULL);
	i = 0;
	j = 0;
	while(++i < argc)
	{
		str = ft_split(argv[i], ' ');
		if (!str)
			error_exit("");
		check_numbers(str, nums);
		temp = 0;
		while (str[temp])
			nums[j++] = ft_atoi(str[temp++]);
		ft_free_array(str);
	}
	return (nums);
}
