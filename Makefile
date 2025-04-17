
NAME = push_swap
BONUSNAME = checker

CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3

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
			src/utils/ft_putstr_fd.c \
			src/utils/ft_split.c
		

	BONUSSRCS = bonus/checker.c \
				bonus/checker_functions.c \
				bonus/validation.c \
				bonus/utils/ft_atol.c \
				bonus/utils/ft_split.c \
				bonus/utils/ft_print_string.c \
				bonus/operations/push.c \
				bonus/operations/rotate.c \
				bonus/operations/reverse_rotate.c \
				bonus/operations/swap.c \
				bonus/get_next_line/get_next_line.c \
				bonus/get_next_line/get_next_line_utils.c 

OBJS = $(SRCS:.c=.o)
BONUSOBJS = $(BONUSSRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

bonus: $(BONUSOBJS)
	$(CC) $(CFLAGS) $(BONUSOBJS) -o $(BONUSNAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(BONUSOBJS)

fclean: clean
	rm -f $(NAME) $(BONUSNAME)

re: fclean all

rebonus: fclean bonus
