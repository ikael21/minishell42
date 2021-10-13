/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikael <ikael@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 11:27:49 by mjerrica          #+#    #+#             */
/*   Updated: 2021/10/12 01:28:37 by ikael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_error(char *arg)
{
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	ft_putstr_fd("unset: `", STDERR_FILENO);
	ft_putstr_fd(arg, STDERR_FILENO);
	ft_putstr_fd("': ", STDERR_FILENO);
	ft_putendl_fd(ERR_UNSET, STDERR_FILENO);
}

static void	get_copy_argv(t_list **env_head, char **env)
{
	t_environ	*item;
	t_list		*new;
	int			i;
	int			j;

	i = -1;
	while (env[++i])
	{
		item = malloc_environ();
		j = 0;
		while (env[i][j] && env[i][j] != '=')
			j++;
		if (env[i][j] == '=')
		{
			print_error(env[i]);
			g_global.g_exit_status = 1;
		}
		item->name = ft_substr(env[i], 0, j);
		item->value = NULL;
		new = ft_lstnew((void *)item);
		ft_lstadd_back(env_head, new);
	}
}

static void	clear_elem(t_list *elem)
{
	free(((t_environ *)elem->content)->name);
	if (((t_environ *)elem->content)->value)
		free(((t_environ *)elem->content)->value);
	free(elem->content);
}

static void	find_and_delete(const char *name, t_list **env)
{
	t_list	*i;
	t_list	*pre;

	i = *env;
	pre = NULL;
	while (i)
	{
		if (ft_strcmp(name, ((t_environ *)i->content)->name) == 0)
		{
			if (!pre)
				(*env)->next = i->next;
			else
				pre->next = i->next;
			clear_elem(i);
			free(i);
			break ;
		}
		pre = i;
		i = i->next;
	}
}

void	ft_unset(char **argv, t_list **env_head)
{
	t_list	*argv_list;
	t_list	*i;

	argv_list = NULL;
	g_global.g_exit_status = 0;
	if (!argv[1])
		return ;
	get_copy_argv(&argv_list, argv + 1);
	i = argv_list;
	while (i)
	{
		if (!check_name(((t_environ *)i->content)->name))
		{
			print_error(((t_environ *)i->content)->name);
			break ;
		}
		find_and_delete(((t_environ *)i->content)->name, env_head);
		i = i->next;
	}
	clear_t_list(argv_list);
}
