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
#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define MAX 600

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

void	set_index(t_deque *stack, int dq_len)
{
	int		arr[dq_len];
	int		i;
	t_dnode	*tmp;

	if (!dq_len)
		return ;
	tmp = stack->head;
	i = 0;
	while (i < dq_len)
	{
		arr[i++] = tmp->content;
		tmp = tmp->next;
	}
	quicksort(arr, 0, dq_len - 1);
	i = -1;
	while (++i < dq_len)
		get_node(stack, &arr[i], NULL)->index = i;
}

void	set_chunk(t_init *vars)
{
	int 	dq_len;
	int 	chunk_size;
	t_dnode	*tmp;

	dq_len = len_deque(vars->stack_a);
	chunk_size = dq_len / 10;
	if (chunk_size == 0)
		chunk_size = 1;
	while (dq_len--)
	{
		tmp = get_node(vars->stack_a, NULL, &dq_len);
		tmp->chunk = tmp->index / chunk_size;
	}
	tmp = NULL;
}

int	add_last_chkdup(t_init *vars, int content)
{
	int		duplicated;
	t_dnode	*tmp;

	duplicated = 0;
	tmp = vars->stack_a->head;
	while (tmp)
	{
		if (tmp->content == content)
			duplicated = 1;
		tmp = tmp->next;
	}
	add_last(vars->stack_a, content);
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

void	rrx_n(int n, t_deque *stack, int is_A)
{
	while (n--)
		put_inst1(rrx_stack, stack, is_A);
}

int		get_pivot(t_deque *stack, int dq_len)
{
	t_dnode	*tmp;
	int		idx;
	int		res;

	if (!dq_len)
		return 0;
	idx = dq_len / 2;
	tmp = stack->head;
	while (dq_len--)
	{
		if (tmp->index == idx)
			res =  tmp->content;
		tmp = tmp->next;
	}
	return res;
}

int	is_dup(int dq_len, int pivot, t_deque *stack, int is_A)
{
	int ra;
	int	pb;
	int	i;
	t_dnode *tmp;

	ra = 0;
	pb = 0;
	i = 0;
	tmp = stack->head;
	if (is_A)
		while (i++ < dq_len)
		{
			if (tmp->content > pivot)
				++ra;
			else
				++pb;
			tmp = tmp->next;
		}
	else
		while (i++ < dq_len)
		{
			if (tmp->content < pivot)
				++ra;
			else
				++pb;
			tmp = tmp->next;
		}
	if (dq_len == ra)
		return (TRUE);
	return (FALSE);
}
void	b_to_a(int dq_len, t_init *vars);

void	a_to_b(int dq_len, t_init *vars)
{
	int	pivot;
	int	ra;
	int	pb;
	int	rrx_flag;

	rrx_flag = TRUE;
	ra = 0;
	pb = 0;
	if (dq_len == 1 || dq_len == 0)
		return ;
	else if (dq_len == 2)
	{
		sort_two(vars->stack_a);
		return;
	}
	set_index(vars->stack_a, dq_len);
	pivot = get_pivot(vars->stack_a, dq_len);
	if (is_dup(dq_len, pivot, vars->stack_a, TRUE))
	{
		ra  = dq_len;
		dq_len = 0;
		rrx_flag = FALSE;
	}
	while (dq_len--)
	{
		if (vars->stack_a->head->content > pivot)
		{
			put_inst1(r_stack, vars->stack_a, TRUE);
			++ra;
		}
		else
		{
			put_inst2(p_stack, vars->stack_b, vars->stack_a, FALSE);
			++pb;
		}
	}
	if (rrx_flag)
		rrx_n(ra, vars->stack_a, TRUE);
	a_to_b(ra, vars);
	b_to_a(pb, vars);
}

void	b_to_a(int dq_len, t_init *vars)
{
	int	pivot;
	int	rb;
	int	pa;
	int	rrx_flag;

	rrx_flag = TRUE;
	rb = 0;
	pa = 0;
	if (dq_len == 1)
	{
		put_inst2(p_stack , vars->stack_a, vars->stack_b, TRUE);
		--dq_len;
	}
	if (dq_len == 0)
		return ;
	set_index(vars->stack_b, dq_len);
	pivot = get_pivot(vars->stack_b, dq_len);
	if (is_dup(dq_len, pivot, vars->stack_b, FALSE))
	{
		rb  = dq_len;
		dq_len = 0;
		rrx_flag = FALSE;
	}
	while(dq_len--)
	{
		if (vars->stack_b->head->content < pivot)
		{
			put_inst1(r_stack, vars->stack_b, FALSE);
			++rb;
		}
		else
		{
			put_inst2(p_stack, vars->stack_a, vars->stack_b, TRUE);
			++pa;
		}
	}
	if (rrx_flag)
		rrx_n(rb, vars->stack_b, FALSE);
	a_to_b(pa, vars);
	b_to_a(rb, vars);
}

int main(int argc, const char **argv)
{
	t_init	*vars;

	vars = malloc(sizeof(t_init *));
	validate_argv(argv);
	if (init(argv, argc, vars))
	{
		free_deque(&vars->stack_a);
		put_error(NULL);
	}
	set_index(vars->stack_a, vars->stack_a->size);
	set_chunk(vars);
	init_deque(&vars->stack_b);
	
	if (vars->stack_a->size < 4)
		sort_three(vars->stack_a, TRUE);
	else if (vars->stack_a->size == 5)
		sort_five(vars);
	else
		a_to_b(vars->stack_a->size, vars);
	free_deque(&vars->stack_a);
	free_deque(&vars->stack_b);
	return 0;
}
