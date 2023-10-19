CC = cc
CFLAGS = -Wall -Wextra -Werror -g
INCLUDES = -lreadline

NAME = minishell

LEXER_DIR = lexer
LEXER_FILES = main.c

ROUTINE_DIR = routine
ROUTINE_FILES = main.c exit.c

SIGNALS_DIR = signals
SIGNALS_FILES = main.c

UTILS_DIR = utils
UTILS_FILES = string/split.c


SRC_DIR = src
SRC_FILES = main.c \
$(addprefix $(ROUTINE_DIR)/,$(ROUTINE_FILES)) \

OBJ_DIR = obj
OBJ_FILES = $(addprefix $(OBJ_DIR)/,$(SRC_FILES:.c=.o))

INC_DIR = inc


all: $(OBJ_DIR) $(NAME)
	@echo "Compilation done"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@  -I $(INC_DIR)

$(NAME): $(OBJ_FILES)
	@$(MAKE) all bonus -C ./lib/libft
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ_FILES) $(INCLUDES)



clean:
	@$(MAKE) clean -C ./lib/libft
	@rm -fr obj
	@echo "Finished cleaning objects"

fclean: clean
	@$(MAKE) fclean -C ./lib/libft
	@rm -f $(NAME)
	@echo "Finished cleaning program"

re: fclean all

.PHONY: all clean fclean re