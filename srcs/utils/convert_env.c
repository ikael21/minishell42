/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikael <ikael@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 02:04:13 by ikael             #+#    #+#             */
/*   Updated: 2021/10/09 23:30:19 by ikael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	get_actual_size(t_list *env_head)
{
	int	size;

	size = 0;
	while (env_head)
	{
		if (((t_environ *)env_head->content)->value)
			size++;
		env_head = env_head->next;
	}
	return (size);
}

char	**convert_env(t_list *env_head)
{
	char		**env;
	char		*temp;
	int			i;

	env = (char **)malloc(sizeof(char *) * (get_actual_size(env_head) + 1));
	if (env == NULL)
		exit(EXIT_FAILURE);
	i = 0;
	while (env_head)
	{
		if (((t_environ *)env_head->content)->value)
		{
			temp = ft_strjoin(((t_environ *)env_head->content)->name, "=");
			if (temp == NULL)
				exit(EXIT_FAILURE);
			env[i] = ft_strjoin(temp, ((t_environ *)env_head->content)->value);
			free(temp);
			if (env[i] == NULL)
				exit(EXIT_FAILURE);
			i++;
		}
		env_head = env_head->next;
	}
	env[i] = NULL;
	return (env);
}
