/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweber <nweber@student.42Heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 20:34:10 by nweber            #+#    #+#             */
/*   Updated: 2025/07/18 14:48:22 by nweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	a.head = NULL;
	a.size = 0;
	b.head = NULL;
	b.size = 0;
	if (!parse_args(argc, argv, &a))
		error_exit("ERROR: Invalid input\n");
	assgin_stack_index(&a);
	if (a.size <= 1 || check_sort(&a))
		return (free_stack(&a), 0);
	if (a.size == 2)
		swap(&a, 'a', true);
	else if (a.size <= 5)
		minimal_sort(&a, &b, a.size);
	else
	{
		sort1(&a, &b, a.size);
		sort2(&a, &b, a.size);
	}
	free_stack(&a);
	free_stack(&b);
	return (0);
}
