#include "push_swap.h"

void	sort_faster(t_two_stacks **stacks)
{
	t_two_stacks	*stacks_p;
	int32_t			len;

	stacks_p = *stacks;
	len = count_nodes(stacks_p->a);
	division_by_partitions(stacks, len, 1);
	chunk_sort(stacks);
}

void	division_by_partitions(t_two_stacks **stacks, int32_t len,
							int32_t chunk)
{
	t_two_stacks	*stacks_p;
	int32_t			p;

	stacks_p = *stacks;
	if (len <= 2)
	{
		if (len == 2 && stacks_p->a->value > stacks_p->a->next->value)
			sa(stacks_p);
		return ;
	}
	p = find_partition(stacks_p->a);
	restore_partied_elems(stacks, p, chunk);
	make_index(stacks_p->a, count_nodes(stacks_p->a), stacks);
	division_by_partitions(stacks, count_nodes(stacks_p->a), (chunk + 1));
}

void	restore_partied_elems(t_two_stacks **stacks, int32_t p, int32_t chunk)
{
	t_two_stacks	*stacks_p;

	stacks_p = *stacks;
	while (left_elems_less_p(stacks_p->a, p, 0))
		find_and_restore_closest(stacks_p, p, chunk, count_nodes(stacks_p->a));
}

void	find_and_restore_closest(t_two_stacks *stacks, int32_t p, int32_t chunk,
							  int32_t len)
{
	t_stack		*tmp;
	int32_t		i;

	tmp = stacks->a;
	i = 0;
	while (i < len)
	{
		if (tmp->index <= p)
		{
			tmp->chunk = chunk;
			if (i < (len / 2))
				move_using_ra(&stacks, tmp->index, 0);
			else
				move_using_rra(&stacks, tmp->index, 0);
			return ;
		}
		tmp = tmp->next;
		++i;
	}
}
