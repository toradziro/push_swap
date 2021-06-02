#include "push_swap.h"

t_stack	*new_stack(int32_t value, t_two_stacks **stacks)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		error_handle(stacks);
	new->next = NULL;
	new->value = value;
	new->length = 1;
	new->index = 0;
	new->chunk = 0;
	new->chunk_b = 0;
	return (new);
}

t_stack	*push(t_stack *stack, int32_t value, int32_t index, int32_t chunk)
{
	t_stack	*new;
	t_stack	*tmp;

	if (!stack)
	{
		stack = new_stack(value, NULL);
		stack->index = index;
		stack->chunk = chunk;
	}
	else
	{
		new = new_stack(value, NULL);
		new->length = stack->length + 1;
		new->index = index;
		new->chunk = chunk;
		tmp = stack;
		stack = new;
		stack->next = tmp;
	}
	return (stack);
}

int32_t	pop(t_stack **stack)
{
	int32_t	tmp;
	t_stack	*out;

	out = *stack;
	tmp = out->value;
	*stack = out->next;
	free(out);
	return (tmp);
}

t_two_stacks	*stacks_init(t_stack *a, t_stack *b)
{
	t_two_stacks	*new;

	new = (t_two_stacks *)malloc(sizeof(t_two_stacks));
	if (!new)
		return (NULL);
	new->a = a;
	new->b = b;
	new->min = 0;
	new->max = 0;
	new->len_b = 0;
	return (new);
}

int32_t	is_no_repited(t_stack *a)
{
	t_stack	*tmp;
	t_stack	*save;

	tmp = a;
	save = a;
	while (a->next)
	{
		tmp = a->next;
		while (tmp)
		{
			if (tmp->value == a->value)
				return (1);
			tmp = tmp->next;
		}
		a = a->next;
	}
	a = save;
	return (0);
}
