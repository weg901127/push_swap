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
	int	res;

	res = FALSE;
	if (len_deque(stack) > 1)
	{
		tmp = remove_first(stack);
		tmp2 = remove_first(stack);
		add_first(stack, tmp);
		add_first(stack, tmp2);
		res = SB;
	}
	return (res);
}

int	r_stack(t_deque *stack)
{
	int	content;
	int	res;

	res = FALSE;
	if (len_deque(stack))
	{
		content = remove_first(stack);
		add_last(stack, content);
		res = RB;
	}
	return (res);
}

int	rrx_stack(t_deque *stack)
{
	int	content;
	int	res;

	res = FALSE;
	if (!is_empty(stack))
	{
		content = remove_last(stack);
		add_first(stack, content);
		res = RRB;
	}
	return (res);
}
