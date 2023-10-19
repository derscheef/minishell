CC = cc
CFLAGS = -Wall -Wextra -Werror  -g -v
INCLUDES = -lreadline

NAME = minishell


ROUTINE_DIR = routine
ROUTINE_FILES = main.c exit.c


SRC_DIR = src
SRC_FILES = main.c \
$(addprefix $(ROUTINE_DIR)/,$(ROUTINE_FILES)) \

OBJ_DIR = obj
OBJ_FILES = $(addprefix $(OBJ_DIR)/,$(SRC_FILES:.c=.o))

INC_DIR = inc


all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@  -I $(INC_DIR)

$(NAME): $(OBJ_FILES)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ_FILES) $(INCLUDES)

clean:
	@rm -fr obj

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re