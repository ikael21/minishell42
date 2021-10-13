/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikael <ikael@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 13:04:21 by ikael             #+#    #+#             */
/*   Updated: 2021/10/13 18:55:39 by ikael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	open_to_rd(t_shell *shell, char *file_name)
{
	close(shell->read_fd);
	shell->read_fd = open(file_name, O_RDONLY);
	if (shell->read_fd == -1)
		return (1);
	shell->is_current_input = READ_FILE;
	return (0);
}

static int	open_to_wr(t_shell *shell, char *file_name, int8_t flag)
{
	close(shell->write_fd);
	if (flag == WRITE_FILE)
		shell->write_fd = open(file_name, O_WRONLY | O_CREAT | O_TRUNC,
				S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (flag == WRITE_APPEND_FILE)
		shell->write_fd = open(file_name, O_WRONLY | O_CREAT | O_APPEND,
				S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (shell->write_fd == -1)
		return (1);
	return (0);
}

static int	get_strings_before_delimiter(t_shell *shell, char *str)
{
	char	*tmp1;
	char	*tmp2;

	tmp1 = ft_strjoin(str, "\n");
	free(str);
	if (tmp1 == NULL)
		return (1);
	if (shell->rd_buffer == NULL)
		shell->rd_buffer = tmp1;
	else
	{
		tmp2 = ft_strjoin(shell->rd_buffer, tmp1);
		free(tmp1);
		if (tmp2 == NULL)
			return (1);
		free(shell->rd_buffer);
		shell->rd_buffer = tmp2;
	}
	return (0);
}

static int	delimiter(t_shell *shell, char *delimiter)
{
	char	*str;
	int		ret;

	if (shell->rd_buffer)
		free(shell->rd_buffer);
	shell->rd_buffer = NULL;
	str = readline("> ");
	if (g_global.g_ctrl_c == 1 || str == NULL)
		return (handle_signals(shell, str));
	while (ft_strcmp(str, delimiter))
	{
		ret = get_strings_before_delimiter(shell, str);
		if (ret)
			return (ret);
		str = readline("> ");
		if (g_global.g_ctrl_c == 1 || str == NULL)
			return (handle_signals(shell, str));
	}
	free(str);
	shell->is_current_input = DELIMITER;
	return (0);
}

int	open_files(t_shell *shell, t_list *args_head)
{
	t_token	*token;
	int		ret;

	while (args_head)
	{
		token = (t_token *)args_head->content;
		if (token->flag != ARG)
		{
			if (token->flag == READ_FILE)
				ret = open_to_rd(shell, token->token);
			if (token->flag == WRITE_FILE)
				ret = open_to_wr(shell, token->token, WRITE_FILE);
			if (token->flag == WRITE_APPEND_FILE)
				ret = open_to_wr(shell, token->token, WRITE_APPEND_FILE);
			if (token->flag == DELIMITER)
				ret = delimiter(shell, token->token);
			if (ret == 1)
				error_occured(token->token, NULL);
			if (ret)
				return (ret);
		}
		args_head = args_head->next;
	}
	return (0);
}
