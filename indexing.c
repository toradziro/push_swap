#include "push_swap.h"

void	make_index(t_stack *stack, int32_t len, t_two_stacks **stacks)
{
	int32_t	*arr;
	int32_t	i;
	t_stack	*tmp;

	i = 0;
	tmp = stack;
	arr = (int32_t *)malloc(sizeof(int32_t) * (len + 1));
	if (!arr)
		error_handle(stacks);
	while (i < len)
	{
		arr[i] = tmp->value;
		tmp = tmp->next;
		++i;
	}
	q_sort(arr, 0, len - 1);
	finish_indexing(stack, arr, len);
}

void	q_sort(int32_t *num, int32_t start, int32_t end)
{
	int32_t	p;
	int32_t	i;
	int32_t	j;

	if (start < end)
	{
		i = start;
		j = end;
		p = num[(i + j) / 2];
		q_sort_main_loop(num, &i, &j, p);
		q_sort(num, start, j);
		q_sort(num, i, end);
	}
}

void	finish_indexing(t_stack *stack, int32_t *arr, int32_t len)
{
	int32_t	t;
	t_stack	*tmp;

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
				tmp->index = (t + 1);
				break ;
			}
			++t;
		}
		tmp = tmp->next;
	}
	free(&arr[0]);
}

void	q_sort_main_loop(int32_t *num, int32_t *i, int32_t *j, int32_t p)
{
	int32_t	tmp;

	while (*i <= *j)
	{
		while (num[*i] < p)
			++*i;
		while (num[*j] > p)
			--*j;
		if (*i <= *j)
		{
			tmp = *(num + *i);
			*(num + *i) = *(num + *j);
			*(num + *j) = tmp;
			++*i;
			--*j;
		}
	}
}
