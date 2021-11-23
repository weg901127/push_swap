/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <gilee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 13:16:55 by gilee             #+#    #+#             */
/*   Updated: 2021/11/24 00:32:21 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "deque.h"

# define MAX 600
# define SA 11
# define SB 10
# define PA 13
# define PB 12
# define RA 15
# define RB 14
# define RRA 17
# define RRB 16

typedef struct s_init
{
	t_deque	*stack_a;
	t_deque	*stack_b;
	t_dnode	*tmp_a;
	t_dnode	*tmp_b;
}				t_init;
/* push_swap_single.c */
int		s_stack(t_deque *stack);
int		r_stack(t_deque *stack);
int		rrx_stack(t_deque *stack);
/* push_swap_multi.c */
int		p_stack(t_deque *stack_a, t_deque *stack_b);
int		ss_stack(t_deque *stack_a, t_deque *stack_b);
int		rr_stack(t_deque *stack_a, t_deque *stack_b);
int		rrr_stack(t_deque *stack_a, t_deque *stack_b);
/* push_swap_inst.c */
void	put_inst1(int (*func)(t_deque *), t_deque *stack, int is_A);
void	put_inst2(int (*func)(t_deque *, t_deque *),
			t_deque *stack_1, t_deque *stack_2, int is_A);
/* push_swap_sort.c */
void	sort_two(t_deque *stack, int is_A);
void	sort_three(t_deque *stack, int is_A);
void	sort_five(t_init *vars);
void	sort_by_index(t_init *vars);
/* push_swap_get_index.c */
int		from_back(t_init *vars, int target);
int		from_front(t_init *vars, int target);
void	get_index(int from_front, int from_back, t_init *vars);
/* push_swap_utils.c */
int		len_arr(int arr[]);
void	rrx_n(int n, t_deque *stack, int is_A);
void	rx_n(int n, t_deque *stack, int is_A);
int		get_pivot(t_deque *stack, int dq_len);
void	put_error(void *arg);
/* push_swap_algo.c */
void	a_to_b(int dq_len, t_init *vars);
void	b_to_a(int dq_len, t_init *vars);
/* push_swap_validation.c */
void	validate_argv(const char **argv);
void	set_index(t_deque *stack, int dq_len);
int		add_last_chkdup(t_init *vars, int before_len, int content);
int		init(const char **argv, int argc, t_init *vars);
/* push_swap_isdup.c */
int		is_dup(int dq_len, int pivot, t_deque *stack, int is_A);

/* quicksort.c */
void	quicksort(int A[], int start, int end);
#endif
