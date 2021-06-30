/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <gilee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 09:06:57 by gilee             #+#    #+#             */
/*   Updated: 2021/06/30 18:47:46 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int main()
{
	t_deque deque;
	t_deque deque2;
	t_dnode *tmp;
	t_dnode *tmp2;

	init_deque(&deque);
	add_last(&deque, "a");
	add_last(&deque, "b");
	add_last(&deque, "c");
	add_last(&deque, "d");
	add_last(&deque, "e");
	//remove_first(&deque);
	init_deque(&deque2);
	//add_last(&deque2, "a");
	//add_last(&deque2, "b");
	//add_last(&deque2, "c");
	//add_last(&deque2, "d");
	//add_last(&deque2, "e");

	//s_stack(&deque);
	//r_stack(&deque);
	//r_stack(&deque);
	p_stack(&deque2, &deque);
	p_stack(&deque2, &deque);
	//rr_stack(&deque, &deque2);
	//rrr_stack(&deque, &deque2);
	//ss_stack(&deque, &deque2);

	tmp = deque.head;
	tmp2 = deque2.head;
	while (tmp)
	{
		printf("%s", tmp->content);
		tmp = tmp->next;
	}
	printf("\n%d", len_deque(&deque));
	free_deque(&deque);
	printf("\n");
	while (tmp2)
	{
		printf("%s", tmp2->content);
		tmp2 = tmp2->next;
	}
	printf("\n%d", len_deque(&deque2));
	free_deque(&deque2);
	return 0;
}
