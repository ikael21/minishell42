/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikael <ikael@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 17:00:51 by ikael             #+#    #+#             */
/*   Updated: 2021/09/27 04:43:31 by ikael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <signal.h>
# include <dirent.h>
# include <sys/errno.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "libft.h"
# include "errors.h"

# define BUILTIN_FUNC_NUM	7

/* *************************************** */
/* macros for setting up flag for a token  */
/* *************************************** */
# define R_IN_FILE			1
# define R_OUT_FILE			2
# define DELIMITER			3
# define R_APPEND_IN_FILE	4
# define ARG				5

/* ********************************* */
/* macros for setting up flag field  */
/* in struct s_environ (t_environ)   */
/* ********************************* */
# define ONLY_NAME	0
# define HAS_VALUE	1

/* ********************************** */
/*  global variable to save the last  */
/*  executed program's return value   */
/* ********************************** */
int						g_exit_status;

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
typedef void			(*t_func_ptr)(void *);
typedef t_func_ptr		t_function_pointer;

/* ********************************** */
/* struct to connect all the built_in */
/* functions with their names given   */
/* as names in command string         */
/* ********************************** */
typedef struct s_built_in
{
	const char			*name;
	t_function_pointer	func_ptr;
}	t_built_in;

/* ******************************** */
/*  main struct that includes all   */
/*  the needed data                 */
/* ******************************** */
typedef struct s_shell
{
	int8_t			next_token_flag;
	DIR				*dir_ptr;
	struct dirent	*dirent;
	pid_t			pid;
	t_list			*env_head;
	t_list			*argv_head;
	t_built_in		built_in[BUILTIN_FUNC_NUM];
}	t_shell;

void		execute_command(t_shell *shell);

/*  built_in commands  */
void		ft_echo(const char *str, const int new_line);
void		ft_pwd(void);
void		ft_exit(void);

/*  PARSING  */
void		parsing(char *cmd, t_shell *shell);
int			preparser(char *cmd);
char		*parse_single_quotes(char *cmd, int *pos1);
char		*parse_double_quotes(char *cmd, int *pos1, t_shell *shell);
char		*parse_dollar(char *cmd, int *pos1, t_list *env_head);
char		*save_token(char *cmd, int *pos1, t_shell *shell);
char		*parse_pipe(char *cmd, int *pos1, t_shell *shell);
char		*parse_redir(char *cmd, int *pos1, t_shell *shell);

/*  UTILS  */
void		get_copy_env(t_list **env_head, char **env);
char		**split_into_three_parts(char *str, int pos1, int pos2);
char		**split_into_two_parts(char *str, int pos1, int pos2);
char		*merge_strings(char *str1, char *str2, char *str3);
int			search_env_name(char *cmd, int pos1);
char		*search_env_value(t_list *env_head, char *name);
char		**convert_args(t_list *argv_head);
char		**convert_env(t_list *env_head);
const char	*ft_getenv(t_list *env_head, char *name);
void		free_str_array(char **str_array);
void		ft_lstclear_super(t_list **argv_head);
int			is_slash(char *path);

#endif
