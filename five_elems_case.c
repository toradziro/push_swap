#include "push_swap.h"

void 	five_elems_case(t_two_stacks **stacks)
{
	t_two_stacks	*stacks_p;

	stacks_p = *stacks;
	while (stacks_p->len_b != 2)
	{
		if (stacks_p->a->index == 5 || stacks_p->a->index == 1)
			pb(stacks);
		else
			ra(stacks);
	}
	three_elems_case(stacks);
	pa(stacks);
	pa(stacks);
	if (stacks_p->a->value > stacks_p->a->next->value)
		ra(stacks);
	else
	{
		sa(stacks_p);
		ra(stacks);
	}
}

void	check_first_two_elems(t_two_stacks **stacks)
{
	t_two_stacks	*stacks_p;

	stacks_p = *stacks;
	if (stacks_p->b->value > stacks_p->b->next->value)
		sb(stacks_p);
}