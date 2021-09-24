/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikael <ikael@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 17:34:15 by ikael             #+#    #+#             */
/*   Updated: 2021/09/23 22:57:32 by ikael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*what_to_parse(char *cmd, int *pos1, t_shell *shell)
{
	if (cmd[*pos1] == '$')
		return (parse_dollar(cmd, pos1, shell->env_head));
	if (cmd[*pos1] == '\'')
		return (parse_single_quotes(cmd, pos1));
	if (cmd[*pos1] == '"')
		return (parse_double_quotes(cmd, pos1, shell));
	if (cmd[*pos1] == '|')
		return (parse_pipe(cmd, pos1, shell));
	return (parse_redir(cmd, pos1, shell));
}

void	parsing(char *cmd, t_shell *shell)
{
	t_list	*lala;
	t_list	*baba;

	t_token	*tok;
	char	*temp;
	int		i;

	i = 0;
	while (cmd[i])
	{
		if (cmd[i] == ' ')
		{
			temp = save_token(cmd, &i, shell), free(cmd);
			cmd = temp;
		}
		else if (cmd[i] == '$' || cmd[i] == '\''
			|| cmd[i] == '"' || cmd[i] == '|'
			|| cmd[i] == '>' || cmd[i] == '<')
		{
			temp = what_to_parse(cmd, &i, shell), free(cmd);
			cmd = temp;
		}
		else
			i++;
	}
	temp = save_token(cmd, &i, shell);
	free(cmd), free(temp);


	// вывод для проверки
	lala = shell->argv_head;
	i = 1;
	while (lala)
	{
		printf("\033[33;1m----------------------------------------------\033[0m\n");
		printf("                     \033[35;1mITEM \033[32;1m#%d\033[0m\n", i);
		baba = (t_list *)lala->content;
		while (baba)
		{
			tok = (t_token *)baba->content;
			if (tok->flag == ARG)
				printf("ARG: %s\n", tok->token);
			else if (tok->flag == R_IN_FILE)
				printf("R_IN_FILE: %s\n", tok->token);
			else if (tok->flag == R_OUT_FILE)
				printf("R_OUT_FILE: %s\n", tok->token);
			else if (tok->flag == DELIMITER)
				printf("DELIMITER: %s\n", tok->token);
			else
				printf("R_APPEND_IN_FILE: %s\n", tok->token);
			baba = baba->next;
		}
		lala = lala->next;
		i++;
	}
}
