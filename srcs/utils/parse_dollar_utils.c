/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_dollar_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikael <ikael@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 17:34:15 by ikael             #+#    #+#             */
/*   Updated: 2021/09/18 17:42:55 by ikael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	search_env_name(char *cmd, int pos1)
{
	int	pos2;

	pos2 = pos1 + 1;
	while (cmd[pos2] && ((cmd[pos2] >= 48 && cmd[pos2] <= 57)
			|| (cmd[pos2] >= 65 && cmd[pos2] <= 90)
			|| (cmd[pos2] >= 97 && cmd[pos2] <= 122) || cmd[pos2] == '_'))
	{
		if (pos2 == pos1 + 1 && (cmd[pos2] >= 48 && cmd[pos2] <= 57))
			return (pos2 + 1);
		pos2++;
	}
	return (pos2);
}

char	*search_env_value(t_list *env_head, char *name)
{
	t_environ	*env;
	char		*tmp;

	if (ft_strcmp(name, "$") == 0)
	{
		tmp = ft_strdup("$");
		if (tmp == NULL)
			exit(EXIT_FAILURE);
		return (tmp);
	}
	tmp = NULL;
	while (env_head)
	{
		env = (t_environ *)env_head->content;
		if (ft_strcmp(env->name, name) == 0)
			tmp = env->value;
		env_head = env_head->next;
	}
	if (tmp == NULL)
		tmp = ft_strdup("\0");
	else
		tmp = ft_strdup(tmp);
	if (tmp == NULL)
		exit(EXIT_FAILURE);
	return (tmp);
}
