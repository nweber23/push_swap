NAME = push_swap
CC = CC
CFLAGS = -Wall -Werror -Wextra -I./includes/
RM = rm -f

SRCS = srcs/main.c srcs/logic.c srcs/parsing.c srcs/utils.c srcs/ops/rotate.c \
		srcs/ops/swap_push.c srcs/ops/reverse_rotate.c

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

re: fclean all

.PHONY: all clean fclean re