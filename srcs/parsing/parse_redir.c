/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikael <ikael@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 01:02:12 by ikael             #+#    #+#             */
/*   Updated: 2021/10/05 17:01:41 by ikael            ###   ########.fr       */
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

static void	set_next_flag(char *str, int8_t *flag)
{
	char	*temp;
	char	sym;
	int		end;

	end = ft_strlen(str) - 1;
	sym = str[end];
	while (str[end] && str[end] == sym)
		end--;
	temp = ft_substr(str, end + 1, ft_strlen(str) - end - 1);
	if (temp == NULL)
		exit(EXIT_FAILURE);
	if (ft_strcmp(temp, ">") == 0)
		*flag = WRITE_FILE;
	else if (ft_strcmp(temp, "<") == 0)
		*flag = READ_FILE;
	else if (ft_strcmp(temp, "<<") == 0)
		*flag = DELIMITER;
	else
		*flag = WRITE_APPEND_FILE;
	free(temp);
}

char	*parse_redir(char *cmd, int *pos1, t_shell *shell)
{
	char	*temp;
	int		i;

	if (*pos1 > 0 && cmd[*pos1 - 1] != ' ')
		add_token(cmd, *pos1, shell);
	i = *pos1 + 1;
	while (cmd[i] == cmd[*pos1])
		i++;
	temp = ft_substr(cmd, 0, i);
	set_next_flag(temp, &shell->next_token_flag);
	free(temp);
	while (cmd[i] && ((cmd[i] >= 9
				&& cmd[i] <= 13) || cmd[i] == ' '))
		i++;
	temp = ft_substr(cmd, i, ft_strlen(cmd) - i);
	if (temp == NULL)
		exit(EXIT_FAILURE);
	*pos1 = 0;
	return (temp);
}
