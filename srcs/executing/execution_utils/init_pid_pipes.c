/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pid_pipes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikael <ikael@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 19:03:48 by ikael             #+#    #+#             */
/*   Updated: 2021/10/13 19:04:06 by ikael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	init_pid_and_pipes(t_shell *shell)
{
	int	ret;

	shell->childs.size = get_pid_size(shell);
	shell->childs.pid = init_pid(shell->childs.size);
	ret = init_pipes(shell);
	if (ret)
	{
		error_occured("pipe", NULL);
		free(shell->childs.pid);
		close_pipes(shell->fd, ret);
		free_fd_array(shell->fd, ret + 1);
		return (-1);
	}
	return (0);
}
