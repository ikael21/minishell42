/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_pwd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjerrica <mjerrica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 14:06:57 by mjerrica          #+#    #+#             */
/*   Updated: 2021/10/08 14:19:29 by mjerrica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_list	*get_pwd(t_list *env_head)
{
	while (env_head)
	{
		if (ft_strcmp(((t_environ *)env_head->content)->name, "PWD") == 0)
			return (env_head);
		env_head = env_head->next;
	}
	return (NULL);
}

void	change_pwd(t_list *env_head)
{
	t_list	*pwd;
	char	directory[MAXDIR];

	if (!getcwd(directory, MAXDIR))
		exit(EXIT_FAILURE);
	pwd = get_pwd(env_head);
	if (pwd)
	{
		free(((t_environ *)pwd->content)->value);
		((t_environ *)pwd->content)->value = ft_strdup(directory);
	}
}
