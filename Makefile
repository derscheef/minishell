GREEN=\033[0;32m
YELLOW=\033[1;33m
NC=\033[0m

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
INCLUDES = -L /opt/homebrew/opt/readline/lib -lft -lreadline -lncurses

NAME = minishell

LEXER_DIR = lexer
LEXER_FILES = main.c destroy.c get_char_type.c \
tokens/init.c tokens/destroy.c \
states/general.c states/quote.c

PARSER_DIR = parser
PARSER_FILES = main.c \
job/main.c job/job1.c \
cmd/main.c cmd/cmd1.c cmd/cmd2.c cmd/simple_cmd.c \
tokenlist/main.c

ROUTINE_DIR = routine
ROUTINE_FILES = main.c

SIGNALS_DIR = signals
SIGNALS_FILES = main.c

UTILS_DIR = utils
UTILS_FILES = ft_putchar.c ft_putstr.c split.c \
debug/print_tokens.c \
nodes/new.c nodes/destroy.c nodes/attach.c

EXECUTER_DIR = executer
EXECUTER_FILES = main.c

EXECUTOR_DIR = executor
EXECUTOR_FILES = main.c cmd.c job.c pipe.c \
cmd/exec_external.c cmd/exec_internal.c cmd/exec_builtin.c cmd/simple_cmd.c \

BUILTINS_DIR = builtins
BUILTINS_FILES = clear.c exit.c env.c pwd.c echo.c

ENV_DIR = env
ENV_FILES = init.c print.c

SRC_DIR = src
SRC_FILES = main.c \
$(addprefix $(LEXER_DIR)/,$(LEXER_FILES)) \
$(addprefix $(PARSER_DIR)/,$(PARSER_FILES)) \
$(addprefix $(ROUTINE_DIR)/,$(ROUTINE_FILES)) \
$(addprefix $(SIGNALS_DIR)/,$(SIGNALS_FILES)) \
$(addprefix $(UTILS_DIR)/,$(UTILS_FILES)) \
$(addprefix $(EXECUTER_DIR)/,$(EXECUTER_FILES)) \
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
