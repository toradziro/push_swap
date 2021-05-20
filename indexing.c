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
	q_sort(arr, 0, (stack->length - 1));
//	while (t < stack->length)
//	{
//		printf ("%d ", arr[t]);
//		++t;
//	}
	t = 0;
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
	while (tmp)
	{
	//	printf("value: %d, index: %d%s", tmp->value, tmp->index, "\n");
		tmp = tmp->next;
	}
}

void		q_sort(i32 *num, i32 start, i32 end)
{
	i32		p;
	i32		i;
	i32		j;
	i32		tmp;

	if (start < end)
	{
		i = start;
		j = end;
		p = num[(i + j) / 2];
		while (i <= j)
		{
			while (num[i] < p)
				++i;
			while (num[j] > p)
				--j;
			if (i <= j)
			{
				tmp = num[i];
				num[i] = num[j];
				num[j] = tmp;
				++i;
				--j;
			}
		}
		q_sort(num, start, j);
		q_sort(num, i, end);
	}
}