/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjerrica <mjerrica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 18:13:35 by mjerrica          #+#    #+#             */
/*   Updated: 2021/10/12 17:04:38 by mjerrica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	exit_with_arg(unsigned long long int arg)
{
	u_int8_t	exit_status;

	exit_status = arg;
	ft_putendl_fd(EXIT, STDERR_FILENO);
	exit(exit_status);
}

static void	out_err_arg(const char *arg)
{
	ft_putendl_fd(EXIT, STDERR_FILENO);
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	ft_putstr_fd("exit: ", STDERR_FILENO);
	ft_putstr_fd((char *)arg, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putendl_fd(EXIT_ERR_ARG, STDERR_FILENO);
	exit(EXIT_STATUS_ERR_ARG);
}

static void	is_number(const char *arg)
{
	int	i;
	int	max_size;

	i = 0;
	max_size = 19;
	if (arg[i] == '-' || arg[i] == '+')
		i++;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]) || i >= max_size)
			out_err_arg(arg);
		i++;
	}
}

static unsigned long long int	atoi_big(const char *arg)
{
	int						i;
	int						isminus;
	unsigned long long int	result;
	unsigned long long int	max_size;

	i = 0;
	result = 0;
	isminus = 1;
	max_size = 9223372036854775807;
	if (arg[i] == '-' || arg[i] == '+')
	{
		if (arg[i] == '-')
			isminus = -1;
		i++;
	}
	while (arg[i])
	{
		result = (result * 10) + (arg[i] - 48);
		i++;
	}
	if (result > max_size)
		out_err_arg(arg);
	return (result * isminus);
}

void	ft_exit(char **argv, t_list **env_head)
{
	(void)env_head;
	if (get_count_strings(argv) > 2)
	{
		is_number(argv[1]);
		ft_putendl_fd(EXIT, STDERR_FILENO);
		ft_putstr_fd("minishell: ", STDERR_FILENO);
		ft_putstr_fd("exit: ", STDERR_FILENO);
		ft_putendl_fd(EXIT_TOO_MANY_ARG, STDERR_FILENO);
		g_global.g_exit_status = 1;
		return ;
	}
	if (argv[1] != NULL)
	{
		is_number(argv[1]);
		exit_with_arg(atoi_big(argv[1]));
	}
	ft_putendl_fd(EXIT, STDERR_FILENO);
	exit(g_global.g_exit_status);
}
