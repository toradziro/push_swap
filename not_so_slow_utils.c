#include "push_swap.h"

int32_t	find_partition(t_stack *stack)
{
	int32_t		p;

	p = find_biggest_elem(stack);
	return (p / 2);
}

int32_t	find_biggest_elem(t_stack *stack)
{
	t_stack	*tmp;
	int32_t	max;

	tmp = stack;
	max = 0;
	while (stack)
	{
		if (stack->index > max)
			max = stack->index;
		stack = stack->next;
	}
	stack = tmp;
	return (max);
}

int32_t	left_elems_less_p(t_stack *stack, int32_t p, int32_t chunk_b)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp)
	{
		if (tmp->index <= p && tmp->chunk_b == chunk_b)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
