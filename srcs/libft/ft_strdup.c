/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikael <ikael@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 19:33:22 by ikael             #+#    #+#             */
/*   Updated: 2021/04/24 21:27:14 by ikael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strcpy(char *dst, const char *src)
{
	int			i;
	char		*destination;
	const char	*source;

	i = 0;
	destination = (char *)dst;
	source = (char *)src;
	while (source[i] != '\0')
	{
		destination[i] = source[i];
		i++;
	}
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
