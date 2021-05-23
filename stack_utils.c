#include "push_swap.h"

t_stack		*new_stack(i32 value)
{
	t_stack	*new;

	new = (t_stack*)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->next = NULL;
	new->value = value;
	new->length = 1;
	new->index = 0;
	new->chank = 0;
	return (new);
}

t_stack		*push(t_stack *stack, i32 value, i32 index, i32 chank)
{
	t_stack	*new;
	t_stack	*tmp;

	if (!stack)
	{
		stack = new_stack(value);
		stack->index = index;
		stack->chank = chank;
	}
	else
	{
		new = new_stack(value); // handle possible errors
		new->length = stack->length + 1;
		new->index = index;
		new->chank = chank;
		tmp = stack;
		stack = new;
		stack->next = tmp;
	}
	return (stack);
}

i32			pop(t_stack **stack)
{
	i32		tmp;
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

	new = (t_two_stacks*)malloc(sizeof(t_two_stacks));
	if (!new)
		return (NULL);
	new->a = a;
	new->b = b;
	new->min = 0;
	new->max = 0;
	new->len_b = 0;
	return (new);
}

void 		find_limits(t_two_stacks *stacks)
{
	t_stack	*iter;

	iter = stacks->a;
	stacks->min = I_32_MAX;
	stacks->max = I_32_MIN;
	while (iter)
	{
		if (iter->value > stacks->max)
			stacks->max = iter->value;
		iter = iter->next;
	}
	iter = stacks->a;
	while (iter)
	{
		if (iter->value < stacks->min)
			stacks->min = iter->value;
		iter = iter->next;
	}
}

void			find_limits_b(t_two_stacks *stacks)
{
	t_stack	*iter;

	iter = stacks->b;
	stacks->min = I_32_MAX;
	stacks->max = I_32_MIN;
	while (iter)
	{
		if (iter->value > stacks->max)
			stacks->max = iter->value;
		iter = iter->next;
	}
	iter = stacks->b;
	while (iter)
	{
		if (iter->value < stacks->min)
			stacks->min = iter->value;
		iter = iter->next;
	}
}

i32		is_no_repited(t_stack *a)
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

//void		error_exit(i32 code)
//{
//}
