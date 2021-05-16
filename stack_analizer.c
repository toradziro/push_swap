#include "push_swap.h"

/*
 * добавить проверку на одно значение
 * добавить свап двух элементов
 * добавить проверку на отсортированность стека
 */

void	sort_distributor(t_two_stacks **stacks)
{
	t_two_stacks	*stacks_p;

	stacks_p = *stacks;
	//check_if_sorted
	if (stacks_p->a->length <= LTL_CASE)
		three_elems_case(stacks);
	else if (stacks_p->a->length == FIVE_CASE)
		five_elems_case(stacks);
}