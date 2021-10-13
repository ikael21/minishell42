/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikael <ikael@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 17:34:15 by ikael             #+#    #+#             */
/*   Updated: 2021/10/13 00:51:59 by ikael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;
	signal(SIGINT, ctrl_c);
	signal(SIGQUIT, SIG_IGN);
	rl_event_hook = event;
	g_global.g_ctrl_c = 0;
	g_global.g_exit_status = 0;
	minishell(env);
}
