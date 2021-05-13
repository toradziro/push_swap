#include "push_swap.h"

int		main(int argc, char **argv)
{
	t_two_stacks	*stacks;
	i32				i;

	if (argc < 2)
	{
		printf("too less argc's\n");
		return (1);
	}
	i = 1;
	stacks = stacks_init(NULL, NULL);
	while (i < argc)
	{
		stacks->a = push(stacks->a, atoi(argv[i]));
		++i;
	}
	ra(&stacks);
	while (stacks->a)
		printf("%d\n", pop(&stacks->a));
	return (0);
}
