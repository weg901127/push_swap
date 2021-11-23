/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_get_index.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <gilee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 08:22:32 by gilee             #+#    #+#             */
/*   Updated: 2021/11/24 00:08:08 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
int	from_back(t_init *vars, int target)
{
	t_dnode	*tmp;
	int		res;

	res = 0;
	tmp = vars->stack_a->tail;
	while (tmp)
	{
		res++;
		if (tmp->index == target)
			break ;
		tmp = tmp->prev;
	}
	return (res);
}

int	from_front(t_init *vars, int target)
{
	t_dnode	*tmp;
	int		res;

	res = 0;
	tmp = vars->stack_a->head;
	while (tmp)
	{
		res++;
		if (tmp->index == target)
			break ;
		tmp = tmp->next;
	}
	return (res - 1);
}

void	get_index(int from_front, int from_back, t_init *vars)
{
	if (from_front <= from_back)
	{
		rx_n(from_front, vars->stack_a, TRUE);
		put_inst2(p_stack, vars->stack_b, vars->stack_a, FALSE);
	}
	else
	{
		rrx_n(from_back, vars->stack_a, TRUE);
		put_inst2(p_stack, vars->stack_b, vars->stack_a, FALSE);
	}
}
