/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_single_quotes.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikael <ikael@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 17:34:15 by ikael             #+#    #+#             */
/*   Updated: 2021/10/06 12:57:35 by ikael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*add_token(t_shell *shell, char *cmd, int *pos)
{
	t_list	*args_head;
	t_token	*token;
	t_list	*new;
	char	*tmp;

	args_head = (t_list *)ft_lstlast(shell->argv_head)->content;
	token = (t_token *)malloc(sizeof(t_token));
	tmp = ft_strdup("");
	if (token == NULL || tmp == NULL)
		exit(EXIT_FAILURE);
	token->token = cmd;
	token->flag = shell->next_token_flag;
	if (shell->next_token_flag != ARG)
		shell->next_token_flag = ARG;
	new = ft_lstnew(token);
	if (new == NULL)
		exit(EXIT_FAILURE);
	ft_lstadd_back(&args_head, new);
	ft_lstlast(shell->argv_head)->content = args_head;
	*pos = 0;
	return (tmp);
}

char	*parse_single_quotes(char *cmd, int *pos1, t_shell *shell)
{
	char	**three_parts;
	int		pos2;
	char	*tmp;

	pos2 = *pos1 + 1;
	while (cmd[pos2] && cmd[pos2] != '\'')
		pos2++;
	three_parts = split_into_three_parts(cmd, *pos1, pos2);
	tmp = merge_strings(three_parts[0],
			three_parts[1], three_parts[2]);
	free(three_parts);
	*pos1 = pos2 - 1;
	if (tmp[*pos1] == '\0')
		tmp = add_token(shell, tmp, pos1);
	return (tmp);
}
