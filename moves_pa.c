#include "push_swap.h"

void	pa(t_two_stacks **stacks)
{
	t_two_stacks	*change;
	int32_t			tmp_v;

	change = *stacks;
	if (!change->b)
		return ;
	--change->len_b;
	change->a = push(change->a, change->b->value, change->b->index,
			change->b->chunk);
	tmp_v = pop(&change->b);
	write (1, "pa\n", 3);
}

void	pb(t_two_stacks **stacks)
{
	t_two_stacks	*change;
	int32_t			tmp_v;

	change = *stacks;
	++change->len_b;
	change->b = push(change->b, change->a->value, change->a->index,
			change->a->chunk);
	tmp_v = pop(&change->a);
	write (1, "pb\n", 3);
}
