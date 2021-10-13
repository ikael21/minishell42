/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_name.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikael <ikael@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 16:03:21 by mjerrica          #+#    #+#             */
/*   Updated: 2021/10/11 21:45:08 by ikael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_name(const char *name)
{
	int	i;

	i = 1;
	if (!((name[0] >= 'A' && name[0] <= 'Z') || \
	(name[0] >= 'a' && name[0] <= 'z') || name[0] == '_'))
	{
		g_global.g_exit_status = 1;
		return (0);
	}
	while (name[i])
	{
		if (!((name[i] >= 'A' && name[i] <= 'Z') || name[i] == '_' || \
		(name[i] >= 'a' && name[i] <= 'z') || \
		(name[i] >= '0' && name[i] <= '9')))
		{
			g_global.g_exit_status = 1;
			return (0);
		}
		i++;
	}
	return (1);
}
