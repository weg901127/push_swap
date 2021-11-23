/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_inst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <gilee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 08:22:36 by gilee             #+#    #+#             */
/*   Updated: 2021/11/23 10:21:50 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_inst1(int (*func)(t_deque *), t_deque *stack, int is_A)
{
	int	res;

	res = func(stack) + is_A;
	if (res == SA)
		write(1, "sa\n", 3);
	else if (res == SB)
		write(1, "sb\n", 3);
	else if (res == RA)
		write(1, "ra\n", 3);
	else if (res == RB)
		write(1, "rb\n", 3);
	else if (res == RRA)
		write(1, "rra\n", 4);
	else if (res == RRB)
		write(1, "rrb\n", 4);
}

void	put_inst2(int (*func)(t_deque *, t_deque *)
		, t_deque *stack_1, t_deque *stack_2, int is_A)
{
	func(stack_1, stack_2);
	if (is_A)
		write(1, "pa\n", 3);
	else
		write(1, "pb\n", 3);
}
