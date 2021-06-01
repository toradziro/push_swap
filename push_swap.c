#include "push_swap.h"

/*
 * Написать анализатор входящего стека на валидность
 * Написать проверку выполняемости каждого действия
 * Написать модуль очистки
 * Написать модуль обработки ошибок
 */

int		main(int argc, char **argv)
{
	t_two_stacks	*stacks;
	i32				i;

	if (argc < 2)
	{
		printf("too less argc's\n");
		return (1);
	}
	i = argc - 1;
	stacks = stacks_init(NULL, NULL);
	while (i > 0)
	{
		stacks->a = push(stacks->a, atoi(argv[i]), 0, 0, 0);
		--i;
	}
	if (is_no_repited(stacks->a))
	{
		printf ("Here are some repeated elements in arguments\n");
		return (1);
	}
	make_index(stacks->a, count_nodes(stacks->a));
	sort_distributor(&stacks);
/*	printf ("Here starts stack 'a'\n");
	while (stacks->a)
		printf("index: %d, chunk: %d value: %d\n", stacks->a->index,
		 stacks->a->chunk, pop(&stacks->a));
	printf("\n\n\n");
	printf ("Here starts stack 'b'\n");
	while (stacks->b)
		printf("index: %d, chunk: %d value: %d\n", stacks->b->index,
		 stacks->b->chunk, pop(&stacks->b)); */
	return (0);
}
