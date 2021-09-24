/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikael <ikael@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 00:55:43 by ikael             #+#    #+#             */
/*   Updated: 2021/09/23 20:53:54 by ikael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	add_token(char *cmd, int pos, t_shell *shell)
{
	t_list	*tmp;
	t_token	*token;
	t_list	*new;
	char	*temp;

	token = (t_token *)malloc(sizeof(t_token));
	temp = ft_substr(cmd, 0, pos);
	if (temp == NULL || token == NULL)
		exit(EXIT_FAILURE);
	token->token = temp;
	token->flag = shell->next_token_flag;
	new = ft_lstnew(token);
	if (new == NULL)
		exit(EXIT_FAILURE);
	tmp = ft_lstlast(shell->argv_head);
	tmp = (t_list *)tmp->content;
	ft_lstadd_back(&tmp, new);
	new = ft_lstlast(shell->argv_head);
	new->content = tmp;
}

char	*parse_pipe(char *cmd, int *pos1, t_shell *shell)
{
	t_list	*new;
	char	*temp;
	int		pos2;

	if (*pos1 > 0 && cmd[*pos1 - 1] != ' ')
		add_token(cmd, *pos1, shell);
	new = ft_lstnew(NULL);
	if (new == NULL)
		exit(EXIT_FAILURE);
	ft_lstadd_back(&shell->argv_head, new);
	pos2 = *pos1 + 1;
	while (cmd[pos2] && ((cmd[pos2] >= 9
				&& cmd[pos2] <= 13) || cmd[pos2] == ' '))
		pos2++;
	temp = ft_substr(cmd, pos2, ft_strlen(cmd) - pos2);
	if (temp == NULL)
		exit(EXIT_FAILURE);
	*pos1 = 0;
	return (temp);
}
