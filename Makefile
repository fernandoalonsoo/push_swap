
NAME = push_swap.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS =		src/push_swap \
			src/initialise_stacks.c \
			src/utils/ft_atoi.c \
			src/utils/ft_print_char.c \
			src/utils/ft_print_number.c \
			src/utils/ft_print_string.c \


BONUSSRCS = 


OBJS = $(SRCS:.c=.o)
BONUSOBJS = $(BONUSSRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

bonus: $(OBJS) $(BONUSOBJS)
	ar rcs $(NAME) $(OBJS) $(BONUSOBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(BONUSOBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

rebonus: fclean bonus
