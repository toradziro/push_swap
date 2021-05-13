#include "push_swap.h"

t_stack		*new_stack(i32 value)
{
	t_stack	*new;

	new = (t_stack*)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->next = NULL;
	new->value = value;
	//new->current = NULL;
	return (new);
}

t_stack		*push(t_stack *stack, i32 value)
{
	t_stack	*new;
	t_stack	*tmp;

	if (!stack)
		stack = new_stack(value);
	else
	{
		new = new_stack(value); // handle possible errors
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
	return (new);
}

//void		error_exit(i32 code)
//{
//}
