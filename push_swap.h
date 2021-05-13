#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define u32 uint32_t
# define i32 int32_t

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdint.h>

typedef struct	s_stack {
		struct	s_stack *next;
		u32		length;
		i32		value;
}				t_stack;

typedef struct	s_two_stacks {
		t_stack	*a;
		t_stack	*b;
}				t_two_stacks;

//дописать остальные возможные действия

t_stack			*new_stack(i32 value);
t_stack			*push(t_stack *stack, i32 value);
i32				pop(t_stack **stack);
t_two_stacks	*stacks_init(t_stack *a, t_stack *b);


void			sa(t_two_stacks *stacks);
void			sb(t_two_stacks *stacks);
void			ss(t_two_stacks *stacks);

void			ra(t_two_stacks **stacks);
void			rb(t_two_stacks **stacks);
void			rr(t_two_stacks **stacks);

void    		rrr(t_two_stacks *stacks);
void		    rrb(t_two_stacks *stacks);
void    		rra(t_two_stacks *stacks);


void    		pa(t_two_stacks **stacks);
void		    pb(t_two_stacks **stacks);

#endif
