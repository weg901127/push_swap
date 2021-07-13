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
	int	tmp;
	int	tmp2;
	int tmp3;
	int tmp4;
	int	res;

	res = FALSE;
	if (len_deque(stack) > 1)
	{
		tmp3 = stack->head->index;
		tmp = remove_first(stack);
		tmp4 = stack->head->index;
		tmp2 = remove_first(stack);
		add_first(stack, tmp);
		stack->head->index = tmp3;
		add_first(stack, tmp2);
		stack->head->index = tmp4;
		res = SB;
	}
	return (res);
}

int	r_stack(t_deque *stack)
{
	int	content;
	int	index;
	int	res;

	res = FALSE;
	if (len_deque(stack))
	{
		index = stack->head->index;
		content = remove_first(stack);
		add_last(stack, content);
		stack->tail->index = index;
		res = RB;
	}
	return (res);
}

int	rrx_stack(t_deque *stack)
{
	int	content;
	int	index;
	int	res;

	res = FALSE;
	if (!is_empty(stack))
	{
		index = stack->tail->index;
		content = remove_last(stack);
		add_first(stack, content);
		stack->head->index = index;
		res = RRB;
	}
	return (res);
}
