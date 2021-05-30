#include "push_swap.h"
/*
 * переписать, посчитать количество смещений вниз, после чего восстановить
 * применять мидпоинт до тех пор, пока в текущем чанке не останется 2 элемента
 *
 * перекинули большую половину чанка в А
 * из А перекинули меньшую половину опять в Б, пока не осталось всего 2
 * элемента, свапнули их, если нужно и вернулись опять в Б
 *
 * повторили до тех пор, пока Б не закончился
 */
void		chunk_sort(t_two_stacks **stacks)
{
	//recursively divide top chunk in B and sent it in A
	//recursively sent all from this chunk back to B
}

void 		recursively_divide_chunk(t_two_stacks **stacks, i32 chunk)
{
	i32		p;

	p = chunk_length((*stacks)->b, chunk);
	p = (p % 2 == 0) ? (p / 2) : ((p + 1) / 2);
	if (!p)
		return ;

}

//i32			find_midpoint_b(t_stack *b, i32 chunk)
//{
//}

//void		replace_in_b(t_two_stacks **stacks, i32 mid, i32 chunk)
//{
//}

//void		replace_in_a(t_two_stacks **stacks, i32 mid, i32 chunk)
//{
//}

//i32			left_less_p_ch(t_stack *b, i32 chunk, i32 p)
//{
//}

//i32			left_bigger_p(t_stack *b, i32 chunk, i32 p)
//{
//}

i32			chunk_length(t_stack *stack, i32 chunk)
{
	t_stack	*tmp;
	i32		len;

	len = 0;
	tmp = stack;
	while (tmp && tmp->chunk == chunk)
	{
		++len;
		tmp = tmp->next;
	}
	return (len);
}

//i32			left_chunk_top(t_stack *stack, i32 chunk)
//{
//}
//
//i32			left_chunk_bottom(t_stack *stack, i32 chunk)
//{
//}
//
//i32			find_max_in_chunk(t_stack *stack, i32 chunk)
//{
//}