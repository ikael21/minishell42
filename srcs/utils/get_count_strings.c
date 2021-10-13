/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_count_strings.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjerrica <mjerrica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 13:49:27 by mjerrica          #+#    #+#             */
/*   Updated: 2021/10/06 12:04:15 by mjerrica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_count_strings(char **strings)
{
	int	count;

	count = 0;
	while (strings[count])
		count++;
	return (count);
}
