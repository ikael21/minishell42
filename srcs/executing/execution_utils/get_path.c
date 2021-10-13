/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikael <ikael@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 14:43:23 by ikael             #+#    #+#             */
/*   Updated: 2021/10/11 16:20:10 by ikael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_path(t_shell *shell, char *bin_name)
{
	char	*path;
	char	*temp;
	char	**dirs;

	temp = (char *)ft_getenv(shell->env_head, "PATH");
	if (temp == NULL)
		return (NULL);
	dirs = ft_split(temp, ':');
	if (dirs == NULL)
		exit(EXIT_FAILURE);
	path = get_needed_dir(shell, dirs, bin_name);
	free_str_array(dirs);
	if (path == NULL)
		return (NULL);
	temp = ft_strjoin(path, "/");
	free(path);
	if (temp == NULL)
		exit(EXIT_FAILURE);
	path = ft_strjoin(temp, bin_name);
	free(temp);
	if (path == NULL)
		exit(EXIT_FAILURE);
	return (path);
}
