/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_str_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikael <ikael@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 04:53:59 by ikael             #+#    #+#             */
/*   Updated: 2021/10/02 18:13:39 by ikael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_str_array(char **str_array)
{
	int	i;

	i = -1;
	while (str_array[++i])
		free(str_array[i]);
	free(str_array);
}

void	free_fd_array(int **fd, int size)
{
	int	i;

	i = -1;
	while (++i < size)
		free(fd[i]);
	free(fd);
}
