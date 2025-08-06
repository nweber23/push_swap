NAME = push_swap
BONUS_NAME = checker
SRC = srcs/push_swap.c srcs/logic.c srcs/parsing.c srcs/utils.c srcs/operations.c srcs/stack_utils.c
BONUS_SRC = bonus_srcs/checker.c bonus_srcs/operations.c bonus_srcs/operations_utils.c bonus_srcs/parsing.c bonus_srcs/utils.c
OBJ_DIR = objs
BONUS_OBJ_DIR = bonus_objs
OBJ = $(SRC:srcs/%.c=$(OBJ_DIR)/%.o)
BONUS_OBJ = $(BONUS_SRC:bonus_srcs/%.c=$(BONUS_OBJ_DIR)/%.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror -I./includes/ -I./libft/includes/

# Library paths
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(LIBFT) $(NAME)

bonus: $(LIBFT) $(BONUS_NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(BONUS_NAME): $(BONUS_OBJ)
	$(CC) $(CFLAGS) $(BONUS_OBJ) $(LIBFT) -o $(BONUS_NAME)

$(OBJ_DIR)/%.o: srcs/%.c includes/*.h
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BONUS_OBJ_DIR)/%.o: bonus_srcs/%.c includes/*.h
	@mkdir -p $(BONUS_OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(MAKE) -C $(LIBFT_DIR)

clean:
	rm -rf $(OBJ_DIR)
	rm -rf $(BONUS_OBJ_DIR)
	$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	rm -f $(BONUS_NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all bonus clean fclean re