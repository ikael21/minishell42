/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_in_out.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikael <ikael@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 19:54:53 by ikael             #+#    #+#             */
/*   Updated: 2021/10/11 15:19:49 by ikael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	in_from_file_or_pipe(t_shell *shell, int pos, char *bin_name)
{
	int	ret;

	if (shell->read_fd != -1 && shell->is_current_input != DELIMITER)
		ret = dup2(shell->read_fd, STDIN_FILENO);
	if (pos && shell->read_fd == -1 && shell->is_current_input != DELIMITER)
		ret = dup2(shell->fd[pos - 1][0], STDIN_FILENO);
	if (shell->is_current_input == DELIMITER)
	{
		ret = dup2(shell->delimiter.del_fd[0], STDIN_FILENO);
		close(shell->delimiter.del_fd[0]);
	}
	if (ret == -1)
	{
		perror(bin_name);
		if (is_built_in(bin_name, shell->built_in) == NULL)
			exit(EXIT_FAILURE);
	}
}

static void	out_to_file_or_pipe(t_shell *shell, int pos, char *bin_name)
{
	int	ret;

	if (shell->write_fd != -1)
		ret = dup2(shell->write_fd, STDOUT_FILENO);
	if (pos < ft_lstsize(shell->argv_head) - 1 && shell->write_fd == -1)
		ret = dup2(shell->fd[pos][1], STDOUT_FILENO);
	if (ret == -1)
	{
		perror(bin_name);
		if (is_built_in(bin_name, shell->built_in) == NULL)
			exit(EXIT_FAILURE);
	}
}

static void	apply_heredoc(t_shell *shell)
{
	if (pipe(shell->delimiter.del_fd) == -1)
	{
		error_occured("pipe", NULL);
		return ;
	}
	shell->delimiter.del_pid = fork();
	if (shell->delimiter.del_pid == -1)
		error_occured("fork", NULL);
	if (shell->delimiter.del_pid == 0)
	{
		close(shell->delimiter.del_fd[0]);
		write(shell->delimiter.del_fd[1],
			shell->rd_buffer, ft_strlen(shell->rd_buffer));
		close(shell->delimiter.del_fd[1]);
		exit(EXIT_SUCCESS);
	}
	close(shell->delimiter.del_fd[1]);
}

void	change_in_out(t_shell *shell, int pos, char	*bin_name)
{
	out_to_file_or_pipe(shell, pos, bin_name);
	if (shell->is_current_input == DELIMITER)
		apply_heredoc(shell);
	in_from_file_or_pipe(shell, pos, bin_name);
}
