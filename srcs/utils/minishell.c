/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikael <ikael@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 00:50:46 by ikael             #+#    #+#             */
/*   Updated: 2021/10/13 00:54:52 by ikael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	clear_some_shit(char *cmd, t_list **argv_head)
{
	free(cmd);
	ft_lstclear(argv_head, free);
}

static void	main_init_shell(t_shell *shell, char **env)
{
	shell->env_head = NULL;
	get_copy_env(&shell->env_head, env);
	init_built_in(shell);
}

static void	init_shell(t_shell *shell)
{
	t_list	*new;

	shell->argv_head = NULL;
	new = ft_lstnew(NULL);
	if (new == NULL)
		exit(EXIT_FAILURE);
	ft_lstadd_back(&shell->argv_head, new);
	shell->is_current_input = -1;
	shell->rd_buffer = NULL;
	shell->read_fd = -1;
	shell->write_fd = -1;
	shell->next_token_flag = ARG;
}

static int	here_we_go(t_shell *shell)
{
	char	*cmd;

	cmd = readline("BourneAgainSHell$ ");
	if (cmd == NULL)
		ctrl_d();
	if (g_global.g_ctrl_c == 1)
	{
		g_global.g_ctrl_c = 0;
		clear_some_shit(cmd, &shell->argv_head);
		return (2);
	}
	if (ft_strcmp(cmd, ""))
		add_history(cmd);
	if (preparser(cmd) == -1 || preparser(cmd) == 2)
	{
		if (preparser(cmd) == -1)
			error_occured("parser", SYNTAX_ERROR);
		clear_some_shit(cmd, &shell->argv_head);
		return (2);
	}
	parsing(cmd, shell);
	execute_commands(shell);
	ft_lstclear_super(&shell->argv_head);
	return (0);
}

void	minishell(char **env)
{
	t_shell		shell;

	main_init_shell(&shell, env);
	while (1)
	{
		init_shell(&shell);
		if (here_we_go(&shell))
			continue ;
	}
}
