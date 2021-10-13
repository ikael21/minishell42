/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_double_quotes.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikael <ikael@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 17:34:15 by ikael             #+#    #+#             */
/*   Updated: 2021/10/06 21:07:00 by ikael            ###   ########.fr       */
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

static char	*fuck_the_norminette(t_shell *shell, int *pos1,
								int pos2, char *tmp)
{
	*pos1 = pos2 - 1;
	if (tmp[*pos1] == '\0')
		tmp = add_token(shell, tmp, pos1);
	return (tmp);
}

char	*parse_double_quotes(char *cmd, int *pos1, t_shell *shell)
{
	char	**three_parts;
	char	*tmp;
	int		pos2;
	int		i;

	pos2 = *pos1 + 1;
	while (cmd[pos2] && cmd[pos2] != '"')
		pos2++;
	three_parts = split_into_three_parts(cmd, *pos1, pos2);
	i = 0;
	while (three_parts[1][i])
	{
		if (three_parts[1][i] == '$')
		{
			tmp = parse_dollar(three_parts[1], &i, shell->env_head);
			free(three_parts[1]);
			three_parts[1] = tmp;
		}
		else
			i++;
	}
	tmp = merge_strings(three_parts[0], three_parts[1], three_parts[2]);
	free(three_parts);
	return (fuck_the_norminette(shell, pos1, pos2, tmp));
}
