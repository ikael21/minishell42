/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_built_in.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikael <ikael@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 10:25:35 by ikael             #+#    #+#             */
/*   Updated: 2021/10/12 22:15:06 by ikael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute_built_in(t_shell *shell,
						char **argv, int pos)
{
	t_function_ptr	built_in_ptr;
	int				read_fd_temp;
	int				write_fd_temp;

	read_fd_temp = dup(STDIN_FILENO);
	write_fd_temp = dup(STDOUT_FILENO);
	if (read_fd_temp == -1 || write_fd_temp == -1)
		return (error_occured("dup", NULL));
	built_in_ptr = is_built_in(argv[0], shell->built_in);
	change_in_out(shell, pos, argv[0]);
	if (shell->is_current_input == DELIMITER)
		waitpid(shell->delimiter.del_pid, NULL, 0);
	built_in_ptr(argv, &shell->env_head);
	if (dup2(write_fd_temp, STDOUT_FILENO) == -1
		|| dup2(read_fd_temp, STDIN_FILENO) == -1)
		return (error_occured("dup2", NULL));
	close(read_fd_temp);
	close(write_fd_temp);
}
