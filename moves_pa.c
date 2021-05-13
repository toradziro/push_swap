#include "push_swap.h"

void    pa(t_two_stacks **stacks)
{
    t_two_stacks *change;
    i32 tmp_v;

    change = *stacks;
    change->a = push(change->a, change->b->value);
    tmp_v = pop(change->b);
}

void    pb(t_two_stacks **stacks)
{
    t_two_stacks *change;
    i32 tmp_v;

    change = *stacks;
    change->b = push(change->b, change->a->value);
    tmp_v = pop(change->a);
}