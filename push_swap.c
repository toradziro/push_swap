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
		stacks->a = push(stacks->a, atoi(argv[i]));
		--i;
	}
	//find_limits(stacks);
	make_index(stacks->a);
	sort_distributor(&stacks);
	printf ("Here starts stack 'a'\n");
	while (stacks->a)
		printf("%d\n", pop(&stacks->a));
	return (0);
}
