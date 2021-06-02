#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdint.h>

# define LTL_CASE 3
# define FIVE_CASE 5
# define I_32_MIN -2147483648
# define I_32_MAX 2147483647

typedef struct s_stack {
	struct s_stack	*next;
	int32_t			length;
	int32_t			value;
	int32_t			index;
	int32_t			chunk;
	int32_t			chunk_b;
}				t_stack;

typedef struct s_two_stacks {
	t_stack	*a;
	t_stack	*b;
	int32_t	min;
	int32_t	max;
	int32_t	len_b;
}				t_two_stacks;

t_stack			*new_stack(int32_t value, t_two_stacks **stacks);
t_stack			*push(t_stack *stack, int32_t value, int32_t index,
					int32_t chunk);
int32_t			pop(t_stack **stack);
t_two_stacks	*stacks_init(t_stack *a, t_stack *b);
int32_t			count_nodes(t_stack *stack);
void			move_using_ra(t_two_stacks **stacks, int32_t current_index,
					int32_t chunk_b);
void			move_using_rra(t_two_stacks **stacks, int32_t current_index,
					int32_t chunk_b);
void			make_index(t_stack *stack, int32_t len, t_two_stacks **stacks);
void			q_sort(int32_t *num, int32_t start, int32_t end);
void			sa(t_two_stacks *stacks);
void			sb(t_two_stacks *stacks);
void			ss(t_two_stacks *stacks);
void			ra(t_two_stacks **stacks);
void			rb(t_two_stacks **stacks);
void			rr(t_two_stacks **stacks);
void			rrr(t_two_stacks *stacks);
void			rrb(t_two_stacks *stacks);
void			rra(t_two_stacks *stacks);
void			pa(t_two_stacks **stacks);
void			pb(t_two_stacks **stacks);
void			sort_distributor(t_two_stacks **stacks);
void			three_elems_case(t_two_stacks **stacks);
void			five_elems_case(t_two_stacks **stacks);
int32_t			is_no_repited(t_stack *a);
void			division_by_partitions(t_two_stacks **stacks, int32_t len,
					int32_t chunk);
int32_t			find_partition(t_stack *stack);
void			restore_partied_elems(t_two_stacks **stacks, int32_t p,
					int32_t chunk);
int32_t			left_elems_less_p(t_stack *stack, int32_t p, int32_t chunk_b);
void			find_and_restore_closest(t_two_stacks *stacks, int32_t p,
					int32_t chunk, int32_t len);
void			sort_faster(t_two_stacks **stacks);
void			chunk_sort(t_two_stacks **stacks);
int32_t			chunk_length(t_stack *stack, int32_t chunk);
int32_t			left_bigger_p(t_stack *b, int32_t chunk, int32_t p);
void			replace_in_a(t_two_stacks **stacks, int32_t mid, int32_t chunk);
int32_t			left_less_p_ch(t_stack *b, int32_t chunk, int32_t p);
void			recursively_divide_chunk_b(t_two_stacks **stacks,
					int32_t chunk);
void			recursively_divide_chunk_a(t_two_stacks **stacks, int32_t chunk,
					int32_t inc);
void			replace_in_b(t_two_stacks **stacks, int32_t mid, int32_t chunk,
					int32_t inc);
void			sort_through(t_two_stacks **stacks);
int32_t			find_next_index(t_stack *stack, int32_t chunk);
void			replace_in_elem_a(t_two_stacks **stacks, int32_t index);
void			try_parse(char *str, t_two_stacks **stacks);
void			error_handle(t_two_stacks **stacks);
int32_t			is_sorted(t_stack *a);
void			free_stacks(t_two_stacks **stacks);
void			parse_line(char *str, t_two_stacks **stacks);
int32_t			skip_nums(int32_t i, char *str);
int32_t			skip_spaces(int32_t i, char *str);
void			q_sort_main_loop(int32_t *num, int32_t *i, int32_t *j,
					int32_t p);
void			finish_indexing(t_stack *stack, int32_t *arr, int32_t len);
int32_t			find_biggest_elem(t_stack *stack);
int32_t			check_for_parse(char *str, t_two_stacks **stacks);

#endif
