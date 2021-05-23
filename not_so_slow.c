#include "push_swap.h"

void		sort_faster(t_two_stacks **stacks)
{
	t_two_stacks	*stacks_p;
	i32				len;

	stacks_p = *stacks;
	len = count_nodes(stacks_p->a);
	division_by_partitions(stacks, len, 1);
	chank_sort(stacks);
}

void		division_by_partitions(t_two_stacks **stacks, i32 len, i32 chank)
{
	t_two_stacks	*stacks_p;
	i32				p;

	stacks_p = *stacks;
	if (len <= 2)
	{
		if (len == 2 && stacks_p->a->value > stacks_p->a->next->value)
			sa(stacks_p);
		return ;
	}
	p = find_partition(stacks_p->a);
	restore_partied_elems(stacks, p, chank);
	make_index(stacks_p->a);
	division_by_partitions(stacks, count_nodes(stacks_p->a), (chank + 1));
}

void		restore_partied_elems(t_two_stacks **stacks, i32 p, i32 chank)
{
	t_two_stacks	*stacks_p;

	stacks_p = *stacks;
	while (left_elems_less_p(stacks_p->a, p))
		find_and_restore_closest(stacks_p, p, chank);
}

i32		left_elems_less_p(t_stack *stack, i32 p)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp)
	{
		if (tmp->index <= p)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	find_and_restore_closest(t_two_stacks *stacks, i32 p, i32 chank)
{
	t_stack		*tmp;
	i32			len;
	i32			i;

	tmp = stacks->a;
	len = count_nodes(stacks->a);
	i = 0;
	while (i < (len / 2))
	{
		if (tmp->index <= p)
		{
			tmp->chank = chank;
			move_using_ra(&stacks, tmp->index);
			return ;
		}
		tmp = tmp->next;
		++i;
	}
	while (i < len)
	{
		if (tmp->index <= p)
		{
			tmp->chank = chank;
			move_using_rra(&stacks, tmp->index);
			return ;
		}
		tmp = tmp->next;
		++i;
	}
}

i32			find_partition(t_stack *stack)
{
	i32		p;

	p = find_biggest_elem(stack);
	return (p / 2);
}

i32			find_biggest_elem(t_stack *stack)
{
	t_stack	*tmp;
	i32		max;

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