#include "push_swap.h"

int		main(int argc, char **argv)
{
	t_two_stacks	*stacks;
	i32				i;

	i = argc - 1;
	if (argc == 1)
		return (0);
	stacks = stacks_init(NULL, NULL);
	if (!stacks)
		error_handle(&stacks);
	while (i > 0)
	{
		try_parse(argv[i], &stacks);
		--i;
	}
	if (is_no_repited(stacks->a))
	{
		error_handle(&stacks);
		return (1);
	}
	make_index(stacks->a, count_nodes(stacks->a), &stacks);
	sort_distributor(&stacks);
	return (0);
}

void			try_parse(char *str, t_two_stacks **stacks)
{
	i32			i;
	int64_t		res;

	i = 0;
	if (str[0] == '-' && str[1] > '9' && str[1] < '0')
		error_handle(stacks);
	if (str[0] == '-' && !str[1])
		error_handle(stacks);
	++i;
	while (str[i])
	{
		if (str[i] > '9' || str[i] < '0')
			error_handle(stacks);
		++i;
	}
	res = atol(&str[0]);
	if (res > I_32_MAX || res < I_32_MIN)
		error_handle(stacks);
	(*stacks)->a = push((*stacks)->a, res, 0, 0, 0);
}

void		error_handle(t_two_stacks **stacks)
{
	write(2, "Error\n", 6);
	free_stacks(stacks);
	exit(1);
}

void		free_stacks(t_two_stacks **stacks)
{
	i32		for_free;

	while ((*stacks)->a)
		for_free = pop(&((*stacks)->a));
	while ((*stacks)->b)
		for_free = pop(&((*stacks)->a));
}

i32			is_sorted(t_stack *a)
{
	t_stack	*tmp;

	tmp = a;
	while (tmp->next)
	{
		if (tmp->value > tmp->next->value)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}