/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_copy_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikael <ikael@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 17:34:15 by ikael             #+#    #+#             */
/*   Updated: 2021/09/18 17:42:50 by ikael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* ******************************************* */
/* first arg: list's head pointer              */
/* second arg: original env. array             */
/* the func. iterates through the array        */
/* and copies apart names and its varues into  */
/* the given list                              */
/* ******************************************* */

void	get_copy_env(t_list **env_head, char **env)
{
	t_environ	*item;
	t_list		*new;
	int			i;
	int			j;

	i = -1;
	while (env[++i])
	{
		item = (t_environ *)malloc(sizeof(t_environ));
		if (item == NULL)
			exit(EXIT_FAILURE);
		j = 0;
		while (env[i][j] && env[i][j] != '=')
			j++;
		item->name = ft_substr(env[i], 0, j);
		item->value = ft_substr(env[i], j + 1, ft_strlen(env[i]) - j - 1);
		if (item->name == NULL || item->value == NULL)
			exit(EXIT_FAILURE);
		item->flag = HAS_VALUE;
		new = ft_lstnew((void *)item);
		if (new == NULL)
			exit(EXIT_FAILURE);
		ft_lstadd_back(env_head, new);
	}
}
