/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikael <ikael@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 17:48:24 by ikael             #+#    #+#             */
/*   Updated: 2021/09/22 22:49:16 by ikael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_slash(char *path)
{
	int	i;

	i = -1;
	while (path[++i])
		if (path[i] == '/')
			return (0);
	return (-1);
}

static char	*get_needed_dir(t_shell *shell, char **def_paths, char *bin_name)
{
	int		i;
	char	*path;

	i = -1;
	while (def_paths[++i])
	{
		shell->dir_ptr = opendir(def_paths[i]);
		if (shell->dir_ptr == NULL)
			continue ;
		while (1)
		{
			shell->dirent = readdir(shell->dir_ptr);
			if (shell->dirent == NULL)
				break ;
			if (ft_strcmp(shell->dirent->d_name, bin_name) == 0)
			{
				path = ft_strdup(def_paths[i]);
				if (path == NULL)
					exit(EXIT_FAILURE);
				if (closedir(shell->dir_ptr) != 0)
					exit(EXIT_FAILURE);
				return (path);
			}
		}
		if (closedir(shell->dir_ptr) != 0)
			exit(EXIT_FAILURE);
	}
	return (NULL);
}

static char	*get_path(t_shell *shell, char *bin_name)
{
	char	**def_paths;
	char	*path;
	char	*temp;

	def_paths = ft_split(ft_getenv(shell->env_head, "PATH"), ':');
	if (def_paths == NULL)
		exit(EXIT_FAILURE);
	path = get_needed_dir(shell, def_paths, bin_name);
	free_str_array(def_paths);
	if (path == NULL)
		return (path);
	temp = ft_strjoin(path, "/"), free(path);
	if (temp == NULL)
		exit(EXIT_FAILURE);
	path = ft_strjoin(temp, bin_name), free(temp);
	if (path == NULL)
		exit(EXIT_FAILURE);
	return (path);
}

static void	execution(char *path_to_dir, char **argv, char **env)
{
	execve(path_to_dir, argv, env);
	ft_putstr_fd("minishell: command not found\n", STDERR_FILENO);
	exit(EXIT_FAILURE);
}

//	пока не учитываю встроенные команды (pwd, echo, env, export, ...)
void	execute_command(t_shell *shell)
{
	char	**argv;
	char	**env;
	char	*path;

	argv = convert_args((t_list *)shell->argv_head->content);
	env = convert_env(shell->env_head);
	if (is_slash(argv[0]) == -1)
		path = get_path(shell, argv[0]);
	else
		path = ft_strdup(argv[0]);
	if (path == NULL)
		path = ft_strdup(argv[0]);
	shell->pid = fork();
	if (shell->pid == 0)
		execution(path, argv, env);
	shell->pid = waitpid(shell->pid, &g_exit_status, 0);
	if (shell->pid == -1)
		perror("minishell");
	free(path);
	free_str_array(argv), free_str_array(env);
}
