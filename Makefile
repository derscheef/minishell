GREEN=\033[0;32m
YELLOW=\033[1;33m

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
INCLUDES = -lreadline

NAME = minishell

LEXER_DIR = lexer
LEXER_FILES = main.c destroy.c get_char_type.c \
tokens/init.c tokens/destroy.c \
states/general.c states/quote.c

ROUTINE_DIR = routine
ROUTINE_FILES = main.c exit.c

SIGNALS_DIR = signals
SIGNALS_FILES = main.c

UTILS_DIR = utils
UTILS_FILES = string/split.c string/skip_to_char.c string/rev_find_in_str.c \
string/skip_set.c string/skip_to_set.c \
debug/print_tokens.c \


SRC_DIR = src
SRC_FILES = main.c \
$(addprefix $(LEXER_DIR)/,$(LEXER_FILES)) \
$(addprefix $(ROUTINE_DIR)/,$(ROUTINE_FILES)) \
$(addprefix $(SIGNALS_DIR)/,$(SIGNALS_FILES)) \
$(addprefix $(UTILS_DIR)/,$(UTILS_FILES)) \

OBJ_DIR = obj
OBJ_FILES = $(addprefix $(OBJ_DIR)/,$(SRC_FILES:.c=.o))

INC_DIR = inc


all: $(OBJ_DIR) $(NAME)
	@echo "${GREEN}Compilation done"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@  -I $(INC_DIR)

$(NAME): $(OBJ_FILES)
	@$(MAKE) all bonus -C ./lib/libft
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ_FILES) $(INCLUDES) -L ./lib/libft -lft



clean:
	@$(MAKE) clean -C ./lib/libft
	@rm -fr obj
	@echo "${YELLOW}Finished cleaning objects"

fclean: clean
	@$(MAKE) fclean -C ./lib/libft
	@rm -f $(NAME)
	@echo "${YELLOW}Finished cleaning program"

re: fclean all

.PHONY: all clean fclean re