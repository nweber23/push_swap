/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweber <nweber@student.42Heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 20:34:13 by nweber            #+#    #+#             */
/*   Updated: 2025/07/17 10:11:29 by nweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	single_rotation(t_stack *stack, int i)
{
	int	a;
	int	b;
	int	c;

	(void)i;
	a = stack->head->value;
	b = stack->head->next->value;
	c = stack->head->next->next->value;
	if (a < b && b < c)
		return (1);
	if (b < c && a > c)
		return (1);
	if (a > c && a < b)
		return (1);
	return (0);
}

void	small_sort(t_stack *stack, int len)
{
	int	min_s_i;
	int	r;

	if (check_sort(stack))
		return ;
	min_s_i = get_min_i(stack);
	r = count_r(stack->head, min_s_i);
	if (single_rotation(stack, min_s_i))
	{
		if (r < len - r)
			ra(stack, 'a', true);
		else
			rra(stack, 'a', true);
	}
}

void	sort1(t_stack *stack_a, t_stack *stack_b, int len)
{
	int	i;
	int	range;

	i = 0;
	range = ft_sqrt(len) * 14 / 10;
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

void	sort2(t_stack *stack_a, t_stack *stack_b, int len)
{
	int	rb_count;
	int	rrb_count;

	while (len - 1 >= 0)
	{
		rb_count = count_r(stack_b->head, len - 1);
		rrb_count = (len + 3) - rb_count;
		if (rb_count <= rrb_count)
		{
			while (stack_b->head->s_index != len - 1)
				rb(stack_b, 'b', true);
			pa(stack_a, stack_b, 'a', true);
			len--;
		}
		else
		{
			while (stack_b->head->s_index != len - 1)
				rrb(stack_b, 'b', true);
			pa(stack_a, stack_b, 'a', true);
			len--;
		}
	}
}
