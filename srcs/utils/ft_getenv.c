/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikael <ikael@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 04:07:25 by ikael             #+#    #+#             */
/*   Updated: 2021/09/21 04:13:28 by ikael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

const char	*ft_getenv(t_list *env_head, char *name)
{
	t_environ	*environ;

	while (env_head)
	{
		environ = (t_environ *)env_head->content;
		if (ft_strcmp(environ->name, name) == 0)
			return ((const char *)environ->value);
		env_head = env_head->next;
	}
	return (NULL);
}
