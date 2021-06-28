/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <gilee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 16:18:35 by gilee             #+#    #+#             */
/*   Updated: 2021/06/23 18:34:59 by gilee            ###   ########.fr       */
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
	void			*content;
	struct s_dnode	*prev;
	struct s_dnode	*next;
}				t_dnode;

typedef struct	s_deque
{
	t_dnode *head;
	t_dnode *tail;
}				t_deque;

void	init_deque(t_deque *deque)
{
	deque->head = NULL;
	deque->tail = NULL;
}

int		is_empty(t_deque *deque)
{
	if (deque->head)
		return FALSE;
	else
		return TRUE;
}

void free_deque(t_deque *deque)
{
	t_dnode *tmp;

	if (!is_empty(deque))
	{
		while (deque->head)
		{
			tmp = deque->head->next;
			free(deque->head);
			deque->head = tmp;
		}
	}
}

void	add_first(t_deque *deque, void *data)
{
	t_dnode *newnode;

	newnode = (t_dnode *)ft_calloc(1, sizeof(t_dnode));
	newnode->content = data;
	newnode->prev = NULL;
	if (is_empty(deque))
	{
		newnode->next = NULL;
		deque->head = newnode;
		deque->tail = newnode;
	}
	else
	{
		deque->head->prev = newnode;
		newnode->next = deque->head;
	}
	deque->head = newnode;
}

#endif
