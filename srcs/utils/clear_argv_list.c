/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_argv_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikael <ikael@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 00:02:49 by ikael             #+#    #+#             */
/*   Updated: 2021/10/02 11:00:06 by ikael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_lstclear_super(t_list **argv_head)
{
	t_list	*tokens;
	t_list	*temp;
	t_list	*next;

	temp = *argv_head;
	while (temp)
	{
		next = temp->next;
		tokens = (t_list *)temp->content;
		while (tokens)
		{
			free(((t_token *)tokens->content)->token);
			tokens = tokens->next;
		}
		tokens = (t_list *)temp->content;
		ft_lstclear(&tokens, free);
		free(temp);
		temp = next;
	}
	*argv_head = NULL;
}
