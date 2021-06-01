#include "push_swap.h"

void		chunk_sort(t_two_stacks **stacks)
{
	while ((*stacks)->b && chunk_length((*stacks)->b, (*stacks)->b->chunk))
	{
		if (count_nodes((*stacks)->b) == 1)
		{
			pa(stacks);
			break ;
		}
		if (chunk_length((*stacks)->b, (*stacks)->b->chunk) <= 10)
		{
			make_index((*stacks)->b, chunk_length((*stacks)->b, (*stacks)
			->b->chunk));
			sort_through(stacks);
		}
		else
		{
			recursively_divide_chunk_b(stacks, (*stacks)->b->chunk);
			make_index((*stacks)->a, chunk_length((*stacks)->a, (*stacks)
			->a->chunk));
			recursively_divide_chunk_a(stacks, (*stacks)->a->chunk, 1);
		}
	}
}

void 		hard_reput_in_a(t_two_stacks **stacks, i32 chunk)
{
	while ((*stacks)->b && (*stacks)->b->chunk == chunk)
		pa(stacks);
}

void		sort_through(t_two_stacks **stacks)
{
	i32		chunk;
	i32		index;

	chunk = (*stacks)->b->chunk;
	while (chunk_length((*stacks)->b, chunk) > 0)
	{
		index = find_next_index((*stacks)->b, chunk);
		replace_in_elem_a(stacks, index);
	}
}

i32			find_next_index(t_stack *stack, i32 chunk)
{
	t_stack	*tmp;
	i32		max;

	tmp = stack;
	max = 0;
	while (tmp && tmp->chunk == chunk)
	{
		if (tmp->index > max)
			max = tmp->index;
		tmp = tmp->next;
	}
	return (max);
}

void 	replace_in_elem_a(t_two_stacks **stacks, i32 index)
{
	i32 	counter;
	t_stack *tmp;
	i32		chunk;

	counter = 0;
	tmp = (*stacks)->b;
	chunk = (*stacks)->b->chunk;
	while (tmp && tmp->chunk == chunk)
	{
		if (tmp->index == index)
		{
			tmp->chunk = 0;
			pa(stacks);
			break ;
		}
		tmp = tmp->next;
		rb(stacks);
		++counter;
	}
	while (counter > 0)
	{
		rrb((*stacks));
		--counter;
	}
}
void 		recursively_divide_chunk_b(t_two_stacks **stacks, i32 chunk)
{
	i32		p;
	i32		len;

	len = chunk_length((*stacks)->b, chunk);
	p = len / 2;
	make_index((*stacks)->b, len);
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

void 		recursively_divide_chunk_a(t_two_stacks **stacks, i32 chunk,
								  		i32 inc)
{
	i32		len;
	i32		p;

	len = chunk_length((*stacks)->a, chunk);
	p = len / 2;
	make_index((*stacks)->a, len);
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


i32			left_less_p_ch(t_stack *a, i32 chunk, i32 p)
{
	t_stack	*tmp;
	i32		chunk_b;

	if (!a)
		return (0);
	tmp = a;
	chunk_b = a->chunk_b;
	while (tmp && tmp->chunk == chunk && tmp->chunk_b == chunk_b)
	{
		if (tmp->index <= p)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void		replace_in_b(t_two_stacks **stacks, i32 mid, i32 chunk, i32 inc)
{
	i32		counter;
	i32		len;

	counter = 0;
	len = chunk_length((*stacks)->a, chunk);
	while ((*stacks)->a->chunk == chunk && counter < len)
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
		if ((*stacks)->a->index <= mid && (*stacks)->a->chunk == chunk)
		{
			(*stacks)->a->chunk += inc;
			pb(stacks);
		}
		rra((*stacks));
		--counter;
	}
}

void		replace_in_a(t_two_stacks **stacks, i32 mid, i32 chunk)
{
	i32		counter;
	i32		len;

	counter = 0;
	len = chunk_length((*stacks)->b, chunk);
	while ((*stacks)->b && (*stacks)->b->chunk == chunk && counter < len)
	{
		if ((*stacks)->b->index >= mid)
		{
			pa(stacks);
			continue ;
		}
		rb(stacks);
		++counter;
	}
	while (counter > 0)
	{
		if ((*stacks)->b->index >= mid && (*stacks)->b->chunk == chunk)
			pa(stacks);
		rrb((*stacks));
		--counter;
	}
}


i32			left_bigger_p(t_stack *b, i32 chunk, i32 p)
{
	t_stack	*tmp;
	i32		chunk_b;

	if (!b)
		return (0);
	tmp = b;
	chunk_b = tmp->chunk_b;
	while (tmp && tmp->chunk == chunk && tmp->chunk_b == chunk_b)
	{
		if (tmp->index > p)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

i32			chunk_length(t_stack *stack, i32 chunk)
{
	t_stack	*tmp;
	i32		len;
	i32		chunk_b;

	if (!stack || stack->chunk != chunk)
		return (0);
	len = 0;
	tmp = stack;
	chunk_b = tmp->chunk_b;
	while (tmp && tmp->chunk == chunk && tmp->chunk_b == chunk_b)
	{
		++len;
		tmp = tmp->next;
	}
	return (len);
}

//i32			left_chunk_top(t_stack *stack, i32 chunk)
//{
//}
//
//i32			left_chunk_bottom(t_stack *stack, i32 chunk)
//{
//}
//
//i32			find_max_in_chunk(t_stack *stack, i32 chunk)
//{
//}