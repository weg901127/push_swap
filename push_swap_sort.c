#include "push_swap.h"

static int	get_max_index(t_init *vars, int cnt)
{
	t_dnode *tmp;
	int		cur;

	cnt -= 1;
	tmp = vars->stack_a->head;
	cur = tmp->index;
	while (cnt--)
	{
		if (tmp->next->index > cur)
			cur = tmp->next->index;
		tmp = tmp->next;
	}
	return (cur);
}

static int get_min_index(t_init *vars, int cnt)
{
	t_dnode *tmp;
	int		cur;

	cnt -= 1;
	tmp = vars->stack_a->head;
	cur = tmp->index;
	while (cnt--)
	{
		if (tmp->next->index < cur)
			cur = tmp->next->index;
		tmp = tmp->next;
	}
	return (cur);
}

void get_min_max(t_init *vars, int min, int max)
{
	int	cnt;

	cnt = 2;
	while (1)
	{
		if (vars->stack_a->head->index == min || vars->stack_a->head->index == max)
		{
			put_inst2(p_stack, vars->stack_b, vars->stack_a, FALSE);
			if (--cnt == 0)
				break;
		}
		put_inst1(r_stack, vars->stack_a, TRUE);
	}
}

void sort_three(t_init *vars)
{
	int	tmp[3];

	tmp[0] = vars->stack_a->head->index;
	tmp[1] = vars->stack_a->head->next->index;
	if (vars->stack_a->size > 2)
	{
		tmp[2] = vars->stack_a->head->next->next->index;
		if (tmp[2] > tmp[0] && tmp[0] > tmp[1] && tmp[2] > tmp[0])
			put_inst1(s_stack, vars->stack_a, TRUE);
		else if (tmp[0] > tmp[2] && tmp[2] > tmp[1] && tmp[0] > tmp[1])
			put_inst1(r_stack, vars->stack_a, TRUE);
		else if (tmp[0] > tmp[2] && tmp[2] < tmp[1] && tmp[0] > tmp[1])
		{
			put_inst1(r_stack, vars->stack_a, TRUE);
			put_inst1(s_stack, vars->stack_a, TRUE);
		}
		else if (tmp[1] > tmp[0] && tmp[0] > tmp[2] && tmp[1] > tmp[2])
			put_inst1(rrx_stack, vars->stack_a, TRUE);
		else if (tmp[1] > tmp[0] && tmp[0] < tmp[2] && tmp[1] > tmp[2])
		{
			put_inst1(rrx_stack, vars->stack_a, TRUE);
			put_inst1(s_stack, vars->stack_a, TRUE);
		}
	}
	else
		if (tmp[0] > tmp[1])
			put_inst1(s_stack, vars->stack_a, TRUE);
}

void	sort_five(t_init *vars)
{
	get_min_max(vars, get_min_index(vars, vars->stack_a->size), get_max_index(vars, vars->stack_a->size));
	sort_three(vars);
	put_inst2(p_stack, vars->stack_a, vars->stack_b, TRUE);
	put_inst2(p_stack, vars->stack_a, vars->stack_b, TRUE);
	if (vars->stack_a->head->index == get_max_index(vars, vars->stack_a->size))
		put_inst1(r_stack, vars->stack_a, TRUE);
	else
	{
		put_inst1(s_stack, vars->stack_a, TRUE);
		put_inst1(r_stack, vars->stack_a, TRUE);
	}
}

int	from_front(t_init *vars, int chunk)
{
	t_dnode	*tmp;
	int		cnt;

	cnt = -1;
	tmp = vars->stack_a->head;
	while ((int)vars->stack_a->size > cnt)
	{
		cnt++;
		if (tmp->chunk == chunk)
			break;
		tmp = tmp->next;
		if (!tmp)
			return (-1);
	}
	return cnt;
}

int	from_tail(t_init *vars, int chunk)
{
	t_dnode	*tmp;
	int		cnt;

	cnt = 0;
	tmp = vars->stack_a->tail;
	while ((int)vars->stack_a->size > cnt)
	{
		cnt++;
		if (tmp->chunk == chunk)
			break;
		tmp = tmp->prev;
		if (!tmp)
			return (-1);
	}
	return cnt;
}

void	sort_by_index(t_init *vars)
{
	int	cnt_front;
	int	cnt_tail;
	int	chunk;

	chunk = 0;
	cnt_front = 0;
	cnt_tail = 0;
	while (vars->stack_a->size)
	{
		cnt_front = from_front(vars, chunk);
		cnt_tail = from_tail(vars, chunk);
		if (cnt_front == -1 || cnt_tail == -1)
		{
			chunk++;
			continue;
		}
		if (cnt_front > cnt_tail)
			while (cnt_tail--)
				put_inst1(rrx_stack, vars->stack_a, TRUE);
		else
			while (cnt_front--)
				put_inst1(r_stack, vars->stack_a, TRUE);
		put_inst2(p_stack, vars->stack_b, vars->stack_a, FALSE);
	}
	//while (vars->stack_b->size)
	//	put_inst2(p_stack, vars->stack_a, vars->stack_b, TRUE);
}

