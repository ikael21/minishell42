/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikael <ikael@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 17:09:14 by ikael             #+#    #+#             */
/*   Updated: 2021/10/13 19:07:55 by ikael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	get_last_exit_status(int exit_status)
{
	if (exit_status == 0)
		g_global.g_exit_status = 0;
	else if (exit_status == 2 || exit_status == 3)
	{
		if (exit_status == 2)
			g_global.g_ctrl_c = 0;
		if (exit_status == 2)
			write(STDOUT_FILENO, "\n", 1);
		else
			write(STDOUT_FILENO, "Quit: 3\n", 8);
		g_global.g_exit_status = 128 + exit_status;
	}
	else
		g_global.g_exit_status = WEXITSTATUS(exit_status);
}

static void	clear_and_wait(t_shell *shell)
{
	int	i;
	int	exit_status;

	close_pipes(shell->fd, ft_lstsize(shell->argv_head) - 1);
	i = -1;
	while (++i < shell->childs.size)
		if (waitpid(shell->childs.pid[i], &exit_status, 0) != -1)
			get_last_exit_status(exit_status);
	free(shell->childs.pid);
	if (shell->rd_buffer)
		free(shell->rd_buffer);
	free_fd_array(shell->fd, ft_lstsize(shell->argv_head));
}

static void	start_commands(char **argv, int i, int *j, t_shell *shell)
{
	if (is_built_in(argv[0], shell->built_in))
		execute_built_in(shell, argv, i);
	else
		execute_external_cmd(shell, argv, i, j);
	shell->is_current_input = -1;
}

static void	init_iterators(int *i, int *j)
{
	*i = 0;
	*j = 0;
}

void	execute_commands(t_shell *shell)
{
	t_list	*temp;
	char	**argv;
	int		i;
	int		j;
	int		open_ret;

	if (init_pid_and_pipes(shell) == -1)
		return ;
	temp = shell->argv_head;
	init_iterators(&i, &j);
	while (temp)
	{
		open_ret = open_files(shell, (t_list *)temp->content);
		argv = convert_args((t_list *)temp->content);
		if (open_ret == 0 && argv[0])
			start_commands(argv, i, &j, shell);
		release_fds_argv(shell, argv);
		if (open_ret == 2)
			break ;
		if (open_ret == 1)
			g_global.g_exit_status = 1;
		temp = temp->next;
		i++;
	}
	clear_and_wait(shell);
}
