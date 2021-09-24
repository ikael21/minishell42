/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_single_quotes.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikael <ikael@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 17:34:15 by ikael             #+#    #+#             */
/*   Updated: 2021/09/18 17:43:38 by ikael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*parse_single_quotes(char *cmd, int *pos1)
{
	char	**three_parts;
	int		pos2;
	char	*tmp;

	pos2 = *pos1 + 1;
	while (cmd[pos2] && cmd[pos2] != '\'')
		pos2++;
	three_parts = split_into_three_parts(cmd, *pos1, pos2);
	tmp = merge_strings(three_parts[0],
			three_parts[1], three_parts[2]);
	free(three_parts), *pos1 = pos2 - 1;
	return (tmp);
}
