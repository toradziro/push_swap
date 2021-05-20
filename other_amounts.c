#include "push_swap.h"

void	sort_slow(t_two_stacks **stacks)
{
	i32	gap_start;
	i32	max_index;
	t_two_stacks	*stacks_p;

	stacks_p = *stacks;
	gap_start = 1;
	max_index = find_biggest_index(stacks_p->a); //проверить длину и индексацию
	while (gap_start <= max_index)
	{
		find_next_elem(stacks, gap_start);
		++gap_start;
	}
	while (stacks_p->b)
		pa(stacks);
}

void 	find_next_elem(t_two_stacks **stacks, i32 current_index)
{
	t_two_stacks	*stacks_p;
	t_stack			*tmp;
	i32				i;
	i32				stack_length;

	i = 1;
	stacks_p = *stacks;
	tmp = stacks_p->a;
	stack_length = count_nodes(stacks_p->a);
	while (tmp && tmp->index != current_index)
	{
		tmp = tmp->next;
		++i;
	}
	if (i <= (stack_length / 2))
		move_using_ra(stacks, current_index);
	else
		move_using_rra(stacks, current_index);
}

void 	move_using_ra(t_two_stacks **stacks, i32 current_index)
{
	t_two_stacks	*stacks_p;

	stacks_p = *stacks;
	while (stacks_p->a->index != current_index)
		ra(stacks);
	pb(stacks);
}

/*
 * Упаковать в указатели на функции
 */

void 	move_using_rra(t_two_stacks **stacks, i32 current_index)
{
	t_two_stacks	*stacks_p;

	stacks_p = *stacks;
	while (stacks_p->a->index != current_index)
		rra(stacks_p);
	pb(stacks);
}

i32		count_nodes(t_stack *stack)
{
	i32	i;
	t_stack *tmp;

	i = 0;
	tmp = stack;
	while (tmp)
	{
		tmp = tmp->next;
		++i;
	}
	++i;
	return (i);
}

i32		find_biggest_index(t_stack *stack)
{
	i32	res;
	t_stack	*tmp;

	res = 0;
	tmp = stack;
	while (tmp)
	{
		if (tmp->index > res)
			res = tmp->index;
		tmp = tmp->next;
	}
	return (res);
}

i32		find_portion(i32 max_index, i32 current_index)
{
	i32	res;

	if (max_index <= current_index)
		return (max_index);
	res = current_index + 10;
	if (max_index <= current_index)
		return (max_index);
	return (res);
}
/*
 * написать деление на порции (длину делим на десять)
 *
 * проходим по каждой подгруппе, находя следующий элемент, для этого написать
 * поиск по несортированному листу
 *
 * переносим эту группу по одной единице в стэк б
 *
 * когда стэк а пуст переносим все обратно в а
 *
 */