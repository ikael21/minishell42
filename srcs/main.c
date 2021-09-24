/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikael <ikael@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 17:34:15 by ikael             #+#    #+#             */
/*   Updated: 2021/09/23 07:45:46 by ikael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	init_shell(t_shell *shell, char **env)
{
	t_list	*new;

	shell->argv_head = NULL;
	new = ft_lstnew(NULL);
	if (new == NULL)
		exit(EXIT_FAILURE);
	ft_lstadd_back(&shell->argv_head, new);
	shell->env_head = NULL;
	get_copy_env(&shell->env_head, env);
	shell->next_token_flag = ARG;
}

static void	minishell(char **env)
{
	char		*cmd;
	t_shell		shell;

	init_shell(&shell, env);
	while (1)
	{
		cmd = readline("BourneAgainSHell$ ");
		if (cmd)
			add_history(cmd);
		if (preparser(cmd) == -1)
		{
			free(cmd);
			continue ;
		}
		parsing(cmd, &shell);
		//execute_command(&shell);
		ft_lstclear_super(&shell.argv_head);
	}
}

int	main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;
	g_exit_status = 0;
	minishell(env);
}
