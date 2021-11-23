/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_multi.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <gilee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 17:25:08 by gilee             #+#    #+#             */
/*   Updated: 2021/11/23 10:22:49 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	p_stack(t_deque *stack_a, t_deque *stack_b)
{
	int	tmp[2];
	int	res;

	res = FALSE;
	tmp[0] = stack_b->head->index;
	tmp[1] = remove_first(&stack_b);
	add_first(stack_a, tmp[1]);
	stack_a->head->index = tmp[0];
	res = TRUE;
	return (res);
}

int	ss_stack(t_deque *stack_a, t_deque *stack_b)
{
	int	res;

	res = FALSE;
	if (!is_empty(stack_b) || !is_empty(stack_a))
		res = s_stack(stack_a) + s_stack(stack_b);
	return (res);
}

int	rr_stack(t_deque *stack_a, t_deque *stack_b)
{
	int	res;

	res = r_stack(stack_a) + r_stack(stack_b);
	return (res);
}

int	rrr_stack(t_deque *stack_a, t_deque *stack_b)
{
	int	res;

	res = rrx_stack(stack_a) + rrx_stack(stack_b);
	return (res);
}
