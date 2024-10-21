NAME = get_next_line

SRCS = 	get_next_line_main.c get_next_line.c get_next_line_utils.c

CC = gcc
CFLAGS = -Wall -Wextra -Werror

OBJS = $(SRCS:.c=.o)

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re:  fclean all

.PHONY: all clean fclean re