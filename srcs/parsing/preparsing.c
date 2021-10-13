/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikael <ikael@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 17:34:15 by ikael             #+#    #+#             */
/*   Updated: 2021/10/12 15:45:50 by ikael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*check_quotes(char *cmd)
{
	char	which_quote;
	size_t	i;

	i = 1;
	which_quote = *cmd;
	while (cmd[i] && cmd[i] != which_quote)
		i++;
	if (cmd[i] == '\0')
		return (NULL);
	return (cmd + i + 1);
}

static int	check_backslash_pipe(char *cmd)
{
	size_t	i;
	char	sym;

	sym = cmd[0];
	if (sym == '|')
	{
		i = 0;
		while (cmd[i] && cmd[i] == sym)
			i++;
		if (i > 1)
			return (-1);
	}
	i = 1;
	while (cmd[i] && ((cmd[i] >= 9
				&& cmd[i] <= 13) || cmd[i] == ' '))
		i++;
	if (cmd[i] == '\0')
		return (-1);
	return (0);
}

static int	check_arrows(char *cmd)
{
	size_t	i;
	char	sym;

	sym = cmd[0];
	if ((cmd[0] == '>' && cmd[1] == '<')
		|| (cmd[0] == '<' && cmd[1] == '>'))
		return (-1);
	i = 0;
	while (cmd[i] && cmd[i] == sym)
		i++;
	if (i > 2)
		return (-1);
	i = 1;
	while (cmd[i] && ((cmd[i] >= 9
				&& cmd[i] <= 13) || cmd[i] == ' '))
		i++;
	if (cmd[i] == '\0' || cmd[i] == '|')
		return (-1);
	return (0);
}

static int	check_white_spaces(char *cmd)
{
	int	i;

	i = 0;
	while (cmd[i] && ((cmd[i] >= 9
				&& cmd[i] <= 13) || cmd[i] == ' '))
		i++;
	if (cmd[i] == '\0')
		return (-1);
	return (0);
}

int	preparser(char *cmd)
{
	char	*temp;

	temp = cmd;
	if (*temp == ';' || *temp == '|')
		return (-1);
	if (check_white_spaces(temp) == -1)
		return (2);
	while (*temp != '\0')
	{
		if (*temp == '\\' || *temp == '|')
			if (check_backslash_pipe(temp) == -1)
				return (-1);
		if (*temp == '>' || *temp == '<')
			if (check_arrows(temp) == -1)
				return (-1);
		if (*temp == '"' || *temp == '\'')
		{
			temp = check_quotes(temp);
			if (temp == NULL)
				return (-1);
		}
		else
			temp++;
	}
	return (0);
}
