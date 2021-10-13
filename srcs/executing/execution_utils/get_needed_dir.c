/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_needed_dir.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikael <ikael@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 14:41:49 by ikael             #+#    #+#             */
/*   Updated: 2021/10/05 14:42:09 by ikael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_needed_dir(t_shell *shell,
						char **dirs,
						char *bin_name)
{
	int		i;
	char	*path;

	i = -1;
	while (dirs[++i])
	{
		shell->dir_ptr = opendir(dirs[i]);
		if (shell->dir_ptr == NULL)
			continue ;
		shell->dirent = readdir(shell->dir_ptr);
		while (shell->dirent)
		{
			if (ft_strcmp(shell->dirent->d_name, bin_name) == 0)
			{
				path = ft_strdup(dirs[i]);
				if (path == NULL)
					exit(EXIT_FAILURE);
				closedir(shell->dir_ptr);
				return (path);
			}
			shell->dirent = readdir(shell->dir_ptr);
		}
		closedir(shell->dir_ptr);
	}
	return (NULL);
}
