#include "push_swap.h"

void		chank_sort(t_two_stacks **stacks)
{
	i32				current_chank;
	i32				chank_max;
	t_two_stacks	*stacks_p;

	stacks_p = *stacks;
	current_chank = stacks_p->b->chank;
	while (stacks_p->b)
	{
		if (chank_length(stacks_p->b, current_chank) >= 30)
		{
			chank_partition(stacks_p->b, current_chank);
		}
		else
		{
			while (stacks_p->b && left_chank_top(stacks_p->b, current_chank))
			{
				chank_max = find_max_in_chank(stacks_p->b, current_chank);
				if (chank_max == stacks_p->b->index &&
					stacks_p->b->chank == current_chank && chank_max)
					pa(stacks);
				else if (chank_max)
				{
					while (chank_max != stacks_p->b->index &&
						   stacks_p->b->chank == current_chank)
						rb(stacks);
					pa(stacks);
					while (left_chank_bottom(stacks_p->b, current_chank))
						rrb(stacks_p);
				}
			}
		}
		--current_chank;
	}
}

void		chank_partition(t_two_stacks **stacks, i32 chank)
{
	i32		chank_median;
	t_two_stacks	*stacks_p;

	stacks_p = *stacks;
	chank_median = chank_length(stack, chank) / 2;
}

i32			chank_length(t_stack *stack, i32 chank)
{
	t_stack	*tmp;
	i32		len;

	len = 0;
	tmp = stack;
	while (tmp && tmp->chank == chank)
	{
		++len;
		tmp = tmp->next;
	}
	return (len);
}

i32			left_chank_top(t_stack *stack, i32 chank)
{
	if (stack->chank == chank)
		return (1);
	return (0);
}

i32			left_chank_bottom(t_stack *stack, i32 chank)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp && tmp->chank == chank)
		tmp = tmp->next;
	while (tmp && tmp->chank != chank)
		tmp = tmp->next;
	if (tmp && tmp->chank == chank)
		return (1);
	return (0);
}

i32			find_max_in_chank(t_stack *stack, i32 chank)
{
	t_stack	*tmp;
	i32		res;

	tmp = stack;
	res = 0;
	while (tmp && tmp->chank == chank)
	{
		if (tmp->index > res)
			res = tmp->index;
		tmp = tmp->next;
	}
	return (res);
}

/*
 * перенести все элементы до первого в чанке вниз, перенести первый из чанка
 * в стак А
 * посмотреть не является ли следующий элемент нужным
 * вытаскивать снизу до тех пор, пока чанк не закончится или не встретится
 * нужный элемент, если встретился, то сразу положить его в стак А
 */