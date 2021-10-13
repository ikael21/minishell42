/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_t_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjerrica <mjerrica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 11:37:59 by mjerrica          #+#    #+#             */
/*   Updated: 2021/10/06 12:05:04 by mjerrica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	clear_t_list(t_list *list)
{
	t_list	*i;

	while (list)
	{
		i = list;
		list = list->next;
		free(((t_environ *)i->content)->name);
		free(((t_environ *)i->content)->value);
		free(i->content);
		free(i);
	}
}
