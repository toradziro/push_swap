#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define i32 int32_t

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdint.h>

# define LTL_CASE 3
# define FIVE_CASE 5
# define I_32_MIN -2147483648
# define I_32_MAX 2147483647

typedef struct	s_stack {
		struct	s_stack *next;
		i32		length;
		i32		value;
		i32		index;
}				t_stack;

typedef struct	s_two_stacks {
		t_stack	*a;
		t_stack	*b;
		i32		min;
		i32		max;
		i32		len_b;
}				t_two_stacks;

//дописать остальные возможные действия

t_stack			*new_stack(i32 value);
t_stack			*push(t_stack *stack, i32 value, i32 index);
i32				pop(t_stack **stack);
t_two_stacks	*stacks_init(t_stack *a, t_stack *b);
void			find_limits(t_two_stacks *stacks);
void			find_limits_b(t_two_stacks *stacks);
i32				find_portion(i32 max_index, i32 current_index);
void 			find_next_elem(t_two_stacks **stacks, i32 current_index);
i32				count_nodes(t_stack *stack);
void		 	move_using_ra(t_two_stacks **stacks, i32 current_index);
void		 	move_using_rra(t_two_stacks **stacks, i32 current_index);
i32				find_biggest_index(t_stack *stack);

void			make_index(t_stack *stack);
void			q_sort(i32 *num, i32 start, i32 end);
//i32				parti(i32 *num, i32 start, i32 end);

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

void			sort_distributor(t_two_stacks **stacks);
void			check_first_two_elems(t_two_stacks **stack);

void			three_elems_case(t_two_stacks **stacks);
void		 	five_elems_case(t_two_stacks **stacks);
void			sort_slow(t_two_stacks **stacks);

i32				is_sorted(t_stack *a);

#endif
