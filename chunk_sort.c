#include "push_swap.h"

void	chunk_sort(t_two_stacks **stacks)
{
	while ((*stacks)->b && chunk_length((*stacks)->b, (*stacks)->b->chunk))
	{
		if (chunk_length((*stacks)->b, (*stacks)->b->chunk) <= 10)
		{
			make_index((*stacks)->b, chunk_length((*stacks)->b, (*stacks)
					->b->chunk), stacks);
			sort_through(stacks);
		}
		else
		{
			recursively_divide_chunk_b(stacks, (*stacks)->b->chunk);
			make_index((*stacks)->a, chunk_length((*stacks)->a, (*stacks)
					->a->chunk), stacks);
			recursively_divide_chunk_a(stacks, (*stacks)->a->chunk, 1);
		}
	}
}
