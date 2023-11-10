GREEN=\033[0;32m
YELLOW=\033[1;33m
NC=\033[0m

CC = cc
CFLAGS = -Wall -Werror -Wextra -g
INCLUDES = -L /opt/homebrew/opt/readline/lib -lft -lreadline -lncurses

NAME = minishell

LEXER_DIR = lexer
LEXER_FILES = main.c destroy.c get_char_type.c remove_quotes.c remove_empty_tokens.c \
tokens/init.c tokens/destroy.c tokens/combine_redirection.c \
states/general.c states/quote.c

PARSER_DIR = parser
PARSER_FILES = main.c destroy.c \
job/main.c job/job1.c \
cmd/main.c cmd/cmd1.c cmd/cmd2.c cmd/cmd3.c cmd/cmd4.c cmd/simple_cmd.c \
tokenlist/main.c

ROUTINE_DIR = routine
ROUTINE_FILES = main.c exit.c

SIGNALS_DIR = signals
SIGNALS_FILES = main.c

UTILS_DIR = utils
UTILS_FILES = ft_putchar.c ft_putstr.c split.c skip_to_set.c \
debug/print_tokens.c \
nodes/new.c nodes/destroy.c nodes/attach.c \
env/replace_env_var.c env/get_env_var.c env/modify_or_add_env_var.c \
dir/can_open_file.c


EXECUTOR_DIR = executor
EXECUTOR_FILES = main.c cmd.c fds.c job.c pipe.c \
cmd/exec_external.c cmd/check_command_type.c cmd/exec_builtin.c cmd/simple_cmd.c \
cmd/exec_external_helpers.c cmd/exec_external_helpers2.c \
heredoc/main.c \


BUILTINS_DIR = builtins
BUILTINS_FILES = clear.c exit.c env.c pwd.c echo.c export.c unset.c cd.c

ENV_DIR = env
ENV_FILES = init.c print.c main.c destroy.c

SRC_DIR = src
SRC_FILES = main.c \
$(addprefix $(LEXER_DIR)/,$(LEXER_FILES)) \
$(addprefix $(PARSER_DIR)/,$(PARSER_FILES)) \
$(addprefix $(ROUTINE_DIR)/,$(ROUTINE_FILES)) \
$(addprefix $(SIGNALS_DIR)/,$(SIGNALS_FILES)) \
$(addprefix $(UTILS_DIR)/,$(UTILS_FILES)) \
$(addprefix $(EXECUTOR_DIR)/,$(EXECUTOR_FILES)) \
$(addprefix $(BUILTINS_DIR)/,$(BUILTINS_FILES)) \
$(addprefix $(ENV_DIR)/,$(ENV_FILES))

OBJ_DIR = obj
OBJ_FILES = $(addprefix $(OBJ_DIR)/,$(SRC_FILES:.c=.o))

INC_DIR = inc

all: $(OBJ_DIR) $(NAME)
	@echo "${GREEN}Compilation done${NC}"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@echo "$(CC) $(CFLAGS) -c $< -o $@  -I $(INC_DIR) -I /opt/homebrew/opt/readline/include"
	@$(CC) $(CFLAGS) -c $< -o $@  -I $(INC_DIR) -I /opt/homebrew/opt/readline/include

$(NAME): $(OBJ_FILES)
	@$(MAKE) all bonus -C ./lib/libft
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ_FILES) -L ./lib/libft $(INCLUDES)

clean:
	@$(MAKE) clean -C ./lib/libft
	@rm -fr obj
	@echo "${YELLOW}Finished cleaning objects${NC}"

fclean: clean
	@$(MAKE) fclean -C ./lib/libft
	@rm -f $(NAME)
	@echo "${YELLOW}Finished cleaning program${NC}"

re: fclean all

.PHONY: all clean fclean re
