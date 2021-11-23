/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_validation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <gilee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 08:22:53 by gilee             #+#    #+#             */
/*   Updated: 2021/11/24 01:07:30 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <stdlib.h>

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
			if (!((tmp[j] == '-' && ft_isdigit(tmp[j + 1]))
					|| ft_isdigit(tmp[j]) || ft_isspace(tmp[j])))
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

void	set_index(t_deque *stack, int dq_len)
{
	int		*arr;
	int		i;
	t_dnode	*tmp;

	if (!dq_len)
		return ;
	arr = ft_calloc(dq_len, sizeof(int));
	if (!arr)
		exit(1);
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
	free(arr);
}

int	add_last_chkdup(t_init *vars, int before_len, int content)
{
	int		duplicated;
	char	*after_char;
	t_dnode	*tmp;

	after_char = ft_itoa(content);
	if (before_len != (int)ft_strlen(after_char))
	{
		free(after_char);
		return TRUE;
	}
	duplicated = FALSE;
	tmp = vars->stack_a->head;
	while (tmp)
	{
		if (tmp->content == content)
			duplicated = TRUE;
		tmp = tmp->next;
	}
	add_last(vars->stack_a, content);
	free(after_char);
	return (duplicated);
}

int	init(const char **argv, int argc, t_init *vars)
{
	int		i;
	int		j;
	int		duplicated;
	char	**tmp;

	i = 1;
	j = 0;
	duplicated = 0;
	init_deque(&vars->stack_a);
	while (i < argc)
	{
		tmp = ft_split(argv[i++], ' ');
		while (tmp[j])
		{
			duplicated |= add_last_chkdup(vars, ft_strlen(tmp[j]),
					ft_atoi(tmp[j]));
			j++;
		}
		j = 0;
		while (tmp[j])
			free(tmp[j++]);
		free(tmp);
		j = 0;
	}
	return (duplicated);
}
