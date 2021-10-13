/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_external_cmd.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikael <ikael@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 14:19:29 by ikael             #+#    #+#             */
/*   Updated: 2021/10/13 16:44:53 by ikael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	print_error(char *bin_name)
{
	char	*str;

	(void)bin_name;
	str = strerror(errno);
	if (ft_strcmp(str, NO_FILE) == 0)
	{
		error_occured(bin_name, CMD_NOT_FOUND);
		return (127);
	}
	error_occured(bin_name, str);
	return (126);
}

static char	*path_to_bin(t_shell *shell, char **argv)
{
	char	*path;

	path = get_path(shell, argv[0]);
	if (path == NULL)
	{
		path = ft_strdup(argv[0]);
		if (path == NULL)
			exit(EXIT_FAILURE);
	}
	return (path);
}

void	execute_external_cmd(t_shell *shell,
							char **argv, int pos, int *j)
{
	char	**env;
	char	*path;

	env = convert_env(shell->env_head);
	path = path_to_bin(shell, argv);
	signal(SIGQUIT, SIG_DFL);
	shell->childs.pid[*j] = fork();
	if (shell->childs.pid[*j] == -1)
		error_occured("fork", NULL);
	if (shell->childs.pid[*j] == 0)
	{
		change_in_out(shell, pos, argv[0]);
		if (shell->is_current_input == DELIMITER)
			waitpid(shell->delimiter.del_pid, NULL, 0);
		close_pipes(shell->fd, ft_lstsize(shell->argv_head) - 1);
		execve(path, argv, env);
		exit(print_error(argv[0]));
	}
	signal(SIGQUIT, SIG_IGN);
	free_str_array(env);
	free(path);
	*j += 1;
}
