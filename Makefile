CC = cc
CFLAGS = -Wall -Wextra -Werror  -g

NAME = minishell

SRC_DIR = src
SRC_FILES = main.c

OBJ_DIR = obj
OBJ_FILES = $(addprefix $(OBJ_DIR)/,$(SRC_FILES:.c=.o))


all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ_FILES)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ_FILES)

clean:
	@rm -fr obj

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re