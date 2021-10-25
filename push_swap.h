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
	t_deque	*stack_a;
	t_deque	*stack_b;
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
/* push_swap_inst.c */
void	put_inst1(int (*func)(t_deque *), t_deque *stack, int is_A);
void	put_inst2(int (*func)(t_deque *, t_deque *), t_deque *stack_1, t_deque *stack_2, int is_A);
/* push_swap_sort.c */
void sort_three(t_init *vars);
void sort_five(t_init *vars);
void sort_by_index(t_init *vars);
/* quicksort.c */
void quicksort(int A[], int start, int end);
#endif
