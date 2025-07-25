NAME = push_swap
CC = cc
CFLAGS = -Wall -Werror -Wextra -I./includes/
RM = rm -f

SRCS = srcs/push_swap.c srcs/logic.c srcs/parsing.c srcs/utils.c \
		srcs/operations.c srcs/stack_utils.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	$(CC) $(CFLAGS) $(OBJS) -L./libft -lft -o $(NAME)

clean:
	$(MAKE) -C ./libft clean
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) -C ./libft fclean
	$(RM) $(NAME)

re: 
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re