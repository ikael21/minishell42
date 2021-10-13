/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikael <ikael@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 01:50:52 by ikael             #+#    #+#             */
/*   Updated: 2021/09/30 16:51:02 by ikael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	get_size(t_list *argv_head)
{
	int		i;
	t_token	*token;

	i = 0;
	while (argv_head)
	{
		token = (t_token *)argv_head->content;
		if (token->flag == ARG)
			i++;
		argv_head = argv_head->next;
	}
	return (i);
}

char	**convert_args(t_list *argv_head)
{
	char	**argv;
	int		i;

	argv = (char **)malloc(sizeof(char *) * (get_size(argv_head) + 1));
	if (argv == NULL)
		exit(EXIT_FAILURE);
	i = 0;
	while (argv_head)
	{
		if (((t_token *)argv_head->content)->flag == ARG)
		{
			argv[i] = ft_strdup(((t_token *)argv_head->content)->token);
			if (argv[i] == NULL)
				exit(EXIT_FAILURE);
			i++;
		}
		argv_head = argv_head->next;
	}
	argv[i] = NULL;
	return (argv);
}
