/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <gilee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 09:06:57 by gilee             #+#    #+#             */
/*   Updated: 2021/11/24 01:08:30 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_sorted(t_init *vars)
{
	t_dnode	*tmp;

	tmp = vars->stack_a->head;
	while (tmp->next)
	{
		if (tmp->index > tmp->next->index)
			return (FALSE);
		tmp = tmp->next;
	}
	return (TRUE);
}

int	main(int argc, const char **argv)
{
	t_init	*vars;

	if (argc == 1)
		return (0);
	vars = malloc(sizeof(t_init *));
	validate_argv(argv);
	if (init(argv, argc, vars))
	{
		free_deque(&vars->stack_a);
		put_error(NULL);
	}
	set_index(vars->stack_a, vars->stack_a->size);
	if (is_sorted(vars))
		vars->stack_a->size = 1;
	init_deque(&vars->stack_b);
	if (vars->stack_a->size == 2)
		sort_two(vars->stack_a, TRUE);
	else if (vars->stack_a->size == 3)
		sort_three(vars->stack_a, TRUE);
	else if (vars->stack_a->size == 5)
		sort_five(vars);
	else
		a_to_b(vars->stack_a->size, vars);
	free_deque(&vars->stack_a);
	free_deque(&vars->stack_b);
	free(vars);
	return (0);
}
