/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <gilee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 08:22:18 by gilee             #+#    #+#             */
/*   Updated: 2021/11/24 00:01:09 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	fix_dup(int *dq_len, int *rrx_flag, int *rx)
{
	*rx = *dq_len;
	*dq_len = 0;
	*rrx_flag = FALSE;
}

static void	a_to_b_sort(int dq_len, t_init *vars, int *ra, int *pb)
{
	int	pivot;
	int	rrx_flag;

	rrx_flag = TRUE;
	pivot = get_pivot(vars->stack_a, dq_len);
	if (is_dup(dq_len, pivot, vars->stack_a, TRUE))
		fix_dup(&dq_len, &rrx_flag, ra);
	while (dq_len--)
	{
		if (vars->stack_a->head->content > pivot)
		{
			put_inst1(r_stack, vars->stack_a, TRUE);
			++(*ra);
		}
		else
		{
			put_inst2(p_stack, vars->stack_b, vars->stack_a, FALSE);
			++(*pb);
		}
	}
	if (rrx_flag)
		rrx_n(*ra, vars->stack_a, TRUE);
}

static void	b_to_a_sort(int dq_len, t_init *vars, int *rb, int *pa)
{
	int	pivot;
	int	rrx_flag;

	rrx_flag = TRUE;
	pivot = get_pivot(vars->stack_b, dq_len);
	if (is_dup(dq_len, pivot, vars->stack_b, FALSE))
		fix_dup(&dq_len, &rrx_flag, rb);
	while (dq_len--)
	{
		if (vars->stack_b->head->content < pivot)
		{
			put_inst1(r_stack, vars->stack_b, FALSE);
			++(*rb);
		}
		else
		{
			put_inst2(p_stack, vars->stack_a, vars->stack_b, TRUE);
			++(*pa);
		}
	}
	if (rrx_flag)
		rrx_n(*rb, vars->stack_b, FALSE);
}

void	a_to_b(int dq_len, t_init *vars)
{
	int	ra;
	int	pb;

	ra = 0;
	pb = 0;
	if (dq_len == 1 || dq_len == 0)
		return ;
	else if (dq_len == 2)
	{
		sort_two(vars->stack_a, TRUE);
		return ;
	}
	set_index(vars->stack_a, dq_len);
	a_to_b_sort(dq_len, vars, &ra, &pb);
	a_to_b(ra, vars);
	b_to_a(pb, vars);
}

void	b_to_a(int dq_len, t_init *vars)
{
	int	rb;
	int	pa;

	rb = 0;
	pa = 0;
	if (dq_len == 1)
	{
		put_inst2(p_stack, vars->stack_a, vars->stack_b, TRUE);
		--dq_len;
	}
	if (dq_len == 0)
		return ;
	set_index(vars->stack_b, dq_len);
	b_to_a_sort(dq_len, vars, &rb, &pa);
	a_to_b(pa, vars);
	b_to_a(rb, vars);
}
