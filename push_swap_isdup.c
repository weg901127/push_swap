/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_isdup.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <gilee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 09:59:26 by gilee             #+#    #+#             */
/*   Updated: 2021/11/23 10:13:03 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_dup(t_dnode *tmp, int pivot, int dq_len, int is_A)
{
	int	i;
	int	ra;

	ra = 0;
	i = 0;
	if (is_A)
	{
		while (i++ < dq_len)
		{
			if (tmp->content > pivot)
				++ra;
			tmp = tmp->next;
		}
	}
	else
	{
		while (i++ < dq_len)
		{
			if (tmp->content < pivot)
				++ra;
			tmp = tmp->next;
		}
	}
	return (ra);
}

int	is_dup(int dq_len, int pivot, t_deque *stack, int is_A)
{
	t_dnode	*tmp;

	tmp = stack->head;
	if (dq_len == find_dup(tmp, pivot, dq_len, is_A))
		return (TRUE);
	return (FALSE);
}
