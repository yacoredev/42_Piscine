NAME = rush-02

SRCS = srcs/main.c \
       srcs/validation.c \
       srcs/file.c \
       srcs/parse.c \
       srcs/dictionary.c \
       srcs/lookup.c \
       srcs/convert.c \
       srcs/join.c \
       srcs/free.c

OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
