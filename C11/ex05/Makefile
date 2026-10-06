NAME = do-op
HDR = includes

CC = cc
FLAGS = -Wall -Wextra -Werror -I $(HDR)

SRCS = srcs/do-op.c srcs/ft_atoi.c \
	srcs/ft_putchar.c srcs/ft_putnbr.c \
	srcs/ft_putstr.c srcs/init_fts.c \
	srcs/operators.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
