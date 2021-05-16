NAME =	push_swap

SRCS =	moves_pa.c \
		moves_ra.c \
		moves_rra.c \
		moves_sa.c \
		push_swap.c \
		stack_utils.c \
		stack_analizer.c \
		three_elems_case.c \
		five_elems_case.c

OBJS =	$(SRCS:.c=.o)

CC =	gcc

FLAGS =	-g -Wall

.c.o:
		$(CC) $(FLAGS) -c $< -o ${<:.c=.o}

$(NAME): $(OBJS)
		$(CC) $(FLAGS) $(OBJS) -o $(NAME)
		@echo "Push swap created"

all:	$(NAME)

clean:
		rm -f $(OBJS)
		@echo "Object files were deleted"

fclean:	clean
		rm -f $(NAME)
		@echo "Everithing was deleted"

re:		fclean all

#.SILENT: