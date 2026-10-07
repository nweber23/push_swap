/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweber <nweber@student.42Heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 11:00:31 by nweber            #+#    #+#             */
/*   Updated: 2025/08/06 11:02:44 by nweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	ft_fgets(char **line)
{
	char	*buffer;
	char	input;
	int		i;
	int		count;

	*line = NULL;
	i = 0;
	buffer = (char *)malloc(BUFFER_SIZE);
	if (!buffer)
		return (-1);
	count = read(0, &input, 1);
	while (count > 0 && input != '\n' && i < BUFFER_SIZE - 1)
	{
		buffer[i++] = input;
		count = read(0, &input, 1);
	}
	if (count > 0 && input == '\n')
		buffer[i++] = '\n';
	buffer[i] = '\0';
	*line = ft_strdup(buffer);
	free(buffer);
	if (!*line)
		return (-1);
	return (i);
}
