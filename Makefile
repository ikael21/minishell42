NAME = minishell

MAIN = srcs/main.c

LIBFT = srcs/libft/libft.a

#colors for beauty
YELLOW =	\033[33;1m
RESET =		\033[0m
RED =		\033[31;1m
GREEN =		\033[32;1m
MAGENTA =	\033[35;1m

SRCS =	srcs/built_in/ft_echo.c								srcs/built_in/ft_pwd.c\
		srcs/built_in/ft_exit.c								srcs/parsing/preparsing.c\
		srcs/parsing/parsing.c								srcs/utils/get_copy_env.c\
		srcs/utils/strings_utils.c							srcs/utils/parse_dollar_utils.c\
		srcs/parsing/parse_double_quotes.c					srcs/parsing/parse_single_quotes.c\
		srcs/parsing/parse_dollar.c							srcs/parsing/save_token.c\
		srcs/executing/execute_commands.c					srcs/utils/convert_args.c\
		srcs/utils/convert_env.c							srcs/utils/ft_getenv.c\
		srcs/utils/free_str_array.c							srcs/utils/clear_argv_list.c\
		srcs/parsing/parse_pipe.c							srcs/parsing/parse_redir.c\
		srcs/executing/open_files.c							srcs/executing/execution_utils/get_path.c\
		srcs/built_in/ft_cd.c								srcs/built_in/ft_env.c\
		srcs/utils/get_count_strings.c						srcs/built_in/ft_export.c\
		srcs/executing/close_pipes.c						srcs/executing/change_in_out.c\
		srcs/utils/sort_env.c								srcs/utils/add_change_env.c\
		srcs/executing/execute_built_in.c					srcs/utils/change_pwd.c\
		srcs/executing/execute_external_cmd.c				srcs/executing/execution_utils/is_slash.c\
		srcs/executing/execution_utils/is_built_in.c		srcs/executing/execution_utils/get_needed_dir.c\
		srcs/executing/execution_utils/init_pipes.c			srcs/built_in/ft_unset.c\
		srcs/utils/clear_t_list.c							srcs/signal/ctrl_c.c\
		srcs/signal/ctrl_d.c								srcs/utils/error_occured.c\
		srcs/utils/malloc_environ.c							srcs/executing/execution_utils/init_pid.c\
		srcs/executing/execution_utils/get_pid_size.c		srcs/executing/execution_utils/handle_signals.c\
		srcs/signal/event.c									srcs/utils/check_name.c\
		srcs/utils/init_built_in.c							srcs/utils/minishell.c\
		srcs/executing/execution_utils/release_fds_argv.c	srcs/executing/execution_utils/init_pid_pipes.c

OBJS_DIR = objs_and_dfiles

OBJS = $(patsubst %.c,$(OBJS_DIR)/%.o, $(SRCS))
D_FILES = $(patsubst %.c,$(OBJS_DIR)/%.d, $(SRCS))

FLAGS = -Wall -Wextra -Werror

READLINE_FLAGS = -L/Users/$(USER)/.brew/Cellar/readline/8.1.1/lib/ -lreadline

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS_DIR) $(OBJS) $(MAIN)
	@gcc $(FLAGS) -Iincludes -o $(NAME) $(MAIN) $(OBJS) $(LIBFT) $(READLINE_FLAGS)
	@echo "$(MAGENTA)$(NAME)$(RESET) $(GREEN)COMPILED!$(RESET)"

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)
	@mkdir -p $(OBJS_DIR)/srcs
	@mkdir -p $(OBJS_DIR)/srcs/built_in
	@mkdir -p $(OBJS_DIR)/srcs/parsing
	@mkdir -p $(OBJS_DIR)/srcs/utils
	@mkdir -p $(OBJS_DIR)/srcs/executing
	@mkdir -p $(OBJS_DIR)/srcs/executing/execution_utils
	@mkdir -p $(OBJS_DIR)/srcs/signal

$(LIBFT):
	@make -C srcs/libft

$(OBJS_DIR)/%.o:%.c
	@gcc $(FLAGS) -Iincludes -c $< -o $@ -MD

include $(wildcard $(D_FILES))

clean:
	@rm -rf $(OBJS_DIR)
	@make fclean -C srcs/libft
	@echo "$(YELLOW)OBJS D-FILES$(RESET) $(RED)DELETED$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(MAGENTA)$(NAME)$(RESET) $(RED)DELETED$(RESET)"

re: fclean all
