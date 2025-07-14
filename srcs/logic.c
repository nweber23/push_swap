/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweber <nweber@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 20:34:13 by nweber            #+#    #+#             */
/*   Updated: 2025/07/14 20:34:13 by nweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort1(t_stack *stack_a, t_stack *stack_b, int length)
{
	int	i;
	int	range;

	i = 0;
	range = ft_sqrt(length) * 14 / 10;
	while (stack_a->head)
	{
		if (stack_a->head->s_index <= i)
		{
			pa(stack_b, stack_a, 'b', true);
			rb(stack_b, 'b', true);
			i++;
		}
		else if (stack_a->head->s_index <= i + range)
		{
			pb(stack_b, stack_a, 'b', true);
			i++;
		}
		else
			ra(stack_a, 'a', true);
	}
}

void	sort2(t_stack *stack_a, t_stack *stack_b, int length)
{
	int	rb_count;
	int	rrb_count;

	while (length - 1 >= 0)
	{
		rb_count = count_r(stack_b->head, length - 1);
		rrb_count = (length + 3) - rb_count;
		if (rb_count <= rrb_count)
		{
			while (stack_b->head->s_index != length - 1)
				rb(stack_b, 'b', true);
			pa(stack_a, stack_b, 'a', true);
			length--;
		}
		else
		{
			while (stack_b->head->s_index != length - 1)
				rrb(stack_b, 'b', true);
			pa(stack_a, stack_b, 'a', true);
			length--;
		}
	}
}
