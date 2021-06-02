#include "push_swap.h"

void	sort_through(t_two_stacks **stacks)
{
	int32_t		chunk;
	int32_t		index;

	chunk = (*stacks)->b->chunk;
	while (chunk_length((*stacks)->b, chunk) > 0)
	{
		index = find_next_index((*stacks)->b, chunk);
		replace_in_elem_a(stacks, index);
	}
}

void 	replace_in_elem_a(t_two_stacks **stacks, int32_t index)
{
	int32_t		counter;
	int32_t		chunk;

	counter = 0;
	chunk = (*stacks)->b->chunk;
	while ((*stacks)->b && (*stacks)->b->chunk == chunk)
	{
		if ((*stacks)->b->index == index)
		{
			(*stacks)->b->chunk = 0;
			pa(stacks);
			break ;
		}
		rb(stacks);
		++counter;
	}
	if (count_nodes((*stacks)->b) == chunk_length((*stacks)->b, chunk))
		return ;
	while (counter > 0)
	{
		rrb((*stacks));
		--counter;
	}
}
