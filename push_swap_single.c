/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_single.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <gilee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 13:50:56 by gilee             #+#    #+#             */
/*   Updated: 2021/07/05 08:00:20 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	s_stack(t_deque *stack)
{
	int	tmp[6];
	int	res;

	res = FALSE;
	if (len_deque(stack) > 1)
	{
		tmp[2] = stack->head->index;
		tmp[4] = stack->head->chunk;
		tmp[0] = remove_first(&stack);
		tmp[3] = stack->head->index;
		tmp[5] = stack->head->chunk;
		tmp[1] = remove_first(&stack);
		add_first(stack, tmp[0]);
		stack->head->index = tmp[2];
		stack->head->chunk = tmp[4];
		add_first(stack, tmp[1]);
		stack->head->index = tmp[3];
		stack->head->chunk = tmp[5];
		res = SB;
	}
	return (res);
}

int	r_stack(t_deque *stack)
{
	int tmp[3];
	int	res;

	res = FALSE;
	if (len_deque(stack))
	{
		tmp[0] = stack->head->index;
		tmp[1] = stack->head->chunk;
		tmp[2] = remove_first(&stack);
		add_last(stack, tmp[2]);
		stack->tail->index = tmp[0];
		stack->tail->chunk = tmp[1];
		res = RB;
	}
	return (res);
}

int	rrx_stack(t_deque *stack)
{
	int tmp[3];
	int	res;

	res = FALSE;
	if (!is_empty(stack))
	{
		tmp[0] = stack->tail->index;
		tmp[1] = stack->tail->chunk;
		tmp[2] = remove_last(&stack);
		add_first(stack, tmp[2]);
		stack->head->index = tmp[0];
		stack->head->chunk = tmp[1];
		res = RRB;
	}
	return (res);
}
