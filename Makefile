NAME = push_swap
BONUS = checker

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS =  src/operations/operation_handling.c \
		src/operations/pushs_swaps.c \
		src/operations/rotates.c \
		src/parsing/parsing.c \
		src/parsing/valid_atoi.c \
		src/stack/stack_handling.c \
		src/sort/push_back_to_a.c \
		src/sort/push_to_b.c \
		src/sort/utils.c \
		src/sort/sort.c \
		src/sort/optimise_ops.c \
		src/printf/printf.c \
		src/printf/puts.c \
		src/utils/utils.c \
		src/utils/split.c \
		src/push_swap.c

SRCS_BONUS = src/parsing/parsing.c \
		src/parsing/valid_atoi.c \
		src/bonus/gnl/gnl.c \
		src/bonus/gnl/gnl_utils.c \
		src/bonus/checker.c \
		src/utils/utils.c \
		src/sort/push_back_to_a.c \
		src/sort/push_to_b.c \
		src/sort/utils.c \
		src/sort/sort.c \
		src/utils/split.c \
		src/operations/pushs_swaps.c \
		src/operations/rotates.c \
		src/operations/operation_handling.c \
		src/stack/stack_handling.c

OBJS = ${SRCS:.c=.o}
OBJS_BONUS = ${SRCS_BONUS:.c=.o}

%.o: %.c
	$(CC) $(CFLAGS) -Iinclude -c $< -o ${<:.c=.o}	
	
$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)
$(BONUS): $(OBJS_BONUS)
	$(CC) $(OBJS_BONUS) -o $(BONUS)

clean:
	rm -f $(OBJS) ${OBJS_BONUS}

fclean: clean
	rm -f $(NAME) $(BONUS)

re: fclean all

all : $(NAME)

bonus: $(BONUS)
