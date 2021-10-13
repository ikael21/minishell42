/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_built_in.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikael <ikael@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 23:03:11 by ikael             #+#    #+#             */
/*   Updated: 2021/10/12 23:03:27 by ikael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_built_in(t_shell *shell)
{
	shell->built_in[0].name = "echo";
	shell->built_in[0].func_ptr = ft_echo;
	shell->built_in[1].name = "env";
	shell->built_in[1].func_ptr = ft_env;
	shell->built_in[2].name = "export";
	shell->built_in[2].func_ptr = ft_export;
	shell->built_in[3].name = "pwd";
	shell->built_in[3].func_ptr = ft_pwd;
	shell->built_in[4].name = "cd";
	shell->built_in[4].func_ptr = ft_cd;
	shell->built_in[5].name = "unset";
	shell->built_in[5].func_ptr = ft_unset;
	shell->built_in[6].name = "exit";
	shell->built_in[6].func_ptr = ft_exit;
}
