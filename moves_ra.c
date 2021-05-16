#include "push_swap.h"

void    	ra(t_two_stacks **stacks)
{
	t_stack	*to_free;
	t_two_stacks *change;
	t_stack	*tmp;
	t_stack *save;

	change = *stacks;
	save = change->a->next;
	tmp = new_stack(change->a->value);
	to_free = change->a;
	while (change->a->next)
		change->a = change->a->next;
	change->a->next = tmp;
	change->a = save;
	free(to_free);
	write(1,"ra\n" , 3);
}

void    rb(t_two_stacks **stacks)
{
	t_stack	*to_free;
	t_two_stacks *change;
	t_stack	*tmp;
	t_stack *save;

	change = *stacks;
	save = change->b->next;
	tmp = new_stack(change->b->value);
	to_free = change->b;
	while (change->b->next)
		change->b = change->b->next;
	change->b->next = tmp;
	change->b = save;
	free(to_free);
	write(1,"rb\n" , 3);
}

void    rr(t_two_stacks **stacks)
{
    ra(stacks);
    rb(stacks);
}