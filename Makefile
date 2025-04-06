
NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

	SRCS = 	src/push_swap.c \
			src/validation_functions.c \
			src/algorithm.c \
			src/optimize.c \
			src/score_calculator.c \
			src/moves.c \
			src/position_finder.c \
			src/operations/push.c \
			src/operations/rotate.c \
			src/operations/reverse_rotate.c \
			src/operations/swap.c \
			src/utils/ft_atol.c \
			src/utils/ft_print_char.c \
			src/utils/ft_print_string.c \
			src/utils/ft_strlen.c \
			src/utils/ft_split.c

BONUSSRCS = 


OBJS = $(SRCS:.c=.o)
BONUSOBJS = $(BONUSSRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

bonus: $(OBJS) $(BONUSOBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(BONUSOBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

rebonus: fclean bonus
