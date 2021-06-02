#include "push_swap.h"

void	sort_distributor(t_two_stacks **stacks)
{
	t_two_stacks	*stacks_p;

	stacks_p = *stacks;
	make_index(stacks_p->a, count_nodes(stacks_p->a), stacks);
	if (!is_sorted((*stacks)->a))
	{
		free_stacks(stacks);
		return ;
	}
	if (stacks_p->a->length == 1)
		return ;
	else if (stacks_p->a->length == 2)
	{
		if (stacks_p->a->value > stacks_p->a->next->value)
			sa(stacks_p);
	}
	else if (stacks_p->a->length == LTL_CASE)
		three_elems_case(stacks);
	else if (stacks_p->a->length == FIVE_CASE)
		five_elems_case(stacks);
	else
		sort_faster(stacks);
}
