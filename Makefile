NAME =	push_swap

SRCS =	moves_pa.c \
		moves_ra.c \
		moves_rra.c \
		moves_sa.c \
		push_swap.c \
		stack_utils.c \
		stack_analizer.c \
		three_elems_case.c \
		five_elems_case.c \
		other_amounts.c \
		indexing.c \
		not_so_slow.c \
		chunk_sort.c \
		parse_line.c \
		chunk_sort_utils.c \
		recursively_division.c \
		sort_through.c \
		not_so_slow_utils.c

OBJS =	$(SRCS:.c=.o)

SRC_D =	$(SRCS:.c=.d)

CC =	gcc

FLAGS =	-g -MMD -Wall -fsanitize=address

.c.o:
		$(CC) $(FLAGS) -c $< -o ${<:.c=.o}

$(NAME): $(OBJS)
		$(CC) $(FLAGS) $(OBJS) -o $(NAME)
		@echo "Push swap created"

all:	$(NAME)

clean:
		rm -f $(OBJS)
		rm -f $(SRC_D)
		@echo "Object files were deleted"

fclean:	clean
		rm -f $(NAME)
		@echo "Everithing was deleted"

re:		fclean all

-include $(SRC_D)
#.SILENT: