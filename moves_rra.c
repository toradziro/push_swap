#include "push_swap.h"

void    	rra(t_two_stacks *stacks)
{
	t_stack	*tmp;
	t_stack	*to_swap;

	tmp = stacks->a;
	while (tmp->next->next)
		tmp = tmp->next;
	to_swap = tmp->next;
	tmp->next = NULL;
	to_swap->next = stacks->a;
	stacks->a = to_swap;
}

void    rrb(t_two_stacks *stacks)
{
	t_stack	*tmp;
	t_stack	*to_swap;

	tmp = stacks->b;
	while (tmp->next->next)
		tmp = tmp->next;
	to_swap = tmp->next;
	tmp->next = NULL;
	to_swap->next = stacks->b;
	stacks->b = to_swap;
}

void    rrr(t_two_stacks *stacks)
{
    rra(stacks);
    rrb(stacks);
}