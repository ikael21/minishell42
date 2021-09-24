/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikael <ikael@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 15:42:15 by ikael             #+#    #+#             */
/*   Updated: 2021/09/19 15:42:35 by ikael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static char	*ft_strcpy(char *dst, const char *src)
{
	int			i;
	char		*destination;
	const char	*source;

	i = -1;
	destination = (char *)dst;
	source = (char *)src;
	while (source[++i])
		destination[i] = source[i];
	destination[i] = '\0';
	return (dst);
}

char	*ft_strdup(const char *s)
{
	char	*dest;

	dest = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (dest == NULL)
		return (NULL);
	return (ft_strcpy(dest, s));
}
