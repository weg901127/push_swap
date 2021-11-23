/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <gilee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 08:22:49 by gilee             #+#    #+#             */
/*   Updated: 2021/11/23 23:43:34 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	len_arr(int arr[])
{
	int	i;

	i = 0;
	while (arr[i++])
		;
	return (--i);
}

void	rrx_n(int n, t_deque *stack, int is_A)
{
	while (n--)
		put_inst1(rrx_stack, stack, is_A);
}

void	rx_n(int n, t_deque *stack, int is_A)
{
	while (n--)
		put_inst1(r_stack, stack, is_A);
}

int	get_pivot(t_deque *stack, int dq_len)
{
	t_dnode	*tmp;
	int		idx;
	int		res;

	if (!dq_len)
		return (0);
	idx = dq_len / 2;
	tmp = stack->head;
	while (dq_len--)
	{
		if (tmp->index == idx)
			res = tmp->content;
		tmp = tmp->next;
	}
	return (res);
}

void	put_error(void *arg)
{
	free(arg);
	write(1, "Error\n", 6);
	exit(ERROR);
}
