/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_single.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <gilee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 13:50:56 by gilee             #+#    #+#             */
/*   Updated: 2021/11/23 10:22:26 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	s_stack(t_deque *stack)
{
	int	tmp[4];
	int	res;

	res = FALSE;
	if (len_deque(stack) > 1)
	{
		tmp[0] = stack->head->index;
		tmp[1] = remove_first(&stack);
		tmp[2] = stack->head->index;
		tmp[3] = remove_first(&stack);
		add_first(stack, tmp[1]);
		stack->head->index = tmp[0];
		add_first(stack, tmp[3]);
		stack->head->index = tmp[2];
		res = SB;
	}
	return (res);
}

int	r_stack(t_deque *stack)
{
	int	tmp[2];
	int	res;

	res = FALSE;
	if (len_deque(stack))
	{
		tmp[0] = stack->head->index;
		tmp[1] = remove_first(&stack);
		add_last(stack, tmp[1]);
		stack->tail->index = tmp[0];
		res = RB;
	}
	return (res);
}

int	rrx_stack(t_deque *stack)
{
	int	tmp[2];
	int	res;

	res = FALSE;
	if (!is_empty(stack))
	{
		tmp[0] = stack->tail->index;
		tmp[1] = remove_last(&stack);
		add_first(stack, tmp[1]);
		stack->head->index = tmp[0];
		res = RRB;
	}
	return (res);
}
