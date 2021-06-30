/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <gilee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 13:16:55 by gilee             #+#    #+#             */
/*   Updated: 2021/06/30 17:28:44 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "deque.h"
/* push_swap_single.c */
int	s_stack(t_deque *stack);
int	r_stack(t_deque *stack);
int	rrx_stack(t_deque *stack);
/* push_swap_multi.c */
int	p_stack(t_deque *stack_a, t_deque *stack_b);
int	ss_stack(t_deque *stack_a, t_deque *stack_b);
int	rr_stack(t_deque *stack_a, t_deque *stack_b);
int	rrr_stack(t_deque *stack_a, t_deque *stack_b);
#endif
