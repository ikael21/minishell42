/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_dollar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikael <ikael@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 17:34:15 by ikael             #+#    #+#             */
/*   Updated: 2021/09/24 01:21:35 by ikael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*parse_dollar(char *cmd, int *pos1, t_list *env_head)
{
	char	*temp1;
	char	**two_parts;
	char	*temp2;
	int		pos2;

	if (cmd[*pos1 + 1] == '?')
	{
		temp2 = ft_itoa(g_exit_status);
		pos2 = *pos1 + 2;
	}
	else
	{
		pos2 = search_env_name(cmd, *pos1);
		if (pos2 == *pos1 + 1)
			temp1 = ft_strdup("$");
		else
			temp1 = ft_substr(cmd, *pos1 + 1, pos2 - *pos1 - 1);
		if (temp1 == NULL)
			exit(EXIT_FAILURE);
		temp2 = search_env_value(env_head, temp1), free(temp1);
	}
	two_parts = split_into_two_parts(cmd, *pos1, pos2);
	*pos1 = *pos1 + ft_strlen(temp2);
	temp1 = merge_strings(two_parts[0], temp2, two_parts[1]), free(two_parts);
	return (temp1);
}
