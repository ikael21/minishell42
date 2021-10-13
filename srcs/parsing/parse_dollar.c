/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_dollar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikael <ikael@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 17:34:15 by ikael             #+#    #+#             */
/*   Updated: 2021/10/12 22:13:09 by ikael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*get_final_string(char *cmd, char *value,
							int *pos1, int pos2)
{
	char	**two_parts;
	char	*temp;

	two_parts = split_into_two_parts(cmd, *pos1, pos2);
	*pos1 = *pos1 + ft_strlen(value);
	temp = merge_strings(two_parts[0], value, two_parts[1]);
	free(two_parts);
	return (temp);
}

char	*parse_dollar(char *cmd, int *pos1, t_list *env_head)
{
	char	*temp1;
	char	*temp2;
	int		pos2;

	if (cmd[*pos1 + 1] == '?')
	{
		temp2 = ft_itoa(g_global.g_exit_status);
		if (temp2 == NULL)
			exit(EXIT_FAILURE);
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
		temp2 = search_env_value(env_head, temp1);
		free(temp1);
	}
	return (get_final_string(cmd, temp2, pos1, pos2));
}
