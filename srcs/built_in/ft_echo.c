/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjerrica <mjerrica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 14:14:12 by mjerrica          #+#    #+#             */
/*   Updated: 2021/10/13 18:00:09 by mjerrica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_out_strings(char **strings)
{
	while (*strings != NULL)
	{
		printf("%s", *strings);
		strings++;
		if (*strings != NULL)
			printf(" ");
	}
}

void	ft_echo(char **argv, t_list **env_head)
{
	int	i;

	(void)env_head;
	i = 1;
	if (argv[1] && !(ft_strcmp(argv[1], "-n")))
	{
		while (argv[i] && !(ft_strcmp(argv[i], "-n")))
			i++;
		if (argv[i])
			ft_out_strings(&argv[i]);
	}
	else
	{
		if (argv[i])
			ft_out_strings(&argv[1]);
		printf("\n");
	}
	g_global.g_exit_status = 0;
}
