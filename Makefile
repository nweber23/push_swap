NAME = push_swap
CC = cc
CFLAGS = -Wall -Werror -Wextra -I./includes/
RM = rm -f

SRCS = srcs/main.c srcs/logic.c srcs/parsing.c srcs/utils.c \
		srcs/operations.c srcs/stack_utils.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	cp ./libft/libft.a $(NAME)
	ar rcs $(NAME) $(OBJS)

clean:
	$(MAKE) -C ./libft clean
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) -C ./libft fclean
	$(RM) $(NAME)

re: $(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re