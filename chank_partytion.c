#include "push_swap.h"

void		chunk_partition(t_two_stacks **stacks, i32 chunk)
{
	i32		len;
	t_two_stacks	*stacks_p;

	stacks_p = *stacks;
	len = chunk_length(stacks_p->b, chunk);
	put_in_stack_a_chunk(stacks, chunk);
	div_chunk(stacks, len, chunk, 1);
	ret_to_b(stacks);
//	while (stacks_p->a)
//	{
//		printf("%d\n", stacks_p->a->chunk_b);
//		stacks_p->a = stacks_p->a->next;
//	}
}

void	ret_to_b(t_two_stacks **stacks)
{
	t_two_stacks	*stacks_p;

	stacks_p = *stacks;
	while (left_chunk_b_in_a(stacks_p->a))
	{
		rra(stacks_p);
		if (stacks_p->a->chunk_b == 1)
		{
			stacks_p->a->chunk_b = 0;
			pb(stacks);
		}
//		else
//		{
//			ra(stacks);
//			break ;
//		}
	}
}

i32			left_chunk_b_in_a(t_stack *a)
{
	t_stack	*tmp;

	tmp = a;
	while (tmp)
	{
		if (tmp->chunk_b == 1)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void		put_in_stack_a_chunk(t_two_stacks **stacks, i32 chunk)
{
	t_two_stacks	*stacks_p;

	stacks_p = *stacks;
	while (stacks_p->b && stacks_p->b->chunk == chunk)
	{
		stacks_p->b->chunk_b = 1;
		pa(stacks);
	}
}

void 		div_chunk(t_two_stacks **stacks, i32 len, i32 chunk, i32 chunk_b)
{
	t_two_stacks	*stacks_p;
	i32				p;

	p = len / 2;
	stacks_p = *stacks;
	if (len <= 2)
	{
		if (len == 2 && stacks_p->a->value > stacks_p->a->next->value)
			sa(stacks_p);
		return;
	}
	//make_index(stacks_p->a);
	if (left_elems_more_p(stacks_p->a, p, 1))
		find_and_restore_closest_b(stacks_p, p, chunk, 1);
	back_to_top_b(stacks);
	div_chunk(stacks, p, chunk, 1);
}

void	find_and_restore_closest_b(t_two_stacks *stacks, i32 p, i32 chunk, i32
chunk_b)
{
	t_stack		*tmp;
	i32			len;
	i32			i;

	tmp = stacks->a;
	len = count_nodes(stacks->a);
	i = 0;
	while (i < (len / 2))
	{
		if (tmp->index <= p && tmp->chunk_b == chunk_b)
		{
			tmp->chunk += 1;
			move_using_ra(&stacks, tmp->index, chunk_b);
			return ;
		}
		tmp = tmp->next;
		++i;
	}
	while (i < len)
	{
		if (tmp->index <= p && tmp->chunk_b == chunk_b)
		{
			tmp->chunk += 1;
			move_using_rra(&stacks, tmp->index, chunk_b);
			return ;
		}
		tmp = tmp->next;
		++i;
	}
}

i32		left_elems_more_p(t_stack *stack, i32 p, i32 chunk_b)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp)
	{
		if (tmp->index > p && tmp->chunk_b == chunk_b)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void		back_to_top_b(t_two_stacks **stacks)
{
	t_stack	*tmp;

	printf("\n\n\nHERE\n\n\n");

	tmp = (*stacks)->a;
	while (left_in_bottom_a(tmp))
		rra(*stacks);
}

i32		left_in_bottom_a(t_stack *a)
{
	t_stack	*tmp;

	tmp = a;
	while (tmp->next)
		tmp = tmp->next;
	if (tmp->chunk_b == 1)
		return (1);
	return (0);
}