/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pipes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikael <ikael@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 14:42:34 by ikael             #+#    #+#             */
/*   Updated: 2021/10/06 18:28:22 by ikael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	init_pipes(t_shell *shell)
{
	int	i;
	int	size;

	size = ft_lstsize(shell->argv_head);
	shell->fd = (int **)malloc(sizeof(int *) * size);
	if (shell->fd == NULL)
		exit(EXIT_FAILURE);
	shell->fd[size - 1] = NULL;
	i = -1;
	while (++i < size - 1)
	{
		shell->fd[i] = (int *)malloc(sizeof(int) * 2);
		if (shell->fd[i] == NULL)
			exit(EXIT_FAILURE);
		if (pipe(shell->fd[i]) == -1)
			return (i);
	}
	return (0);
}
