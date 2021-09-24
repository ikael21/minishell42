/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikael <ikael@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 01:50:52 by ikael             #+#    #+#             */
/*   Updated: 2021/09/22 22:48:59 by ikael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**convert_args(t_list *argv_head)
{
	char	**argv;
	int		i;

	argv = (char **)malloc(sizeof(char *) * (ft_lstsize(argv_head) + 1));
	if (argv == NULL)
		exit(EXIT_FAILURE);
	i = 0;
	while (argv_head)
	{
		argv[i] = ft_strdup(((t_token *)argv_head->content)->token);
		if (argv[i] == NULL)
			exit(EXIT_FAILURE);
		argv_head = argv_head->next;
		i++;
	}
	argv[i] = NULL;
	return (argv);
}
