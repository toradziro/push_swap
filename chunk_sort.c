#include "push_swap.h"
/*
 * переписать, посчитать количество смещений вниз, после чего восстановить
 * применять мидпоинт до тех пор, пока в текущем чанке не останется 2 элемента
 *
 * перекинули большую половину чанка в А
 * из А перекинули меньшую половину опять в Б, пока не осталось всего 2
 * элемента, свапнули их, если нужно и вернулись опять в Б
 *
 * повторили до тех пор, пока Б не закончился
 */
void		chunk_sort(t_two_stacks **stacks)
{
	while (chunk_length((*stacks)->b, (*stacks)->b->chunk))
	{
		if (count_nodes((*stacks)->b) == 2 && (*stacks)->b->value < (*stacks)->b->next->value)
		{
			sb((*stacks));
			pa(stacks);
		}
		if (count_nodes((*stacks)->b) == 1)
		{
			pa(stacks);
			break;
		}
		recursively_divide_chunk_b(stacks, (*stacks)->b->chunk);
		recursively_divide_chunk_a(stacks, (*stacks)->a->chunk);
	}
}

void 		recursively_divide_chunk_b(t_two_stacks **stacks, i32 chunk)
{
	i32		p;
	i32		len;

	len = chunk_length((*stacks)->b, chunk);
	while (len > 2)
	{
		p = len / 2;//(len % 2 == 0) ? (len / 2) : ((len + 1) / 2);
		if (left_bigger_p((*stacks)->b, chunk, p))
		{
			replace_in_a(stacks, p, chunk);
		}
		len = chunk_length((*stacks)->b, chunk);
	}
	if (len <= 2)
	{
		if (len == 2)
		{
			pa(stacks);
			pa(stacks);
		}
		if (len == 1)
			pa(stacks);
	}
}

void 		recursively_divide_chunk_a(t_two_stacks **stacks, i32 chunk)
{
	i32		len;
	i32		p;

	len = chunk_length((*stacks)->a, chunk);
	while (len > 2)
	{
		p = (len % 2 == 0) ? (len / 2) : ((len + 1) / 2);
		if (left_less_p_ch((*stacks)->a, chunk, p))
			replace_in_b(stacks, p, chunk);
		else
			break ;
		len = chunk_length((*stacks)->a, chunk);
	}
	if (len == 2 && (*stacks)->a->value > (*stacks)->a->next->value)
		sa((*stacks));
}

i32			left_less_p_ch(t_stack *a, i32 chunk, i32 p)
{
	t_stack	*tmp;

	if (!a)
		return (0);
	tmp = a;
	while (tmp && tmp->chunk == chunk)
	{
		if (tmp->index <= p)
		{
			return (tmp->index);
		}
		tmp = tmp->next;
	}
	return (0);
}

void		replace_in_b(t_two_stacks **stacks, i32 mid, i32 chunk)
{
	i32		index;
	i32		counter;
	t_stack	*tmp;
	t_stack	*cont;

	counter = 0;
	tmp = (*stacks)->a;
	cont = tmp;
	index = left_less_p_ch(tmp, chunk, mid);
	while (tmp->chunk == chunk)
	{
		if (tmp->index == index)
		{
			++tmp->chunk;
			pb(stacks);
			break ;
		}
		tmp = tmp->next;
		ra(stacks);
		++counter;
	}
	while (counter > 0)
	{
		rra((*stacks));
		--counter;
	}
	tmp = cont;
}

//i32			find_midpoint_b(t_stack *b, i32 chunk)
//{
//}


void		replace_in_a(t_two_stacks **stacks, i32 mid, i32 chunk)
{
	i32		index;
	i32		counter;
	t_stack	*tmp;
	t_stack	*cont;

	counter = 0;
	tmp = (*stacks)->b;
	cont = tmp;
	index = left_bigger_p(tmp, chunk, mid);
	while (tmp && tmp->chunk == chunk)
	{
		if (tmp->index == index)
		{
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
	tmp = cont;
}


i32			left_bigger_p(t_stack *b, i32 chunk, i32 p)
{
	t_stack	*tmp;

	if (!b)
		return (0);
	tmp = b;
	while (tmp && tmp->chunk == chunk)
	{
		if (tmp->index > p)
			return (tmp->index);
		tmp = tmp->next;
	}
	return (0);
}

i32			chunk_length(t_stack *stack, i32 chunk)
{
	t_stack	*tmp;
	i32		len;

	if (!stack || stack->chunk != chunk)
		return (0);
	len = 0;
	tmp = stack;
	while (tmp && tmp->chunk == chunk)
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