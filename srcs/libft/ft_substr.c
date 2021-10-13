/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikael <ikael@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 13:37:14 by ikael             #+#    #+#             */
/*   Updated: 2021/04/25 19:43:12 by ikael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*pointer;
	size_t	i;

	if (start >= ft_strlen(s))
	{
		pointer = (char *)malloc(sizeof(char));
		pointer[0] = '\0';
		return (pointer);
	}
	if (len + start >= ft_strlen(s))
		len = ft_strlen(s) - start;
	pointer = (char *)malloc(sizeof(char) * (len + 1));
	if (pointer == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		pointer[i] = s[start + i];
		i++;
	}
	pointer[i] = '\0';
	return (pointer);
}
