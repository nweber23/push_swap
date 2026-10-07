/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweber <nweber@student.42Heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 20:41:23 by nweber            #+#    #+#             */
/*   Updated: 2025/08/11 15:47:32 by nweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_stack *stack_a, t_stack *stack_b, int length)
{
	if (check_sort(stack_a))
		return ;
	else if (length == 2)
		swap(stack_a, 'a', true);
	else if (length == 3)
		small_sort(stack_a, length);
	else if (length <= 7)
		minimal_sort(stack_a, stack_b, length);
	else
	{
		sort1(stack_a, stack_b, length);
		sort2(stack_a, stack_b, length);
	}
}
