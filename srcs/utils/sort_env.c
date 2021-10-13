/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjerrica <mjerrica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 15:25:04 by mjerrica          #+#    #+#             */
/*   Updated: 2021/10/10 17:10:19 by mjerrica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	copy_t_list(t_list *dest, t_list *src)
{
	t_list	*i;

	i = dest;
	while (src)
	{
		if (src->next)
			i->next = ft_lstnew(NULL);
		i->content = malloc_environ();
		((t_environ *)i->content)->name = \
		ft_strdup(((t_environ *)src->content)->name);
		if (((t_environ *)src->content)->value)
			((t_environ *)i->content)->value = \
			ft_strdup(((t_environ *)src->content)->value);
		else
			((t_environ *)i->content)->value = NULL;
		i = i->next;
		src = src->next;
	}
}

static void	find_and_cut_less(t_list **copyEnv, t_list **less)
{
	t_list	*i;
	t_list	*pre;
	t_list	*pre_less;

	i = *copyEnv;
	*less = *copyEnv;
	pre_less = NULL;
	while (i)
	{
		if (ft_strcmp(((t_environ *)(*less)->content)->name, \
		((t_environ *)i->content)->name) > 0)
		{
			*less = i;
			pre_less = pre;
		}
		pre = i;
		i = i->next;
	}
	if (!pre_less)
		*copyEnv = (*less)->next;
	else
		pre_less->next = (*less)->next;
	(*less)->next = NULL;
}

t_list	*sort_env(t_list *env_head)
{
	t_list	*sort_list;
	t_list	*copy_env;
	t_list	*less;

	sort_list = NULL;
	copy_env = ft_lstnew(NULL);
	copy_t_list(copy_env, env_head);
	while (copy_env && env_head)
	{
		find_and_cut_less(&copy_env, &less);
		if (!sort_list)
			sort_list = less;
		else
			ft_lstadd_back(&sort_list, less);
	}
	return (sort_list);
}
