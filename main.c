#include "deque.h"
#include <stdio.h>

int main()
{
	t_deque deque;

	init_deque(&deque);
	add_first(&deque, "a");

	printf("%s", deque.head->content);
	free_deque(&deque);
	return 0;
}
