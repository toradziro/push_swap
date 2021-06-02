#include "push_swap.h"

void	recursively_divide_chunk_a(t_two_stacks **stacks, int32_t chunk,
								int32_t inc)
{
	int32_t	len;
	int32_t	p;

	len = chunk_length((*stacks)->a, chunk);
	p = len / 2;
	make_index((*stacks)->a, len, stacks);
	while (left_less_p_ch((*stacks)->a, chunk, p))
		replace_in_b(stacks, p, chunk, inc);
	len = chunk_length((*stacks)->a, chunk);
	if (len <= 2)
	{
		if (len == 2 && (*stacks)->a->value > (*stacks)->a->next->value)
			sa(*stacks);
		return ;
	}
	recursively_divide_chunk_a(stacks, chunk, ++inc);
}

void	replace_in_b(t_two_stacks **stacks, int32_t mid, int32_t chunk,
				  int32_t inc)
{
	int32_t		counter;
	int32_t		len;

	counter = 0;
	len = chunk_length((*stacks)->a, chunk);
	while ((*stacks)->a->chunk == chunk && counter < len && left_less_p_ch(
			(*stacks)->a, chunk, mid))
	{
		if ((*stacks)->a->index <= mid)
		{
			(*stacks)->a->chunk += inc;
			pb(stacks);
			continue ;
		}
		ra(stacks);
		++counter;
	}
	while (counter > 0)
	{
		rra((*stacks));
		--counter;
	}
}

void	replace_in_a(t_two_stacks **stacks, int32_t mid, int32_t chunk)
{
	int32_t		counter;
	int32_t		len;

	counter = 0;
	len = chunk_length((*stacks)->b, chunk);
	while ((*stacks)->b && (*stacks)->b->chunk == chunk && counter < len
		   && left_bigger_p((*stacks)->b, chunk, mid))
	{
		if ((*stacks)->b->index >= mid)
		{
			pa(stacks);
			continue ;
		}
		rb(stacks);
		++counter;
	}
	if (count_nodes((*stacks)->b) == chunk_length((*stacks)->b, chunk))
		return ;
	while (counter > 0)
	{
		if ((*stacks)->b->index >= mid && (*stacks)->b->chunk == chunk)
			pa(stacks);
		rrb((*stacks));
		--counter;
	}
}

void	recursively_divide_chunk_b(t_two_stacks **stacks, int32_t chunk)
{
	int32_t		p;
	int32_t		len;

	len = chunk_length((*stacks)->b, chunk);
	p = len / 2;
	make_index((*stacks)->b, len, stacks);
	while (left_bigger_p((*stacks)->b, chunk, p))
		replace_in_a(stacks, p, chunk);
	len = chunk_length((*stacks)->b, chunk);
	if (len <= 2)
	{
		if (len == 2)
		{
			if ((*stacks)->b->value < (*stacks)->b->next->value)
				sb((*stacks));
			pa(stacks);
			pa(stacks);
		}
		if (len == 1)
			pa(stacks);
		return ;
	}
}
