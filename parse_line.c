#include "push_swap.h"

void	parse_line(char *str, t_two_stacks **stacks)
{
	int32_t	i;
	int64_t	val;

	i = check_for_parse(str, stacks);
	--i;
	while (i >= 0)
	{
		i = skip_nums(i, str);
		val = atol(&str[i]);
		--i;
		if (val > INT32_MAX || val < INT32_MIN)
			error_handle(stacks);
		(*stacks)->a = push((*stacks)->a, (int32_t)val, 0, 0);
		i = skip_spaces(i, str);
	}
}

int32_t	check_for_parse(char *str, t_two_stacks **stacks)
{
	int32_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] > '9' || str[i] < '0')
		{
			if (str[i] == '-' || str[i] == ' ')
			{
				++i;
				continue ;
			}
			error_handle(stacks);
		}
		++i;
	}
	return (i);
}

int32_t	skip_nums(int32_t i, char *str)
{
	while (str[i])
	{
		if (str[i - 1] == ' ' || i == 0)
			break ;
		--i;
	}
	return (i);
}

int32_t	skip_spaces(int32_t i, char *str)
{
	while (str[i] == ' ')
		--i;
	return (i);
}
