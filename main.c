/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <gilee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 09:06:57 by gilee             #+#    #+#             */
/*   Updated: 2021/07/02 05:35:38 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"
#include "libft/libft.h"
#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

void	put_error(void *arg)
{
	free(arg);
	write(1, "Error\n", 6);
	exit(ERROR);
}

void	validate_argv(const char **argv)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	while (argv[++i])
	{
		tmp = ft_strtrim(argv[i], " ");
		if (!ft_strlen(tmp))
			put_error(tmp);
		while (tmp[j])
		{
			if (!((tmp[j] == '-' && ft_isdigit(tmp[j + 1])) || ft_isdigit(tmp[j]) || ft_isspace(tmp[j])))
				put_error(tmp);
			j++;
		}
		j = 0;
		free(tmp);
		tmp = NULL;
	}
	if (i == 1)
		put_error(NULL);
}

int	get_pivot(t_init *vars)
{
	int		pivot;
	int		i;
	t_dnode *tmp;

	i = 1;
	pivot = len_deque(&vars->stack_a) / 2;
	tmp = (&vars->stack_a)->head;
	while (i++ != pivot)
		tmp = tmp->next;
	return (tmp->content);
}

int	add_last_chkdup(t_init *vars, int content)
{
	int		duplicated;
	t_dnode	*tmp;

	duplicated = 0;
	tmp = (&vars->stack_a)->head;
	while (tmp)
	{
		if (tmp->content == content)
			duplicated = 1;
		tmp = tmp->next;
	}
	add_last(&vars->stack_a, content);
	return (duplicated);
}

int	init(const char **argv, int argc, t_init *vars)
{
	int		i;
	int		j;
	int		duplicated;
	char 	**tmp;

	i = 1;
	j = 0;
	duplicated = 0;
	init_deque(&vars->stack_a);
	while (i < argc)
	{
		tmp = ft_split(argv[i++], ' ');
		while (tmp[j])
			duplicated = add_last_chkdup(vars, ft_atoi(tmp[j++]));
		j = 0;
		while (tmp[j])
			free(tmp[j++]);
		free(tmp);
		j = 0;
	}
	return (duplicated);
}

int main(int argc, const char **argv)
{
	t_init	vars;

	validate_argv(argv);
	if (init(argv, argc, &vars))
	{
		free_deque(&vars.stack_a);
		put_error(NULL);
	}
	printf("pivot : %d\n", get_pivot(&vars));
	init_deque(&vars.stack_b);

	for (int i = 0 ; i < len_deque(&vars.stack_a) / 2 ; i++)
		p_stack(&vars.stack_b, &vars.stack_a);

	vars.tmp_a = vars.stack_a.head;
	vars.tmp_b = vars.stack_b.head;
	while (vars.tmp_a)
	{
		printf("%d ", vars.tmp_a->content);
		vars.tmp_a = vars.tmp_a->next;
	}
	printf("\nlen : %d", len_deque(&vars.stack_a));
	free_deque(&vars.stack_a);
	printf("\n");
	while (vars.tmp_b)
	{
		printf("%d ", vars.tmp_b->content);
		vars.tmp_b = vars.tmp_b->next;
	}
	printf("\nlen : %d", len_deque(&vars.stack_b));
	free_deque(&vars.stack_b);
	return 0;
}
