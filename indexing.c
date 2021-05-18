#include "push_swap.h"

void		make_index(t_stack *stack)
{
	i32		*arr;
	i32		i;
	i32		t;
	t_stack	*tmp;

	i = 0;
	t = 0;
	tmp = stack;
	arr = (i32*)malloc(sizeof(i32) * stack->length);
	while (tmp)
	{
		arr[i] = tmp->value;
		tmp = tmp->next;
		++i;
	}
	q_sort(arr, 0, (stack->length));
	while (t < stack->length)
	{
		tmp = stack;
		while (tmp)
		{
			if (tmp->value == arr[t])
			{
				tmp->index = t + 1;
				break ;
			}
			tmp = tmp->next;
		}
		++t;
	}
	tmp = stack;
	t = 0;
	while (t < stack->length)
	{
		printf("%d%s", arr[t], ((t + 1 == stack->length) ? "\n" : ", "));
		++t;
	}
	while (tmp)
	{
		printf("%d%s", tmp->index, (tmp->next ? ", " : "\n"));
		tmp = tmp->next;
	}
}

void		q_sort(i32 *num, i32 start, i32 end)
{
	i32		p;

	if (start < end)
	{
		p = parti(num, start, end);
		q_sort(num, start, p);
		q_sort(num, p + 1, end);
	}
}

i32		parti(i32 *num, i32 start, i32 end)
{
	i32	p;
	i32	i;
	i32	j;
	i32	tmp;

	p = (end + start) / 2;
	i = start;
	j = end - 1;
	while (i <= j)
	{
		while (num[i] < num[p])
			++i;
		while (num[j] > num[p])
			--j;
		if (i <= j)
		{
			tmp = num[j];
			num[j] = num[i];
			num[i] = tmp;
			--j;
			++i;
		}
	}
	return (p);
}