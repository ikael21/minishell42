/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_occured.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikael <ikael@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 20:21:51 by ikael             #+#    #+#             */
/*   Updated: 2021/10/10 15:11:40 by ikael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	error_occured(const char *the_reason, char *error_message)
{
	if (error_message == NULL)
		error_message = strerror(errno);
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	ft_putstr_fd((char *)the_reason, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putendl_fd((char *)error_message, STDERR_FILENO);
}
