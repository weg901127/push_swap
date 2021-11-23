/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_get.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <gilee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 13:13:02 by gilee             #+#    #+#             */
/*   Updated: 2021/11/23 10:18:57 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"

int	get_first(t_deque *deque)
{
	int	content;

	content = 0;
	if (!is_empty(deque))
		content = deque->head->content;
	return (content);
}

int	get_last(t_deque *deque)
{
	int	content;

	content = 0;
	if (!is_empty(deque))
		content = deque->tail->content;
	return (content);
}

t_dnode	*get_node(t_deque *deque, int *content, int *index)
{
	t_dnode	*tmp;

	tmp = deque->head;
	if (content)
	{
		while (tmp)
		{
			if (tmp->content == *content)
				return (tmp);
			tmp = tmp->next;
		}
	}
	else if (index)
	{
		while (tmp)
		{
			if (tmp->index == *index)
				return (tmp);
			tmp = tmp->next;
		}
	}
	return (NULL);
}
