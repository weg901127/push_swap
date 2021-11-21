/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_calc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <gilee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 13:10:31 by gilee             #+#    #+#             */
/*   Updated: 2021/07/02 02:45:45 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"


void	add_first(t_deque *deque, int data)
{
	t_dnode *newnode;

	newnode = (t_dnode *)ft_calloc(1, sizeof(t_dnode));
	newnode->content = data;
	if (is_empty(deque))
	{
		deque->head = newnode;
		deque->tail = newnode;
	}
	else
	{
		deque->head->prev = newnode;
		newnode->next = deque->head;
	}
	deque->head = newnode;
	(deque->size)++;
}

void	add_last(t_deque *deque, int data)
{
	t_dnode *newnode;

	newnode = (t_dnode *)ft_calloc(1, sizeof(t_dnode));
	newnode->content = data;
	if (is_empty(deque))
	{
		deque->head = newnode;
		deque->tail = newnode;
	}
	else
	{
		deque->tail->next = newnode;
		newnode->prev = deque->tail;
	}
	deque->tail = newnode;
	(deque->size)++;
}

int	remove_first(t_deque **deque)
{
	t_dnode *r_node;
	int		r_content;

	r_content = ERROR;
	r_node = (*deque)->head;
	if (!is_empty(*deque))
	{
		r_content = (*deque)->head->content;
		(*deque)->head = (*deque)->head->next;
		free(r_node);
		r_node = NULL;
		if ((*deque)->head == NULL)
			(*deque)->tail = NULL;
		else
			(*deque)->head->prev = NULL;	
	}
	((*deque)->size)--;
	return (r_content);
}

int	remove_last(t_deque **deque)
{
	t_dnode *r_node;
	int		r_content;

	r_content = ERROR;
	r_node = (*deque)->tail;
	if (!is_empty(*deque))
	{
		r_content = (*deque)->tail->content;
		(*deque)->tail = (*deque)->tail->prev;
		free(r_node);
		r_node = NULL;
		if ((*deque)->tail == NULL)
			(*deque)->head = NULL;
		else
			(*deque)->tail->next = NULL;	
	}
	((*deque)->size)--;
	return (r_content);
}
