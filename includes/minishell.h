/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikael <ikael@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 17:00:51 by ikael             #+#    #+#             */
/*   Updated: 2021/10/13 20:32:52 by ikael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <signal.h>
# include <dirent.h>
# include <sys/errno.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sysexits.h>
# include "readline/readline.h"
# include "readline/history.h"
# include "libft.h"
# include "errors.h"

# define BUILTIN_FUNC_NUM	7
# define MAXDIR				1024

// colors for beauty
# define MAGENTA	"\033[35;1m"
# define YELLOW		"\033[33;1m"
# define RESET		"\033[0m"
# define RED		"\033[31;1m"
# define GREEN		"\033[32;1m"

/* *************************************** */
/* macros for setting up flag for a token  */
/* *************************************** */
# define READ_FILE			1
# define WRITE_FILE			2
# define DELIMITER			3
# define WRITE_APPEND_FILE	4
# define ARG				5

/* ********************************* */
/* macros for setting up flag field  */
/* in struct s_environ (t_environ)   */
/* ********************************* */
# define ONLY_NAME	0
# define HAS_VALUE	1

/* ************************************* */
/*  global variable to save the last     */
/*  executed child process' return value */
/* ************************************* */
typedef struct s_global
{
	int	g_exit_status;
	int	g_ctrl_c;
}	t_global;

t_global			g_global;

/* ********************************************* */
/*  struct that represents one element           */
/*  in the list of env. var. (t_list *env_head)  */
/* ********************************************* */
typedef struct s_environ
{
	char	*name;
	char	*value;
	int8_t	flag;
}	t_environ;

/* ************************************* */
/* struct for saving token after parsing */
/* ************************************* */
typedef struct s_token
{
	char	*token;
	int8_t	flag;
}	t_token;

/* ******************************** */
/* prototype for a function pointer */
/* ******************************** */
typedef void		(*t_func_ptr)(char **argv, t_list **env_head);
typedef t_func_ptr	t_function_ptr;

/* ********************************** */
/* struct to connect all the built_in */
/* functions with their names given   */
/* as names in command string         */
/* ********************************** */
typedef struct s_built_in
{
	const char		*name;
	t_function_ptr	func_ptr;
}	t_built_in;

/* ********************************** */
/* struct for the case when a command */
/* takes input from current source    */
/* ********************************** */
typedef struct s_delimiter
{
	pid_t	del_pid;
	int		del_fd[2];
}	t_delimiter;

// комментарии позже
typedef struct s_childs
{
	pid_t	*pid;
	int		size;
}	t_childs;

/* ******************************** */
/*  main struct that includes all   */
/*  the needed data                 */
/* ******************************** */
typedef struct s_shell
{
	int8_t			is_current_input;
	char			*rd_buffer;
	int				**fd;
	int				write_fd;
	int				read_fd;
	int8_t			next_token_flag;
	DIR				*dir_ptr;
	struct dirent	*dirent;
	t_childs		childs;
	t_delimiter		delimiter;
	t_list			*env_head;
	t_list			*argv_head;
	t_built_in		built_in[BUILTIN_FUNC_NUM];
}	t_shell;

void			minishell(char **env);
void			execute_commands(t_shell *shell);
int				open_files(t_shell *shell, t_list *args_head);
int				init_pipes(t_shell *shell);
char			*get_path(t_shell *shell, char *bin_name);
void			close_pipes(int **fd, int size);
void			change_in_out(t_shell *shell, int pos, char *bin_name);
void			execute_built_in(t_shell *shell,
					char **argv,
					int pos);
int				setup_delimiter(t_shell *shell);
void			execute_external_cmd(t_shell *shell,
					char **argv, int pos, int *j);
int				get_pid_size(t_shell *shell);
pid_t			*init_pid(int size);

/*  built_in commands  */
void			init_built_in(t_shell *shell);
void			ft_echo(char **argv, t_list **env_head);
void			ft_cd(char **argv, t_list **env_head);
void			ft_exit(char **argv, t_list **env_head);
void			ft_env(char **argv, t_list **env_head);
void			ft_pwd(char **argv, t_list **env_head);
void			ft_export(char **argv, t_list **env_head);
void			ft_unset(char **argv, t_list **env_head);

/*  PARSING  */
void			parsing(char *cmd, t_shell *shell);
int				preparser(char *cmd);
char			*parse_single_quotes(char *cmd, int *pos1, t_shell *shell);
char			*parse_double_quotes(char *cmd, int *pos1, t_shell *shell);
char			*parse_dollar(char *cmd, int *pos1, t_list *env_head);
char			*save_token(char *cmd, int *pos1, t_shell *shell);
char			*parse_pipe(char *cmd, int *pos1, t_shell *shell);
char			*parse_redir(char *cmd, int *pos1, t_shell *shell);

/*  UTILS  */
int				init_pid_and_pipes(t_shell *shell);
void			free_fd_array(int **fd, int size);
void			get_copy_env(t_list **env_head, char **env);
char			**split_into_three_parts(char *str, int pos1, int pos2);
char			**split_into_two_parts(char *str, int pos1, int pos2);
char			*merge_strings(char *str1, char *str2, char *str3);
int				search_env_name(char *cmd, int pos1);
char			*search_env_value(t_list *env_head, char *name);
char			**convert_args(t_list *argv_head);
char			**convert_env(t_list *env_head);
const char		*ft_getenv(t_list *env_head, char *name);
void			free_str_array(char **str_array);
void			ft_lstclear_super(t_list **argv_head);
int				is_slash(char *path);
t_function_ptr	is_built_in(char *cmd, t_built_in *built_in);
char			*get_needed_dir(t_shell *shell,
					char **dirs,
					char *bin_name);
int				get_count_strings(char **strings);
t_list			*sort_env(t_list *env_head);
void			add_change_env(t_list *argvList, t_list **env_head);
void			clear_t_list(t_list *list);
void			error_occured(const char *the_reason, char *error_message);
t_environ		*malloc_environ(void);
void			change_pwd(t_list *env_head);
int				handle_signals(t_shell *shell, char *str);
int				check_name(const char *name);
void			release_fds_argv(t_shell *shell, char **argv);

/*  SIGNAL  */
void			ctrl_c(int sign);
void			ctrl_d(void);
void			signal_handling(void);
int				event(void);

#endif
