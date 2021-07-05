/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <gilee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 13:16:55 by gilee             #+#    #+#             */
/*   Updated: 2021/07/05 07:59:21 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "deque.h"

# define SA 11
# define SB 10
# define PA 13
# define PB 12
# define RA 15
# define RB 14
# define RRA 17
# define RRB 16

typedef struct	s_init
{
	t_deque	stack_a;
	t_deque	stack_b;
	t_dnode	*tmp_a;
	t_dnode	*tmp_b;
}				t_init;
/* push_swap_single.c */
int	s_stack(t_deque *stack);
int	r_stack(t_deque *stack);
int	rrx_stack(t_deque *stack);
/* push_swap_multi.c */
int	p_stack(t_deque *stack_a, t_deque *stack_b);
int	ss_stack(t_deque *stack_a, t_deque *stack_b);
int	rr_stack(t_deque *stack_a, t_deque *stack_b);
int	rrr_stack(t_deque *stack_a, t_deque *stack_b);
/* quicksort.c */
void QuickSort(int A[], int start, int end);
#endif
