/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweber <nweber@student.42Heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 10:59:07 by nweber            #+#    #+#             */
/*   Updated: 2025/08/06 13:15:23 by nweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
			ft_array_free(str);
			free(nums);
			error_exit("Error\n");
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
	while (++i < argc)
	{
		str = ft_split(argv[i], ' ');
		if (!str)
			error_exit("Error\n");
		check_numbers(str, nums);
		temp = 0;
		while (str[temp])
			nums[j++] = ft_atoi(str[temp++]);
		ft_array_free(str);
	}
	return (nums);
}

int	ft_fgets(char **line)
{
	char	*buffer;
	char	input;
	int		i;
	int		count;

	i = 0;
	buffer = (char *)malloc(BUFFER_SIZE);
	if (!buffer)
		return (-1);
	count = read(0, &input, 1);
	while (count > 0 && input != '\n' && i < BUFFER_SIZE - 1)
	{
		buffer[i] = input;
		i++;
		count = read(0, &input, 1);
	}
	if (count > 0 && input == '\n')
		buffer[i++] = '\n';
	buffer[i] = '\0';
	*line = ft_strdup(buffer);
	free(buffer);
	if (count == 0 && i == 0)
		return (0);
	return (i);
}
