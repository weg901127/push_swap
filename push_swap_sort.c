/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <gilee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 08:22:44 by gilee             #+#    #+#             */
/*   Updated: 2021/11/24 00:06:58 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_deque *stack, int is_A)
{
	int	tmp[3];

	tmp[0] = stack->head->index;
	tmp[1] = stack->head->next->index;
	tmp[2] = stack->head->next->next->index;
	if (tmp[2] > tmp[0] && tmp[0] > tmp[1] && tmp[2] > tmp[0])
		put_inst1(s_stack, stack, is_A);
	else if (tmp[0] > tmp[2] && tmp[2] > tmp[1] && tmp[0] > tmp[1])
		put_inst1(r_stack, stack, is_A);
	else if (tmp[0] > tmp[2] && tmp[2] < tmp[1] && tmp[0] > tmp[1])
	{
		put_inst1(r_stack, stack, is_A);
		put_inst1(s_stack, stack, is_A);
	}
	else if (tmp[1] > tmp[0] && tmp[0] > tmp[2] && tmp[1] > tmp[2])
		put_inst1(rrx_stack, stack, is_A);
	else if (tmp[1] > tmp[0] && tmp[0] < tmp[2] && tmp[1] > tmp[2])
	{
		put_inst1(rrx_stack, stack, is_A);
		put_inst1(s_stack, stack, is_A);
	}
}

void	sort_five(t_init *vars)
{
	get_index(from_front(vars, 4), from_back(vars, 4), vars);
	get_index(from_front(vars, 0), from_back(vars, 0), vars);
	sort_three(vars->stack_a, TRUE);
	//sort_two(vars->stack_b, FALSE);
	put_inst2(p_stack, vars->stack_a, vars->stack_b, TRUE);
	put_inst2(p_stack, vars->stack_a, vars->stack_b, TRUE);
	put_inst1(r_stack, vars->stack_a, TRUE);
}

void	sort_two(t_deque *stack, int is_A)
{
	int	tmp[2];

	tmp[0] = stack->head->content;
	tmp[1] = stack->head->next->content;
	if (tmp[0] > tmp[1])
		put_inst1(s_stack, stack, is_A);
}
