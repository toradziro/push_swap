#include "push_swap.h"

void	three_elems_case(t_two_stacks **stacks)
{
	t_two_stacks	*stacks_p;
	i32				one;
	i32				two;
	i32				three;

	stacks_p = *stacks;
	one = stacks_p->a->value;
	two = stacks_p->a->next->value;
	three = stacks_p->a->next->next->value;
	if (one > two && three > one)
		sa(stacks_p);
	else if (one > two && three < two)
	{
		sa(stacks_p);
		rra(stacks_p);
	}
	else if (one > three && three > two)
		ra(&stacks_p);
	else if (two > three && one < three)
	{
		sa(stacks_p);
		ra(&stacks_p);
	}
	else if (one > three && two > one)
		rra(stacks_p);
}