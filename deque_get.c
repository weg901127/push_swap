/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_get.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <gilee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 13:13:02 by gilee             #+#    #+#             */
/*   Updated: 2021/07/01 18:59:02 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"

int	get_first(t_deque *deque)
{
	int	content;

	if (!is_empty(deque))
		content = deque->head->content;
	return (content);
}

int	get_last(t_deque *deque)
{
	int	content;

	if (!is_empty(deque))
		content = deque->tail->content;
	return (content);
}
