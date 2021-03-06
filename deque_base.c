/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_base.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <gilee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 13:05:51 by gilee             #+#    #+#             */
/*   Updated: 2021/11/24 00:46:51 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"

void	init_deque(t_deque **deque)
{
	*deque = (t_deque *)malloc(sizeof(t_deque));
	(*deque)->head = NULL;
	(*deque)->tail = NULL;
	(*deque)->size = 0;
}

int	is_empty(t_deque *deque)
{
	if (deque->size)
		return (FALSE);
	else
		return (TRUE);
}

void	free_deque(t_deque **deque)
{
	t_dnode	*tmp;

	if (!is_empty(*deque))
	{
		while ((*deque)->head)
		{
			tmp = (*deque)->head->next;
			free((*deque)->head);
			(*deque)->head = tmp;
		}
		tmp = NULL;
		(*deque)->head = NULL;
	}
	free(*deque);
}

int	len_deque(t_deque *deque)
{
	t_dnode	*tmp;
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
