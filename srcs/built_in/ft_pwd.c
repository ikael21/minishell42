/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikael <ikael@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 12:46:04 by mjerrica          #+#    #+#             */
/*   Updated: 2021/10/13 20:06:22 by ikael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_pwd(char **argv, t_list **env_head)
{
	char	directory[MAXDIR];

	(void)argv;
	(void)env_head;
	if (getcwd(directory, MAXDIR))
	{
		ft_putendl_fd(directory, STDOUT_FILENO);
		g_global.g_exit_status = 0;
	}
	else
		g_global.g_exit_status = 1;
}
