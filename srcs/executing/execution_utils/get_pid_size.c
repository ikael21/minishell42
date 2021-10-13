/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pid_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikael <ikael@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 14:31:15 by ikael             #+#    #+#             */
/*   Updated: 2021/10/09 14:31:39 by ikael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_pid_size(t_shell *shell)
{
	int		size;
	t_list	*temp;
	t_token	*token;
	t_list	*args;

	size = 0;
	temp = shell->argv_head;
	while (temp)
	{
		args = (t_list *)temp->content;
		token = (t_token *)args->content;
		while (token->flag != ARG)
		{
			args = args->next;
			if (args == NULL)
				break ;
			token = (t_token *)args->content;
		}
		if (is_built_in(token->token, shell->built_in) == NULL)
			size++;
		temp = temp->next;
	}
	return (size);
}
