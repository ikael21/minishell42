/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikael <ikael@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 12:55:00 by mjerrica          #+#    #+#             */
/*   Updated: 2021/10/11 21:40:12 by ikael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_env(char **argv, t_list **env_head)
{
	t_list	*i;

	(void)argv;
	i = *env_head;
	while (i)
	{
		if (((t_environ *)i->content)->value)
			printf("%s=%s\n", ((t_environ *)i->content)->name, \
			((t_environ *)i->content)->value);
		i = i->next;
	}
	g_global.g_exit_status = 0;
}
