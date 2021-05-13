#include "push_swap.h"

void	sa(t_two_stacks *stacks)
{
	i32	tmp;

	tmp = stacks->a->value;
	stacks->a->value = stacks->a->next->value;
	stacks->a->next->value = tmp;
}

void	sb(t_two_stacks *stacks)
{
	i32 tmp;

	tmp = stacks->b->value;
	stacks->b->value = stacks->b->next->value;
	stacks->b->next->value = tmp;
}

void	ss(t_two_stacks *stacks)
{
	sa(stacks);
	sb(stacks);
}
