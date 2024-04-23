NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS =  src/operations/operation_handling.c \
		src/operations/pushs_swaps.c \
		src/operations/rotates.c \
		src/parsing/parsing.c \
		src/stack/stack_handling.c \
		src/stack/print_stacks.c \
		src/sort/sort_only_with_a.c \
		src/sort/chunks_sort.c \
		src/sort/sort.c \
		src/sort/optimise_ops.c \
		src/printf/printf.c \
		src/printf/puts.c \
		src/utils/utils.c \
		src/utils/split.c \
		src/push_swap.c

OBJS = ${SRCS:.c=.o}

%.o: %.c
	$(CC) $(CFLAGS) -Iinclude -c -g3 $< -o ${<:.c=.o}	
	
$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)
	#enlever -g3

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

all : $(NAME)
