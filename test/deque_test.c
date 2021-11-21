#include "../deque.h"
#include <stdio.h>

int main()
{
	t_deque *stack;

	init_deque(&stack);
	add_first(stack, 1);
	add_first(stack, 2);
	add_first(stack, 3);
	add_first(stack, 4);
	add_first(stack, 5);
	t_dnode *tmp;
	tmp = stack->head;
	while (tmp)
	{
		printf("%d ",tmp->content);
		tmp = tmp->next;
	}
	printf("\n");
	return 0;
}
