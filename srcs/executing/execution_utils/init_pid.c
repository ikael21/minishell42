/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikael <ikael@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 18:27:06 by ikael             #+#    #+#             */
/*   Updated: 2021/10/09 18:27:23 by ikael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

pid_t	*init_pid(int size)
{
	pid_t	*pid;

	pid = (pid_t *)malloc(sizeof(pid_t) * size);
	if (pid == NULL)
		exit(EXIT_FAILURE);
	return (pid);
}
