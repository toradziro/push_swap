#include "push_swap.h"

int32_t	left_bigger_p(t_stack *b, int32_t chunk, int32_t p)
{
	t_stack	*tmp;
	int32_t	chunk_b;

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

int32_t	chunk_length(t_stack *stack, int32_t chunk)
{
	t_stack	*tmp;
	int32_t	len;
	int32_t	chunk_b;

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

int32_t	left_less_p_ch(t_stack *a, int32_t chunk, int32_t p)
{
	t_stack	*tmp;
	int32_t	chunk_b;

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

int32_t	find_next_index(t_stack *stack, int32_t chunk)
{
	t_stack	*tmp;
	int32_t	max;

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
