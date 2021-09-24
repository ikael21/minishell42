/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikael <ikael@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 17:34:15 by ikael             #+#    #+#             */
/*   Updated: 2021/09/23 07:34:45 by ikael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	save_cmd_or_arg(char *cmd,
							int pos,
							t_list **tokens_head,
							int8_t nxt_flag)
{
	t_token	*token;
	t_list	*new;
	char	*temp;

	token = (t_token *)malloc(sizeof(t_token));
	temp = ft_substr(cmd, 0, pos);
	if (temp == NULL || token == NULL)
		exit(EXIT_FAILURE);
	token->token = temp;
	token->flag = nxt_flag;
	new = ft_lstnew(token);
	if (new == NULL)
		exit(EXIT_FAILURE);
	ft_lstadd_back(tokens_head, new);
}

char	*save_token(char *cmd, int *pos1, t_shell *shell)
{
	t_list	*tokens_head;
	char	*temp;
	int		i;

	tokens_head = (t_list *)(ft_lstlast(shell->argv_head))->content;
	save_cmd_or_arg(cmd, *pos1, &tokens_head, shell->next_token_flag);
	ft_lstlast(shell->argv_head)->content = tokens_head;
	i = *pos1 + 1;
	while (cmd[i] && ((cmd[i] >= 9
				&& cmd[i] <= 13) || cmd[i] == ' '))
		i++;
	temp = ft_substr(cmd, i, ft_strlen(cmd) - i);
	if (temp == NULL)
		exit(EXIT_FAILURE);
	*pos1 = 0;
	if (shell->next_token_flag != ARG)
		shell->next_token_flag = ARG;
	return (temp);
}
