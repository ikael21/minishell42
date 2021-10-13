/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikael <ikael@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 17:14:36 by mjerrica          #+#    #+#             */
/*   Updated: 2021/10/12 01:28:25 by ikael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_list	*get_oldpwd(t_list *env_head)
{
	while (env_head)
	{
		if (ft_strcmp(((t_environ *)env_head->content)->name, "OLDPWD") == 0)
			return (env_head);
		env_head = env_head->next;
	}
	return (NULL);
}

static void	change_oldpwd(t_list *env_head)
{
	t_list	*oldpwd;
	char	directory[MAXDIR];

	if (!getcwd(directory, MAXDIR))
		return ;
	oldpwd = get_oldpwd(env_head);
	if (oldpwd)
	{
		free(((t_environ *)oldpwd->content)->value);
		((t_environ *)oldpwd->content)->value = ft_strdup(directory);
	}
}

static void	go_back(t_list *env_head)
{
	char	*copy_oldpwd;
	t_list	*oldpwd;

	oldpwd = get_oldpwd(env_head);
	if (!oldpwd)
	{
		error_occured("cd", "OLDPWD not set");
		return ;
	}
	copy_oldpwd = ft_strdup(((t_environ *)oldpwd->content)->value);
	change_oldpwd(env_head);
	if (chdir(copy_oldpwd) == -1)
	{
		ft_putstr_fd("minishell: ", STDERR_FILENO);
		ft_putstr_fd("cd: ", STDERR_FILENO);
		perror(copy_oldpwd);
		g_global.g_exit_status = 1;
	}
	free(copy_oldpwd);
}

static void	go_home(const char *home, t_list *env_head)
{
	if (!home)
	{
		error_occured("cd", "HOME not set");
		g_global.g_exit_status = 1;
		return ;
	}
	change_oldpwd(env_head);
	if (chdir(home) == -1)
	{
		ft_putstr_fd("minishell: ", STDERR_FILENO);
		ft_putstr_fd("cd: ", STDERR_FILENO);
		perror(home);
		g_global.g_exit_status = 1;
	}
}

void	ft_cd(char **argv, t_list **env_head)
{
	g_global.g_exit_status = 0;
	if (!argv[1] || !ft_strcmp(argv[1], "~") || !ft_strcmp(argv[1], "--"))
		go_home(ft_getenv(*env_head, "HOME"), *env_head);
	else
	{
		if (!ft_strcmp(argv[1], "-"))
			go_back(*env_head);
		else
		{
			change_oldpwd(*env_head);
			if (chdir(argv[1]) == -1)
			{
				ft_putstr_fd("minishell: ", STDERR_FILENO);
				ft_putstr_fd("cd: ", STDERR_FILENO);
				perror(argv[1]);
				g_global.g_exit_status = 1;
			}
		}
	}
	change_pwd(*env_head);
}
