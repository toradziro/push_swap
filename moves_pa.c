#include "push_swap.h"

void    pa(t_two_stacks **stacks)
{
    t_two_stacks *change;
    i32 tmp_v;

    change = *stacks;
    --change->len_b;
    change->a = push(change->a, change->b->value);
    tmp_v = pop(&change->b);
    write(1,"pa\n" , 3);
}

void    pb(t_two_stacks **stacks)
{
    t_two_stacks *change;
    i32 tmp_v;

    change = *stacks;
    ++change->len_b;
    change->b = push(change->b, change->a->value);
    tmp_v = pop(&change->a);
	write(1,"pb\n" , 3);
}