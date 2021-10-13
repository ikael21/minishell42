/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_ctrl_c.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikael <ikael@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 15:14:34 by ikael             #+#    #+#             */
/*   Updated: 2021/10/13 01:56:51 by ikael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	handle_signals(t_shell *shell, char *str)
{
	if (g_global.g_ctrl_c == 1)
	{
		if (shell->rd_buffer)
		{
			free(shell->rd_buffer);
			shell->rd_buffer = NULL;
		}
		free(str);
		g_global.g_ctrl_c = 0;
		return (2);
	}
	shell->is_current_input = DELIMITER;
	return (0);
}
