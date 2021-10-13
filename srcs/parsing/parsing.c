/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikael <ikael@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 17:34:15 by ikael             #+#    #+#             */
/*   Updated: 2021/10/12 19:22:27 by ikael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*what_to_parse(char *cmd, int *pos1, t_shell *shell)
{
	if (cmd[*pos1] == '$')
		return (parse_dollar(cmd, pos1, shell->env_head));
	if (cmd[*pos1] == '\'')
		return (parse_single_quotes(cmd, pos1, shell));
	if (cmd[*pos1] == '"')
		return (parse_double_quotes(cmd, pos1, shell));
	if (cmd[*pos1] == '|')
		return (parse_pipe(cmd, pos1, shell));
	return (parse_redir(cmd, pos1, shell));
}

static char	*put_token(t_shell *shell, char *cmd, int *pos)
{
	char	*temp;

	temp = save_token(cmd, pos, shell);
	free(cmd);
	return (temp);
}

void	parsing(char *cmd, t_shell *shell)
{
	char	*temp;
	int		i;

	i = 0;
	temp = NULL;
	while (cmd[i])
	{
		if (cmd[i] == ' ')
			cmd = put_token(shell, cmd, &i);
		else if (cmd[i] == '$' || cmd[i] == '\'' || cmd[i] == '"'
			|| cmd[i] == '|' || cmd[i] == '>' || cmd[i] == '<')
		{
			temp = what_to_parse(cmd, &i, shell);
			free(cmd);
			cmd = temp;
		}
		else
			i++;
	}
	if (ft_strcmp(cmd, ""))
		cmd = put_token(shell, cmd, &i);
	free(cmd);
}
