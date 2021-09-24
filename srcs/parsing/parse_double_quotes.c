/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_double_quotes.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikael <ikael@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 17:34:15 by ikael             #+#    #+#             */
/*   Updated: 2021/09/18 17:44:44 by ikael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*parse_double_quotes(char *cmd, int *pos1, t_shell *shell)
{
	char	**three_parts;
	char	*tmp;
	int		pos2;
	int		i;

	pos2 = *pos1 + 1;
	while (cmd[pos2] && cmd[pos2] != '"')
		pos2++;
	three_parts = split_into_three_parts(cmd, *pos1, pos2);
	i = 0;
	while (three_parts[1][i])
	{
		if (three_parts[1][i] == '$')
		{
			tmp = parse_dollar(three_parts[1], &i, shell->env_head);
			free(three_parts[1]), three_parts[1] = tmp;
		}
		else
			i++;
	}
	tmp = merge_strings(three_parts[0],
			three_parts[1], three_parts[2]);
	free(three_parts), *pos1 = pos2 - 1;
	return (tmp);
}
