/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikael <ikael@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 15:07:08 by ikael             #+#    #+#             */
/*   Updated: 2021/04/24 20:41:16 by ikael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	len_needle;

	i = 0;
	len_needle = ft_strlen(needle);
	if (*needle == '\0')
		return ((char *)haystack);
	while (i < len && haystack[i] != '\0')
	{
		if (haystack[i] == *needle)
		{
			if (len < ft_strlen(needle))
				return (NULL);
			if (ft_memcmp(&haystack[i], needle, len_needle) == 0)
			{
				if (i + len_needle <= len)
					return ((char *)haystack + i);
			}
		}
		i++;
	}
	return (NULL);
}
