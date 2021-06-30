/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_single.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <gilee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 13:50:56 by gilee             #+#    #+#             */
/*   Updated: 2021/06/30 18:46:39 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"
#include "push_swap.h"

int	s_stack(t_deque *stack)
{
	void	*tmp;
	void	*tmp2;
	int		res;

	res = FALSE;
	if (len_deque(stack) > 1)
	{
		tmp = remove_first(stack);
		tmp2 = remove_first(stack);
		add_first(stack, tmp);
		add_first(stack, tmp2);
		res = TRUE;
	}
	return (res);
}

int	r_stack(t_deque *stack)
{
	void	*content;
	int		res;

	res = FALSE;
	if (len_deque(stack))
	{
		content = remove_first(stack);
		add_last(stack, content);
		res = TRUE;
	}
	return (res);
}

int	rrx_stack(t_deque *stack)
{
	void	*content;
	int		res;

	res = FALSE;
	if (!is_empty(stack))
	{
		content = remove_last(stack);
		add_first(stack, content);
		res = TRUE;
	}
	return (res);
}
