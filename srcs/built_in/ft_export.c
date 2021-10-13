/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikael <ikael@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 14:43:54 by mjerrica          #+#    #+#             */
/*   Updated: 2021/10/12 01:35:23 by ikael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	out_env(t_list *env)
{
	t_list	*env_export;

	env_export = env;
	while (env_export)
	{
		if (((t_environ *)env_export->content)->value)
			printf("declare -x %s=\"%s\"\n", \
			((t_environ *)env_export->content)->name, \
			((t_environ *)env_export->content)->value);
		else
			printf("declare -x %s=\"\"\n", \
			((t_environ *)env_export->content)->name);
		env_export = env_export->next;
	}
	clear_t_list(env);
}

static int	search_start_value(const char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '=')
		i++;
	return (i);
}

static char	*get_value(const char *argv, int j)
{
	if (argv[j] == '=')
		return (ft_substr(argv, j + 1, ft_strlen(argv) - j - 1));
	else
		return (NULL);
}

static t_list	*convert_argv(char **argv)
{
	int		i;
	int		j;
	t_list	*tmp;
	t_list	*argv_list;

	i = 0;
	argv_list = NULL;
	while (argv[i])
	{
		tmp = ft_lstnew(NULL);
		tmp->content = malloc_environ();
		j = search_start_value(argv[i]);
		((t_environ *)tmp->content)->name = ft_substr(argv[i], 0, j);
		((t_environ *)tmp->content)->value = get_value(argv[i], j);
		if (!argv_list)
			argv_list = tmp;
		else
			ft_lstadd_back(&argv_list, tmp);
		i++;
	}
	return (argv_list);
}

void	ft_export(char **argv, t_list **env_head)
{
	t_list	*argv_list;

	g_global.g_exit_status = 0;
	if (!argv[1])
		out_env(sort_env(*env_head));
	else
	{
		argv_list = convert_argv(argv + 1);
		add_change_env(argv_list, env_head);
		clear_t_list(argv_list);
	}
}
