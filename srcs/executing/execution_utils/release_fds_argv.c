/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   release_fds_argv.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikael <ikael@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 19:02:10 by ikael             #+#    #+#             */
/*   Updated: 2021/10/13 19:02:25 by ikael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	release_fds_argv(t_shell *shell, char **argv)
{
	close(shell->read_fd);
	close(shell->write_fd);
	shell->write_fd = -1;
	shell->read_fd = -1;
	if (argv[0])
		free_str_array(argv);
	else
		free(argv);
}
