#include "deque.h"
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

void sort_three(t_deque *stack, int is_A)
{
	int	tmp[3];

	tmp[0] = stack->head->index;
	tmp[1] = stack->head->next->index;
	if (stack->size > 2)
	{
		tmp[2] = stack->head->next->next->index;
		if (tmp[2] > tmp[0] && tmp[0] > tmp[1] && tmp[2] > tmp[0])
			put_inst1(s_stack, stack, is_A);
		else if (tmp[0] > tmp[2] && tmp[2] > tmp[1] && tmp[0] > tmp[1])
			put_inst1(r_stack, stack, is_A);
		else if (tmp[0] > tmp[2] && tmp[2] < tmp[1] && tmp[0] > tmp[1])
		{
			put_inst1(r_stack, stack, is_A);
			put_inst1(s_stack, stack, is_A);
		}
		else if (tmp[1] > tmp[0] && tmp[0] > tmp[2] && tmp[1] > tmp[2])
			put_inst1(rrx_stack, stack, is_A);
		else if (tmp[1] > tmp[0] && tmp[0] < tmp[2] && tmp[1] > tmp[2])
		{
			put_inst1(rrx_stack, stack, is_A);
			put_inst1(s_stack, stack, is_A);
		}
	}
	else
		if (tmp[0] > tmp[1])
			put_inst1(s_stack, stack, is_A);
}

void	sort_five(t_init *vars)
{
	get_min_max(vars, get_min_index(vars, vars->stack_a->size), get_max_index(vars, vars->stack_a->size));
	sort_three(vars->stack_a, TRUE);
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

void	sort_two(t_deque *stack)
{
	int	tmp[2];

	tmp[0] = stack->head->content;
	tmp[1] = stack->head->next->content;
	if (tmp[0] > tmp[1])
		put_inst1(s_stack, stack, TRUE);
}
