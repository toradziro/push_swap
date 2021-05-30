#include "push_swap.h"

void		print_index(t_two_stacks *stacks)
{
	t_stack	*tmp_a = stacks->a;
	t_stack	*tmp_b = stacks->b;
	printf("Stack a: \n\n\n");
	while (stacks->a)
	{
		printf("index: %d, chunk: %d, value: %d\n", stacks->a->index,
		 stacks->a->chunk, stacks->a->value);
		stacks->a = stacks->a->next;
	}
	printf("Stack b: \n\n\n");
	while (stacks->b)
	{
		printf("index: %d, chunk: %d  value: %d\n", stacks->b->index,
		 stacks->b->chunk, stacks->b->value);
		stacks->b = stacks->b->next;
	}
	stacks->a = tmp_a;
	stacks->b = tmp_b;
}
