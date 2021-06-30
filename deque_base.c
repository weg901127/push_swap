/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_base.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <gilee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 13:05:51 by gilee             #+#    #+#             */
/*   Updated: 2021/06/30 16:14:07 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"

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

void	free_deque(t_deque *deque)
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

int		len_deque(t_deque *deque)
{
	t_dnode *tmp;
	int		len;

	len = 0;
	if (!is_empty(deque))
	{
		tmp = deque->head;
		while (tmp)
		{
			len++;
			tmp = tmp->next;
		}
	}
	return (len);
}
