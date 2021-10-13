/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_change_env.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikael <ikael@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 15:34:04 by mjerrica          #+#    #+#             */
/*   Updated: 2021/10/11 21:44:58 by ikael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_error(char *arg)
{
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	ft_putstr_fd("export: `", STDERR_FILENO);
	ft_putstr_fd(arg, STDERR_FILENO);
	ft_putstr_fd("': ", STDERR_FILENO);
	ft_putendl_fd(ERR_UNSET, STDERR_FILENO);
	g_global.g_exit_status = 1;
}

static t_list	*find_var(const char *name, t_list *env)
{
	t_list	*i;

	i = env;
	while (i)
	{
		if (ft_strcmp(name, ((t_environ *)i->content)->name) == 0)
			return (i);
		i = i->next;
	}
	return (NULL);
}

static void	copy_elem(t_list *tmp, t_list *argv_list)
{
	tmp->content = malloc_environ();
	((t_environ *)tmp->content)->name = \
	ft_strdup(((t_environ *)argv_list->content)->name);
	if (((t_environ *)argv_list->content)->value)
		((t_environ *)tmp->content)->value = \
		ft_strdup(((t_environ *)argv_list->content)->value);
	else
		((t_environ *)tmp->content)->value = NULL;
}

static void	copy_value(t_list *tmp, t_list *argv_list)
{
	if (((t_environ *)argv_list->content)->value)
	{
		if (((t_environ *)tmp->content)->value)
			free(((t_environ *)tmp->content)->value);
		((t_environ *)tmp->content)->value = \
		ft_strdup(((t_environ *)argv_list->content)->value);
	}
}

void	add_change_env(t_list *argv_list, t_list **env_head)
{
	t_list	*tmp;

	while (argv_list)
	{
		if (check_name(((t_environ *)argv_list->content)->name))
		{
			tmp = find_var(((t_environ *)argv_list->content)->name, *env_head);
			if (tmp)
				copy_value(tmp, argv_list);
			else
			{
				tmp = ft_lstnew(NULL);
				copy_elem(tmp, argv_list);
				ft_lstadd_back(env_head, tmp);
			}
			argv_list = argv_list->next;
		}
		else
		{
			print_error(((t_environ *)argv_list->content)->name);
			break ;
		}
	}
}
