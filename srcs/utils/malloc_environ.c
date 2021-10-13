/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_environ.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikael <ikael@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 13:39:21 by mjerrica          #+#    #+#             */
/*   Updated: 2021/10/11 21:46:07 by ikael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_environ	*malloc_environ(void)
{
	t_environ	*tmp;

	tmp = (t_environ *)malloc(sizeof(t_environ));
	if (tmp)
		return (tmp);
	g_global.g_exit_status = 1;
	exit(1);
}
