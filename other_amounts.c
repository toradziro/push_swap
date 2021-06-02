#include "push_swap.h"

void	move_using_ra(t_two_stacks **stacks, int32_t current_index,
				   int32_t chunk_b)
{
	t_two_stacks	*stacks_p;

	stacks_p = *stacks;
	while (stacks_p->a)
	{
		if (stacks_p->a->index == current_index
			&& stacks_p->a->chunk_b == chunk_b)
			break ;
		ra(stacks);
	}
	pb(stacks);
}

void	move_using_rra(t_two_stacks **stacks, int32_t current_index,
					int32_t chunk_b)
{
	t_two_stacks	*stacks_p;

	stacks_p = *stacks;
	while (stacks_p->a)
	{
		if (stacks_p->a->index == current_index
			&& stacks_p->a->chunk_b == chunk_b)
			break ;
		rra(stacks_p);
	}
	pb(stacks);
}

int32_t	count_nodes(t_stack *stack)
{
	int32_t	i;
	t_stack	*tmp;

	if (!stack)
		return (0);
	i = 0;
	tmp = stack;
	while (tmp->next)
	{
		tmp = tmp->next;
		++i;
	}
	++i;
	return (i);
}
