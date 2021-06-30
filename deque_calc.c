/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_calc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <gilee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 13:10:31 by gilee             #+#    #+#             */
/*   Updated: 2021/06/30 13:13:42 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"


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

void	add_last(t_deque *deque, void *data)
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
		deque->tail->next = newnode;
		newnode->prev = deque->tail;
	}
	deque->tail = newnode;
}

void	*remove_first(t_deque *deque)
{
	t_dnode *r_node;
	void	*r_content;

	r_content = NULL;
	r_node = deque->head;
	if (!is_empty(deque))
	{
		r_content = deque->head->content;
		deque->head = deque->head->next;
		free(r_node);
		r_node = NULL;
		if (deque->head == NULL)
			deque->tail = NULL;
		else
			deque->head->prev = NULL;	
	}
	return (r_content);
}

void	*remove_last(t_deque *deque)
{
	t_dnode *r_node;
	void	*r_content;

	r_content = NULL;
	r_node = deque->tail;
	if (!is_empty(deque))
	{
		r_content = deque->tail->content;
		deque->tail = deque->tail->prev;
		free(r_node);
		r_node = NULL;
		if (deque->tail == NULL)
			deque->head = NULL;
		else
			deque->tail->next = NULL;	
	}
	return (r_content);
}
