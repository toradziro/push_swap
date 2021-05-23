#include "push_swap.h"

void		make_index(t_stack *stack)
{
	i32		*arr;
	i32		i;
	i32		t;
	i32		len;
	t_stack	*tmp;

	i = 0;
	tmp = stack;
	len = count_nodes(stack);
	arr = (i32*)malloc(sizeof(i32) * len);
	while (tmp)
	{
		arr[i] = tmp->value;
		tmp = tmp->next;
		++i;
	}
	q_sort(arr, 0, len); // проверить len или len - 1
	t = 0;
	tmp = stack;
	while (tmp)
	{
		arr = &arr[0];
		t = 0;
		while (t <= len)
		{
			if (tmp->value == arr[t])
			{
				tmp->index = t;
				break ;
			}
			++t;
		}
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