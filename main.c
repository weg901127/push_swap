/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <gilee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 09:06:57 by gilee             #+#    #+#             */
/*   Updated: 2021/07/07 22:12:55 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"
#include "libft/libft.h"
#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define MAX 600

int	is_ok(t_init *vars)
{
	t_dnode *tmp;

	tmp = (&vars->stack_a)->head;
	while (tmp->next)
	{
		if (tmp->content > tmp->next->content)
			return (FALSE);
		tmp = tmp->next;
	}
	return (TRUE);
}

void	put_inst1(int (*func)(t_deque *), t_deque *stack, int is_A)
{
	int res;

	res = func(stack) + is_A;
	if (res == SA)
		write(1, "sa\n", 3);
	else if (res == SB)
		write(1, "sb\n", 3);
	else if (res == RA)
		write(1, "ra\n", 3);
	else if (res == RB)
		write(1, "rb\n", 3);
	else if (res == RRA)
		write(1, "rra\n", 4);
	else if (res == RRB)
		write(1, "rrb\n", 4);
}

void	put_inst2(int (*func)(t_deque *, t_deque *), t_deque *stack_1, t_deque *stack_2, int is_A)
{
	int res;

	func(stack_1, stack_2);
	if (is_A)
		write(1, "pa\n", 3);
	else
		write(1, "pb\n", 3);
}

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

int len_arr(int arr[])
{
	int i;

	i = 0;
	while (arr[i++])
		;
	return (--i);
}

int	get_pivot(t_init *vars)
{
	int		dq_len;
	int		pivot;
	t_dnode	*tmp;

	dq_len = len_deque(&vars->stack_a);
	tmp = (&vars->stack_a)->head;
	pivot = (1 + dq_len) / 2;
	return (get_node(&vars->stack_a, NULL, &pivot)->content);
}

void	set_index(t_init *vars)
{
	int		dq_len;
	int		arr[MAX];
	int		i;
	t_dnode	*tmp;

	dq_len = len_deque(&vars->stack_a);
	tmp = (&vars->stack_a)->tail;
	while (dq_len)
	{
		arr[--dq_len] = tmp->content;
		tmp = tmp->prev;
	}
	printf("dq_len:%d ",len_deque(&vars->stack_a));
	QuickSort(arr, 0, len_deque(&vars->stack_a) - 1);
	for (int i = 0; i < len_deque(&vars->stack_a); i++)
		printf("%d ",arr[i]);
	i = 0;
	dq_len = len_deque(&vars->stack_a);
	while (dq_len--)
	{
		get_node(&vars->stack_a, &arr[i], NULL)->index = i + 1;
		i++;
	}
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

int	get_min(int len, t_dnode *tmp)
{
	int	min;

	min = tmp->content;
	while (len--)
	{
		if (tmp->content < min)
			min = tmp->content;
		tmp = tmp->next;
	}
	return (min);
}

void	sort(int dq_len, t_init *vars)
{
	t_dnode	*tmp;
	int		len;
	int		min;
	int     ra;

	ra = 0;
	len = dq_len;
	tmp = (&vars->stack_a)->head;
	if (dq_len <= 2)
	{
		if (dq_len == 2 && tmp->content > tmp->next->content)
			put_inst1(s_stack, &vars->stack_a, TRUE);
		return ;
	}
	min = get_min(len, (&vars->stack_a)->head);
	while (len--)
	{
		if ((&vars->stack_a)->head->content == min)
			put_inst2(p_stack, &vars->stack_b, &vars->stack_a, FALSE);
		else
		{
			put_inst1(r_stack, &vars->stack_a, TRUE);
			ra++;
		}
	}
	while (ra--)
		put_inst1(rrx_stack, &vars->stack_a, TRUE);
	sort(2, vars);
	put_inst2(p_stack, &vars->stack_a, &vars->stack_b, TRUE);
}
void	b_to_a(int dq_len, t_init *vars);

void	a_to_b(int dq_len, t_init *vars)
{
	int	pivot;
	int	len;
	int	ra;

	ra = 0;
	len = dq_len;
	if (dq_len <= 3)
	{
		sort(dq_len, vars);
		return ;
	}
	pivot = (&vars->stack_a)->head->content;
	while (len--)
	{
		if ((&vars->stack_a)->head->content < pivot)
		{
			put_inst1(r_stack, &vars->stack_a, TRUE);
			ra++;
		}
		else
			put_inst2(p_stack, &vars->stack_b, &vars->stack_a, FALSE);
	}
	a_to_b(ra, vars);
	b_to_a(dq_len - ra, vars);
}

void	b_to_a(int dq_len, t_init *vars)
{
	int	pivot;
	int	len;
	int	rb;

	rb = 0;
	len = dq_len;
	if (dq_len == 0)
		return ;
	pivot = (&vars->stack_b)->head->content;
	while (len--)
	{
		if ((&vars->stack_b)->head->content < pivot)
		{
			put_inst1(r_stack, &vars->stack_b, FALSE);
			rb++;
		}
		else
			put_inst2(p_stack, &vars->stack_a, &vars->stack_b, TRUE);
	}
	a_to_b(dq_len - rb, vars);
	b_to_a(rb, vars);
}

int main(int argc, const char **argv)
{
	t_init	*vars;

	validate_argv(argv);
	vars = (t_init *)malloc(sizeof(t_init));
	if (init(argv, argc, vars))
	{
		free_deque(&vars->stack_a);
		put_error(NULL);
	}
	set_index(vars);
	printf("pivot : %d\n", get_pivot(vars));
	init_deque(&vars->stack_b);

	a_to_b(len_deque(&vars->stack_a), vars);
	vars->tmp_a = (&vars->stack_a)->head;
	vars->tmp_b = (&vars->stack_b)->head;
	printf("A : ");
	while (vars->tmp_a)
	{
		printf("%d(%d) ", vars->tmp_a->content, vars->tmp_a->index);
		vars->tmp_a = vars->tmp_a->next;
	}
	printf("size:%d", vars->stack_a.size);
	free_deque(&vars->stack_a);
	
	printf("\n");
	printf("B : ");
	while (vars->tmp_b)
	{
		printf("%d(%d) ", vars->tmp_b->content, vars->tmp_b->index);
		vars->tmp_b = vars->tmp_b->next;
	}
	
	free_deque(&vars->stack_b);
	free(vars);
	return 0;
}
