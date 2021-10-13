/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_built_in.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikael <ikael@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 14:40:08 by ikael             #+#    #+#             */
/*   Updated: 2021/10/05 14:40:12 by ikael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_function_ptr	is_built_in(char *cmd, t_built_in *built_in)
{
	int	i;

	i = -1;
	while (++i < BUILTIN_FUNC_NUM)
		if (ft_strcmp(cmd, built_in[i].name) == 0)
			return (built_in[i].func_ptr);
	return (NULL);
}
