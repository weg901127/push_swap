/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <gilee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 16:18:35 by gilee             #+#    #+#             */
/*   Updated: 2021/07/02 02:46:06 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEQUE_H
# define DEQUE_H
# include "libft/libft.h"
# ifndef NULL
#  define NULL (void *)0
# endif
# ifndef TRUE
#  define TRUE 1
# endif
# ifndef FALSE
#  define FALSE 0
# endif
# ifndef ERROR
#  define ERROR -1
# endif

typedef struct	s_dnode
{
	int				content;
	struct s_dnode	*prev;
	struct s_dnode	*next;
}				t_dnode;

typedef struct	s_deque
{
	t_dnode *head;
	t_dnode *tail;
}				t_deque;
/* deque_base.c */
void	init_deque(t_deque *deque);
int	is_empty(t_deque *deque);
void 	free_deque(t_deque *deque);
int	len_deque(t_deque *deque);
/* deque_calc.c */
void	add_first(t_deque *deque, int data);
void	add_last(t_deque *deque, int data);
int	remove_first(t_deque *deque);
int	remove_last(t_deque *deque);
/* deque_get.c */
int	get_first(t_deque *deque);
int	get_last(t_deque *deque);
#endif
